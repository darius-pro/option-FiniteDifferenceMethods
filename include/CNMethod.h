////////////////////////////////////////////////////////////
//
//	This class is represents the Crank-Nicholson Method and
//	is derived from the ImplicitMethods base class
//
////////////////////////////////////////////////////////////

#pragma once

#include "ImplicitMethods.h"

class CNMethod : public ImplicitMethods
{
public:
	CNMethod(PDE* PDE_to_solve, int i_max, int j_max);

	double A(int i, int j);
	double B(int i, int j);
	double C(int i, int j);
	double D(int i, int j);
	double E(int i, int j);
	double F(int i, int j);
	double G(int i, int j);
};