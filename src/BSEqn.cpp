#include "BSEqn.h"
#include <cmath>

BSEqn::BSEqn(BSModel* BSParameters, Option* BSOption) : PDE(BSOption->m_T, BSOption->m_lower_sT, BSOption->m_upper_sT),
	m_BSParameters(BSParameters), m_BSOption(BSOption)
{
	// Initialises PDE and stores BS paramater and Option
}

// Set co-efficients


double BSEqn::a(double t, double S)
{
	return 0.5*pow(m_BSParameters->m_sigma, 2.0)*pow(S, 2.0);
}

double BSEqn::b(double t, double S)
{
	return m_BSParameters->m_r*S;
}

double BSEqn::c(double t, double S)
{
	return -m_BSParameters->m_r;
}

double BSEqn::d(double t, double S)
{
	return 0.0;
}

double BSEqn::e(double t, double S)
{
	return 0.0;
}

double BSEqn::f(double S)
{
	return m_BSOption->payoff(S);
}

double BSEqn::f_Lower(double t)
{
	return m_BSOption->lowerBdCond(m_BSParameters,t);
}

double BSEqn::f_Upper(double t)
{
	return m_BSOption->upperBdCond(m_BSParameters, t);
}