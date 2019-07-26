#include "CNMethod.h"

CNMethod::CNMethod(PDE* PDE_to_solve, int i_max, int j_max) : ImplicitMethods(PDE_to_solve, i_max, j_max)
{

}

double CNMethod::A(int i, int j)
{
	return 0.5*m_deltaT / m_deltaX * (a(i - 0.5, j) / m_deltaX - b(i - 0.5, j) / 2.0);
}

double CNMethod::B(int i, int j)
{
	return 1.0 + 0.5 * m_deltaT * (-2.0 * a(i - 0.5, j) / pow(m_deltaX, 2) + c(i - 0.5, j));
}

double CNMethod::C(int i, int j)
{
	return (m_deltaT / (2 * m_deltaX)) *(b(i - 0.5, j) / 2.0 + a(i - 0.5, j) / m_deltaX);
}

double CNMethod::D(int i, int j)
{
	return m_deltaT*d(i - 0.5, j);
}

double CNMethod::E(int i, int j)
{
	return -A(i, j);
}

double CNMethod::F(int i, int j)
{
	return 2.0 - B(i, j);
}

double CNMethod::G(int i, int j)
{
	return -C(i, j);
}