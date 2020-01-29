//============================================================================
// Name        : rec_sum_of_first_n.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : recursion examples : sum of first n natural numbers
//============================================================================

#include <iostream>
using namespace std;


/*
 * Sum of first n natural numbers using recursive fn.
 * sum(n) = n*(n+1)/2
 * Sum(n) = n + sum(n-1)
 */

int rec_sum_of_first_n(int n)
{
	if(n == 0)
		return 0;

	return n + rec_sum_of_first_n(n-1);
}

int main() {

	/******* Recursion examples ********/
	cout << "sum of first 10 natural numbers = " << rec_sum_of_first_n(10);

	return 0;
}
