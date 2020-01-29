//============================================================================
// Name        : recursion.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : recursion
//============================================================================

#include <iostream>
using namespace std;

/*
 * Recursion:
 * -calling phase / ascending phase
 * -recursive call or recursive call + return phase
 * -returning phase / descending phase
 *
 */
void recursion(int n)
{
	if(n == 0)
	{
		cout << "All functions calls are in stack / Stack reached top " << endl;
		return;
	}

	//1. Ascending phase /Calling time execution
	//Expected output (for n = 5): 5, 4, 3, 2, 1
	cout << "calling phase - " << n << endl;

	//2. recursion call or recursive call + return phase
	recursion(n-1);

	//3. Descending phase / return time execution
	//Expected output (for n = 5): 1, 2, 3, 4, 5
	cout << "return phase - " << n << endl;
}

/*
 * Factorial
 */

int factorial(int n)
{
	if (n == 0)
		return 1;

	return n*factorial(n-1); // recursion + returning phase
}

int main() {

	cout << endl;
	cout << "recursion : " << endl;
	recursion(5);	//Expected output : calling phase - 5, 4, 3, 2, 1, returning phase - 1, 2, 3, 4, 5

	cout << endl;
	cout << "factorial : " << endl;
	int fact = factorial(5);	//Expected out put: = 5x4x3x2x1 = 120
	cout << "factorial(5) = " << fact << endl;

	return 0;
}
