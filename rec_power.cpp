//============================================================================
// Name        : rec_power.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : recursion examples : calculate power using recursion
//============================================================================

#include <iostream>
using namespace std;


/*
 * Calculate power using recursive fn.
 * power(n, m) = n^m;
 * power(n, m) = {
 * 					1					if m = 0
 * 					n*power(n, m-1)     if m > 0
 * 				 }
 */

int rec_power(int n, int m)
{
	if(m == 0)
		return 1;

	return n * rec_power(n, m-1);
}

int main() {

	/******* Recursion examples ********/
	cout << "(n ^ m) = 2 power 5 = " << rec_power(2, 5);

	return 0;
}



