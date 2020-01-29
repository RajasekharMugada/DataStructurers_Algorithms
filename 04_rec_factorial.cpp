//============================================================================
// Name        : rec_factorial.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : recursion examples : calculate factorial using recursion
//============================================================================

#include <iostream>
using namespace std;


/*
 * Calculate factorial using recursive fn.
 * factorial(n) = 1*2*...(n-1)*n;
 * factorial(n) = {
 * 					 = 1					if n = 1
 * 					 = n*factorial(n-1)     if n > 1
 * 				  }
 */
int rec_factorial(int n)
{
	if(n <= 1)
		return 1;

	return n * rec_factorial(n-1);
}

int main() {

	/******* Recursion examples ********/
	cout << "factorial(5) = " << rec_factorial(5);

	return 0;
}
