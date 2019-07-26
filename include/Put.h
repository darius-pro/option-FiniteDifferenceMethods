//////////////////////////////////////////////////////////////
//
//	This class represents a European Put option and is derived
//	from the Option class
//
//////////////////////////////////////////////////////////////

#pragma once

#include "Option.h"

class EurPut : public Option
{
public:
	EurPut(double strike, double T, double lower_sT, double upper_sT);
	double payoff(double sT);
	double upperBdCond(BSModel* BSParameters, double t);
	double lowerBdCond(BSModel* BSParameters, double t);

	double m_strike;
};
