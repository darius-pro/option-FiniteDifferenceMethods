#include "Put.h"
#include <cmath>

// EurPut Constructor

EurPut::EurPut(double strike, double T, double lower_sT, double upper_sT) : Option(T, lower_sT, upper_sT), m_strike(strike)
{
	// Initialises Option, stores strike
}

double EurPut::payoff(double sT)
{
	if (m_strike > sT)
		return m_strike - sT;
	else
		return 0;
}

double EurPut::upperBdCond(BSModel* BSParameters, double t)
{
	// When sT is very high, option is worthless
	return 0;
}

double EurPut::lowerBdCond(BSModel* BSParameters, double t)
{
	// When sT is very low option will expire with value near to strike
	// Return discounted strike
	return exp(BSParameters->m_r*(m_T - t))*m_strike;
}