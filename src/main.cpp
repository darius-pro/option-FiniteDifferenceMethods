#include <iostream>
#include "BSModel.h"
#include "Put.h"
#include "BSEqn.h"
#include "Option.h"
#include "ExplicitMethod.h"
#include "ImplicitMethod.h"
#include "CNMethod.h"

using namespace std;

int main()
{
	double s0 = 100.0, r = 0.05, sigma = 0.2;
	BSModel Model(s0, r, sigma);

	double K = 100.0, T = 1.0/12.0, upperST = 2.0 * s0, lowerST = 0.0;
	EurPut PutOption(K, T, lowerST, upperST);

	BSEqn BSPDE(&Model, &PutOption);

	int imax = 200, jmax = 1000;

	// Explicit Method
	ExplicitMethod Method(&BSPDE, imax, jmax);
	Method.solve();
	cout << "Explicit Method: " << Method.v(0,0, s0) << endl;

	// Implicit Method - LU Decomposition
	ImplicitMethods Method(&BSPDE, imax, jmax);
	Method.solveByLUDecomposition();
	cout << "Implicit Method (LU): " << Method.v(0,0, s0) << endl;

	// Implicit Method - Sucessive Over Relaxation
	ImplicitMethods Method(&BSPDE, imax, jmax);
	Method.solveBySOR();
	cout << "Implicit Method (SOR): " << Method.v(0,0, s0) << endl;

	// Crank Nicolson Method
	CNMethod Method(&BSPDE, imax, jmax);
	Method.solveByLUDecomposition();
	cout << "Crank Nicolson Method: " << Method.v(0,0, s0) << endl;

	system("pause");
	return 0;
}