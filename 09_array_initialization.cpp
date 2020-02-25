//============================================================================
// Name        : array_initialization.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Array initialization techniques : Static, Dynamic initialization
//============================================================================

#include <iostream>
using namespace std;

/*
 * Initialize array using static memory
 */
void static_arr_init(void)
{

	int *arr_ptr;

	int i = 0; //loop iterator

	/* Initialize array with size 10 */
	int arr[10];
	int size = sizeof(arr)/sizeof(arr[0]);

	for(i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	arr_ptr = &arr[0];

	cout << "static array: initialize the array to size 10 : " <<endl;
	cout << "array address : " << arr_ptr << " array : ";
	for(i = 0; i < size; i++)
	{
		cout << arr_ptr[i] << " ";
	}


	/* re-size array to size 15 */
	int arr_new[15];
	int size_new = sizeof(arr_new)/sizeof(arr_new[0]);

	for(i = 0; i < size; i++)
	{
		arr_new[i] = arr[i];
	}
	for(; i < size_new; i++)
	{
		arr_new[i] = i + 1;
	}

	arr_ptr = &arr_new[0];
	cout << endl << "static array: resize the array to size 15 : " << endl;
	cout << "array address : " << arr_ptr << " array : ";
	for(i = 0; i < size_new; i++)
	{
		cout << arr_ptr[i] << " ";
	}
}

/*
 * Initialize array using dynamic memory (heap)
 * -There will not be any storage wastage for reassigning dynamic array
 */
void dynamic_arr_init(void)
{

	int i = 0; //loop iterator

	/* Initialize array with size 10 */
	int *arr_ptr = new int [10];
	int size = 10;

	for(i = 0; i < size; i++)
	{
		arr_ptr[i] = i + 1;
	}
	cout << endl;
	cout << "dynamic array: initialize the array to size 10 : " <<endl;
	cout << "array address : " << &arr_ptr << " array : ";
	for(i = 0; i < size; i++)
	{
		cout << arr_ptr[i] << " ";
	}


	/* re-size array to size 15 */
	int * arr_new_ptr = new int [15];
	int size_new = 15;

	for(i = 0; i < size; i++)
	{
		arr_new_ptr[i] = arr_ptr[i];
	}
	for(; i < size_new; i++)
	{
		arr_new_ptr[i] = i + 1;
	}

	//Delete old array memory space
	//Assign old array ptr address for newly created array
	delete [] arr_ptr;
	arr_ptr = arr_new_ptr;
	arr_new_ptr = NULL;

	cout << endl << "static array: resize the array to size 15 : " << endl;
	cout << "array address : " << &arr_ptr << " array : ";
	for(i = 0; i < size_new; i++)
	{
		cout << arr_ptr[i] << " ";
	}
}


int main(void)
{
	static_arr_init();
	dynamic_arr_init();

	return 0;
}

