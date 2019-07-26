#include "ImplicitMethods.h"
#include <iostream>

ImplicitMethods::ImplicitMethods(PDE* PDE_to_solve, int i_max, int j_max) : FDMethod(PDE_to_solve,i_max,j_max)
{

}

Vector ImplicitMethods::w(int i)
{
	Vector w(m_jMax + 1);
	w[1] = D(i, 1) + A(i, 1)*f_Lower(i) - E(i,1)*f_Lower(i - 1);
	for (int j = 2; j <= m_jMax - 2; j++)
	{
		w[j] = D(i, j);
	}
	w[m_jMax - 1] = D(i, m_jMax - 1) + C(i, m_jMax - 1)*f_Upper(i) + G(i, m_jMax - 1)*f_Upper(i - 1);
	return w;
}

Vector ImplicitMethods::Av(int i, Vector input_vector)
{
	Vector returnVector(m_jMax + 1);
	returnVector[1] = B(i, 1)*input_vector[1] + C(i, 1)*input_vector[2];
	for (int j = 2;j <= m_jMax - 2;j++)
	{
		returnVector[j] = A(i, j)*input_vector[j - 1] + B(i, j)*input_vector[j] + C(i, j)*input_vector[j + 1];
	}
	returnVector[m_jMax - 1] = A(i, m_jMax - 1)*input_vector[m_jMax - 2] + B(i, m_jMax - 1)*input_vector[m_jMax - 1];
	return returnVector;
}

Vector ImplicitMethods::LUDecomposition(int i, Vector input_vector)
{
	Vector output_vector(m_jMax + 1);
	Vector r(m_jMax+1);
	Vector y(m_jMax + 1);

	r[1] = F(i, 1);
	y[1] = input_vector[1];

	for (int j = 2; j <= m_jMax - 1;j++)
	{
		r[j] = F(i, j) - E(i, j)*G(i, j - 1) / r[j - 1];
		y[j] = output_vector[j] - E(i, j)*y[j - 1] / r[j - 1];
	}
	output_vector[m_jMax - 1] = y[m_jMax - 1] / r[m_jMax - 1];

	for (int j = m_jMax - 2;j > 0;j--)
	{
		output_vector[j] = (y[j] - G(i, j)*output_vector[j + 1]) / r[j];
	}
	return output_vector;
}

void ImplicitMethods::solveByLUDecomposition()
{
	for (int j = 0; j <= m_jMax;j++)
		V[m_iMax][j] = f(j);

	for (int i = m_iMax; i > 0;i--)
	{
		V[i - 1] = LUDecomposition(i, Av(i,V[i])+w(i));
		V[i - 1][0] = f_Lower(i - 1);
		V[i - 1][m_jMax] = f_Upper(i - 1);
	}
}