//////////////////////////////////////////////////////////////
//
//	This abstract class represents the general parabolic PDE:
//	Ft + a*Fxx + b*Fx + c*F + d = 0
//
//	It contains three variables defining the x/T space:
//	xu, xl - Upper and lower bounds of x
//	T - Upper bound of T such that F : [0,T]
//
//	It also contains upper (f_Upper), lower (f_Lower) and terminal (f)
//	boundary conditions
//
//////////////////////////////////////////////////////////////

#pragma once


class PDE
{
public:
	PDE(double T, double xLower, double xUpper) : m_T(T), m_xLower(xLower), m_xUpper(xUpper) {}

	double m_xUpper;
	double m_xLower;
	double m_T;

	virtual double a(double t, double x) = 0;
	virtual double b(double t, double x) = 0;
	virtual double c(double t, double x) = 0;
	virtual double d(double t, double x) = 0;
	virtual double e(double t, double x) = 0;

	virtual double f(double x) = 0;
	virtual double f_Upper(double t) = 0;
	virtual double f_Lower(double t) = 0;


};
