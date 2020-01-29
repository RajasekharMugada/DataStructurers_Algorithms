//============================================================================
// Name        : rec_taylor_series.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : recursion examples : taylor series expansion for e^x using recursion
//============================================================================

#include <iostream>
using namespace std;

/*
 * Taylor series expansion for e^x using recursion: Horner's rule : Optimized solution
 * exp(x, n) = 1 + x/1 + x^2/2! + x^3/3! + ... +x^(n-1)/(n-1)!   ;  n-terms
 * exp(x, n) = {   (static m = 0, m++)
 * 					= 1				  				if n <= m
 * 					= 1 + (x/m)*exp(x, n)     	if n > m
 * 				 }
 */
float taylor_series_exp_horner(int x, int n)
{
	static int m = 0;
	m++;

	if(n <= m)
		return 1;

	return 1 + ((float)x/m)*taylor_series_exp_horner(x, n);
}


/*
 * Taylor series expansion for e^x using optimized power, factorial
 * exp(x, n) = 1 + x/1 + x^2/2! + x^3/3! + ... +x^(n-1)/(n-1)!   ;  n-terms
 * exp(x, n) = {   (static p = 1, f = 1, m = 1)
 *									if n = 1
 * 					= 1
 * 									if n > 1
 * 					p = p*x
 * 					f = f*(m++)
 * 					= p/f + exp(x, n-1)
 * 				 }
 */
float taylor_series_exp_using_power_factorial_opt(int x, int n)
{
	static int p = 1, f = 1, m = 1;

	if(n <= 1)
		return 1;

	p = p*x;
	f = f*(m++);

	return (float)p/f + taylor_series_exp_using_power_factorial_opt(x, n-1);
}



/*
 * Calculate power using recursive
 * power(n, m) = n^m;
 * power(n, m) = {
 * 					= 1					if m = 0
 * 					= n*power(n, m-1)     if m > 0
 * 				 }
 */
float rec_power(float n, int m)
{
	if(m == 0)
		return 1.0;
	return n * rec_power(n, m-1);
}

/*
 * Factorial using recursion:
 * factorial(n) = { 1					if n = 0
 * 					n*factorial(n-1)	if n > 0 }
 */
int rec_factorial(int n)
{
	if (n == 0)
		return 1;
	return n*rec_factorial(n-1);
}


/*
 * Taylor series expansion for e^x using power, factorial functions
 * exp(x, n) = 1 + x/1 + x^2/2! + x^3/3! + ... +x^(n-1)/(n-1)!   ;  n-terms
 * exp(x, n) = {
 * 					1				  			if n = 0
 * 					(x^n/n!) + exp(x, n-1)     	if n > 0
 * 				 }
 */

float taylor_series_exp_using_power_factorial(int x, int n)
{
	if(n <= 1)
		return 1.0;

	return (rec_power(x, n-1)/rec_factorial(n-1)) +  taylor_series_exp_using_power_factorial(x, n-1);
}

int main() {

	/******* Recursion examples ********/
	cout << "Taylor series - using horner's rule: (e ^ 2) = " << taylor_series_exp_horner(2, 10);
	cout << endl;
	cout << "Taylor series - using power, factorial: (e ^ 2) = " << taylor_series_exp_using_power_factorial(2, 10);
	cout << endl;
	cout << "Taylor setries - using optimized power, factorial: (e ^ 2) = " << taylor_series_exp_using_power_factorial_opt(2, 10);

	return 0;
}



