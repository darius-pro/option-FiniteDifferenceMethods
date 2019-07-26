////////////////////////////////////////////////////////////
//
//	This is a class the performs the Explicit Method
//	numerical approximation and is derived from the FDMethod
//	class
//
////////////////////////////////////////////////////////////

#pragma once

#include "FDMethod.h"

class ExplicitMethod : public FDMethod
{
public:
	ExplicitMethod(PDE* PDE_to_solve, int i_Max, int j_Max);
	
	double A(int i, int j);
	double B(int i, int j);
	double C(int i, int j);
	double D(int i, int j);

	void solve();
};
