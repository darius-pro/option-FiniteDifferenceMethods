////////////////////////////////////////////////////////////
//
//	This is an abstract base class from which other Implicit 
//	schemes are derived from. This class is derived from the
//	FDMethod class, as Implicit methods are finite-difference
//	methods themselves
//
//	Represents finite-difference discretisation:
//	E*v(i-1,j-1) + F*v(i-1,j) + G*v(i-1,j+1) =
//	A*v(i,j-1) + B*v(i,j) + C*v(i,j+1) + D;
//
//	Represented in matrix form: B(i)v(i-1) = A(i)v(i) + w(i)
//
//	This class contains:
//	w(i) - returns w vector
//	A(i, vector) - returns vector A(i)*vector
//	LUDecomposition(i,vector) - returns LU composition of
//								vector at i
//	
//
////////////////////////////////////////////////////////////

#pragma once

#include "FDMethod.h"
#include "Matrix.h"

class ImplicitMethods : public FDMethod
{
public:
	ImplicitMethods(PDE* PDE_to_solve, int i_max, int j_max);

	virtual double A(int i, int j) = 0;
	virtual double B(int i, int j) = 0;
	virtual double C(int i, int j) = 0;
	virtual double D(int i, int j) = 0;
	virtual double E(int i, int j) = 0;
	virtual double F(int i, int j) = 0;
	virtual double G(int i, int j) = 0;

	Vector w(int i);
	Vector Av(int i, Vector input_vector);

	Vector LUDecomposition(int i, Vector input_vector);

	void solveByLUDecomposition();

	void solveBySOR();
};
