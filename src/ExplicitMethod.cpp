#include "ExplicitMethod.h"

ExplicitMethod::ExplicitMethod(PDE* PDE_to_solve, int i_Max, int j_Max) : FDMethod(PDE_to_solve, i_Max, j_Max)
{
	// Initialises FDMethod object
}

double ExplicitMethod::A(int i, int j)
{
	return (m_deltaT / m_deltaX)*(a(i, j) / m_deltaX - b(i, j) / 2.0);
}

double ExplicitMethod::B(int i, int j)
{
	return 1 - m_deltaT*c(i, j) - (2 * a(i, j)*m_deltaT) / pow(m_deltaX, 2);
}

double ExplicitMethod::C(int i, int j)
{
	return (m_deltaT / m_deltaX)*(a(i, j) / m_deltaX + b(i, j) / 2.0);
}

double ExplicitMethod::D(int i, int j)
{
	return m_deltaT*d(i, j);
}

void ExplicitMethod::solve()
{
	for (int j = 0; j <= m_jMax; j++)
		V[m_iMax][j] = f(j); // Populate terminal boundary (right side of mesh)

	for (int i = m_iMax; i > 0; --i)
	{
		V[i - 1][0] = f_Lower(i - 1);
		V[i - 1][m_jMax] = f_Upper(i - 1);
		for (int j = 1; j < m_jMax; j++)
		{
			V[i - 1][j] = A(i, j)*V[i][j - 1] + B(i, j)*V[i][j] + C(i, j)*V[i][j + 1];
		}
	}
}