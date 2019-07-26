#include "FDMethod.h"

FDMethod::FDMethod(PDE* PDE_to_solve, int i_max, int j_max) : m_PDE(PDE_to_solve), m_iMax(i_max), m_jMax(j_max)
{
	m_deltaX = (m_PDE->m_xUpper - m_PDE->m_xLower) / m_jMax;
	m_deltaT = (m_PDE->m_T / m_iMax);
	V.resize(m_iMax+1);
	for (int i = 0; i <= m_iMax; i++)
		V[i].resize(m_jMax + 1);
}

double FDMethod::t(double i)
{
	return i*m_deltaT;
}

double FDMethod::x(double j)
{
	return m_PDE->m_xLower + j*m_deltaX;
}


double FDMethod::a(double i, int j)
{
	return m_PDE->a(t(i), x(j));
}

double FDMethod::b(double i, int j)
{
	return m_PDE->b(t(i), x(j));
}

double FDMethod::c(double i, int j)
{
	return m_PDE->c(t(i), x(j));
}

double FDMethod::d(double i, int j)
{
	return m_PDE->d(t(i), x(j));
}

double FDMethod::e(double i, int j)
{
	return m_PDE->e(t(i), x(j));
}

double FDMethod::f(int j)
{
	return m_PDE->f(x(j));
}

double FDMethod::f_Lower(double i)
{
	return m_PDE->f_Lower(t(i));
}

double FDMethod::f_Upper(double i)
{
	return m_PDE->f_Upper(t(i));
}

double FDMethod::v(double _t, double _x)
{
	int i = floor(_t / m_deltaT);
	int j = floor((_x - m_PDE->m_xLower) / m_deltaX);
	double lambda1 = (_t - t(i)) / m_deltaT;
	double lambda0 = 1.0 - lambda1;
	double theta1 = (_x - x(j)) / m_deltaX;
	double theta0 = 1-theta1;
	return lambda1*theta1*V[i + 1][j + 1] + lambda1*theta0*V[i + 1][j]
		+ lambda0*theta1*V[i][j + 1] + lambda0*theta0*V[i][j];
}

