//////////////////////////////////////////////////////////////
//
//	This class is an abstract class that represents all types 
//	of options
//
//////////////////////////////////////////////////////////////

#pragma once

#include "BSModel.h"

class Option
{
public:
	Option(double T, double lower_sT, double upper_sT);
	virtual double payoff(double sT) = 0;
	virtual double upperBdCond(BSModel* BSParameters, double t) = 0;
	virtual double lowerBdCond(BSModel* BSParameters, double t) = 0;

	double m_T;
	double m_upper_sT;
	double m_lower_sT;
};