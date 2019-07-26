#include <iostream>
#include "BSModel.h"
#include "Put.h"
#include "BSEqn.h"
#include "Option.h"
#include "ExplicitMethod.h"
#include "CNMethod.h"
#include <Windows.h>

using namespace std;

int main()
{
	double s0 = 100.0, r = 0.05, sigma = 0.2;
	BSModel Model(s0, r, sigma);

	double K = 100.0, T = 1.0/12.0, upperST = 2.0 * s0, lowerST = 0.0;
	EurPut PutOption(K, T, lowerST, upperST);

	BSEqn BSPDE(&Model, &PutOption);

	int imax = 200, jmax = 1000;

	double time_start = GetTickCount();

	/*
	ExplicitMethod Method(&BSPDE, imax, jmax);
	Method.solve();

	double time_end = GetTickCount();

	cout << "Price: " << Method.v(0.0, s0) << endl;
	cout << "Calculation took: " << time_end - time_start << " ms" << endl << endl;
	*/

	CNMethod Method(&BSPDE, imax, jmax);
	Method.solveByLUDecomposition();

	cout << "Price: " << Method.v(0.0, s0) << endl;

	system("pause");
	return 0;
}