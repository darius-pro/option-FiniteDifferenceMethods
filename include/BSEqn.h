//////////////////////////////////////////////////////////////
//
//	This class represents the Black-Scholes PDE, and is
//	derived from the PDE class (which represents a general
//	parabolic PDE)
//
//////////////////////////////////////////////////////////////

#pragma once

#include "PDE.h"
#include "BSModel.h"
#include "Option.h"

class BSEqn : public PDE
{
public:
	BSModel * m_BSParameters;
	Option * m_BSOption;

	BSEqn(BSModel* BSParameters, Option* BSOption);

	double a(double t, double S);
	double b(double t, double S);
	double c(double t, double S);
	double d(double t, double S);
	double e(double t, double S);

	double f(double S);
	double f_Upper(double t);
	double f_Lower(double t);
};
