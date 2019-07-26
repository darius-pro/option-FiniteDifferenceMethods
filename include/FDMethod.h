////////////////////////////////////////////////////////////
//
//	This class is a base class uses to derive all finite
//	difference methods from.
//
//	It contains the following:
//	t(i) - t-value at the i-th step
//	x(j) - x-value at the j-th step
//
//	a(i,j) - co-efficient a at i,j
//	b(i,j) - co-efficient b at i,j
//	c(i,j) - co-efficient c at i,j
//	d(i,j) - co-efficient d at i,j
//	e(i,j) - co-efficient e at i,j
//
//	f(x) - terminal boundary condition
//	f_Upper(t) - upper boundary condition
//	f_Lower(t) - lower boundary condition
//
////////////////////////////////////////////////////////////

#pragma once

#include "PDE.h"
#include <vector>

using namespace std;

typedef vector<double> Vector;

class FDMethod
{
public:
	PDE *m_PDE;
	FDMethod(PDE* PDE_to_solve, int i_max, int j_max);
	
	double t(double i);
	double x(double j);

	vector<Vector> V;

	double a(double i, int j);
	double b(double i, int j);
	double c(double i, int j);
	double d(double i, int j);
	double e(double i, int j);

	double f(int j);
	double f_Upper(double i);
	double f_Lower(double i);

	int m_iMax;
	int m_jMax;
	double m_deltaX;
	double m_deltaT;

	double v(double t, double x);
};
