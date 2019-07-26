//////////////////////////////////////////////////////////////
//
//	This class stores the key parameters in the Black-Scholes
//	framework
//
//////////////////////////////////////////////////////////////
#pragma once

class BSModel
{
public:
	BSModel(double s0, double r, double sigma);

	double m_s0;
	double m_r;
	double m_sigma;
};
