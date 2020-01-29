//============================================================================
// Name        : rec_ncr.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : number of combinations or nCr using recursion
//============================================================================

#include <iostream>
using namespace std;

/*
 *  nCr using recursion:
 *  nCr = n!/((n-r)!*r!)
 *
 *  ncr(n, r) = {		= n  							if r = 1
 *  					= ((n-r+1)/r) * ncr(n, r-1)		if r > 1
 *
 *				}
 */
float ncr(int n, int r)
{
	if (r <= 1) return n;

	return ((float)(n-r+1)/r)*ncr(n, r-1);
}

int main() {

	cout << "4C2 = ncr(4, 2) = " << ncr(4, 2);
}




