//============================================================================
// Name        : array_based_algorithms.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Commonly used algorithms based on Array ADT
//		1. Count number of pairs whose sum is K
//
//============================================================================

#include <iostream>
using namespace std;

//Count pair of numbers whose sum is K
int count_pairs_with_given_sum(int sum, int * array_ptr, int array_size)
{
	int * hash_ptr = new int[sum];
	int m = 0, n = 0; //pair of numbers such that m+n = k
	int count = 0;

	//Prepare hash table to check other element in the pair is
	//present or not in the given input array
	for(int i = 0; i < sum; i++)
	{
		hash_ptr[i] = 0;
	}

	//Scan through the i/p array and mark Hash table for the corresponding index
	//and check the other element in the pair is already present(particular index is set) or not.
	for(int i = 0; i< array_size; i++)
	{
		m = array_ptr[i];
		n = sum - m;
		if(hash_ptr[n] == 1)	//pair exists
		{
			count++;
		}
		hash_ptr[m] = 1;
	}

	delete [] hash_ptr;

	return count;
}



int main()
{
	int arr[9] = {2, 3, 12, 1, 7, 8, 7, 3, 8};
	int num_pairs = count_pairs_with_given_sum(15, arr, 9);


	cout << "Given array: ";
	for (int i =0; i< 9; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	cout << "Number of pair with sum 15 are : " << num_pairs << endl;

	return 0;
}




