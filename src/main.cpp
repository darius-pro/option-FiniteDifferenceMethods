#include <iostream>
#include "BSModel.h"
#include "Put.h"
#include "BSEqn.h"
#include "Option.h"
#include "ExplicitMethod.h"
#include "ImplicitMethods.h"
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
	ExplicitMethod Method1(&BSPDE, imax, jmax);
	Method1.solve();
	cout << "Explicit Method: " << Method1.v(0.0, s0) << endl;

	// Implicit Method - LU Decomposition
	ImplicitMethods Method2(&BSPDE, imax, jmax);
	Method2.solveByLUDecomposition();
	cout << "Implicit Method (LU): " << Method2.v(0.0, s0) << endl;

	// Implicit Method - Sucessive Over Relaxation
	ImplicitMethods Method3(&BSPDE, imax, jmax);
	Method3.solveBySOR();
	cout << "Implicit Method (SOR): " << Method3.v(0.0, s0) << endl;

	// Crank Nicolson Method
	CNMethod Method4(&BSPDE, imax, jmax);
	Method4.solveByLUDecomposition();
	cout << "Crank Nicolson Method: " << Method4.v(0.0, s0) << endl;

	system("pause");
	return 0;
}