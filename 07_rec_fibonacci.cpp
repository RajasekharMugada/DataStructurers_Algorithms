//============================================================================
// Name        : rec_fibonacci.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Fibanocci number using recursion
//============================================================================

#include <iostream>
using namespace std;

/*
 * Return Fibonacci number as per the given series index
 * Fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21 ...
 *fib(n) = {
 *				= 0 					if n = 1
 *				= 1   					if n = 2
 *				= fib(n-1)+fib(n-2)		if n > 2
 *			}
 */
int fibonacci(int n)
{
	if(n <= 1) return 1;
	if(n == 2) return 1;

	return fibonacci(n-1)+fibonacci(n-2);
}

int main () {

	cout << "Fibonacci series : 1, 1, 2, 3, 5, 8, 13, 21 ..." << endl;
	cout << "Fibonacci number (6) =  " << fibonacci(6);

}




