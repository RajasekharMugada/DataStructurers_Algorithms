//============================================================================
// Name        : arra_adt.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Array Abstract Data Type features
//============================================================================

#include <iostream>
using namespace std;



class Array
{
private:
	int *A;		//pointer to an array
	int size;	//max capacity of the array
	int length;	//number of elements in the array

public:
	Array(int sz = 20)		//constructor
	{
		//Initialize the array with default size as 10
		size = sz;
		length = 0;
		A = new int [size];
	}
	~Array()	//desctructor
	{
		delete [] A;
		size = 0;
		length = 0;
	}

	void display(void);

	void append(int x);
	void insert(int index, int x);
	void delete_element_at(int index);
	void insert_in_sorted_array(int x);

	//searching techniques
	int linear_search(int key);			//T(n) = O(n)
	int binary_search(int key);			//T(n) = O(log(n))
	int binary_search_recursive(int key, int l, int h);
	//sorting techniques
	void bubble_sort();					//T(n) = O(n2)
	void selection_sort();				//T(n) = O(n2) //not implemented
	void insert_sort();					//not implemented
	void heap_sort();					//not implemented
	int is_sorted();

	int get(int index);
	void set(int index, int x);
	int max();
	int min();
	int sum();
	float avg();
	void reverse();
	void rearrange();	//all -ve elements towards left and +ve ones towards right side

	Array * merge_sorted_arrays(Array arr2);	//Merge two sorted array data structures
	Array * union_array(class Arr2);
	Array * intersection(class Arr2);
	Array * difference(class Arr2);

private:
	void swap(int & x, int & y);

};


void Array::display()
{
	cout << endl << "Elements are : ";
	for(int i = 0; i< length; i++)
	{
		cout << A[i] << " ";
	}
}

void Array :: append(int x)
{
	if(length < size)
	{
		A[length++] = x;
	}

}

/*
 * Insert the element at the given position:
 * Shift all the elements from last index to the given index - one step to the right
 * Place the given index at the given position
 */
void Array :: insert(int index, int x)
{
	int i;

	//check input arguments for boundary conditions
	if(length >= size || index < 0 || index > length)
	{
		return;
	}

	for(i = length; i > index; i--)
	{
		A[i] = A[i-1];
	}
	A[i] = x;
	length++;
}

/*
 * Delete an element from the given index:
 * Shift all the elements which are right side of the given index to one step left
 */
void Array :: delete_element_at(int index)
{
	if(length == 0 || index >= length)
		return;
	if(length == 1)
		length--;

	for(int i = index+1; i < length; i++)
	{
		A[i-1] = A[i];
	}
	length--;
}

void Array :: insert_in_sorted_array(int x)
{
	if(length == size)
	{
		return;
	}

	int i = length -1;

	//Find the proper position for the given element from back side of the list
	//Right shift all the list element which are greater than the given element
	while(A[i] > x)
	{
		A[i+1] = A[i];
		i--;
	}

	//Insert the given element at the desired location
	A[i+1] = x;

	length++;
}


int Array :: linear_search(int key)
{
	for(int i = 0; i< length; i++)
	{
		if(A[i] == key)
			return i;
	}

	return -1;	//not found
}

/*Binary search:
 * 1. Works only on sorted elements
 * 2. repetitive/recursive method:
 * 			- Check the middle element for the key if not found
 * 			- Divide the list in to half and select which half to work on
 */
int Array :: binary_search(int key)
{
	int l = 0;
	int h = length -1;
	int m = 0;

	while(l <= h)
	{
		m = (l+h)/2;

		if(key == A[m])
		{
			return m;
		}
		else if (key < A[m])
		{
			h = m-1;
		}
		else if (key > A[m])
		{
			l = m+1;
		}
	}
	return -1; // not dfound
}

/*Binary search in recursive method:
 * 1. Works only on sorted elements
 * 2. repetitive/recursive method:
 * 			- Check the middle element for the key if not found
 * 			- Divide the list in to half and select which half to work on
 * 3. Pass low, high index for the array to search
 */
int Array :: binary_search_recursive(int key, int l, int h)
{
	int m = 0;

	if(l <= h)
	{
		m = (l+h)/2;

		if(key == A[m])
		{
			return m;
		}
		else if (key < A[m])
		{
			h = m-1;
			return binary_search_recursive(key, l, h);
		}
		else if (key > A[m])
		{
			l = m+1;
			return binary_search_recursive(key, l, h);
		}
	}
	return -1; // not found
}


void Array :: bubble_sort()
{
	int i = 0, j = 0;
	int flag_sorted = 0;

	// number of scans over entire list
	for(i = 0; i< length -1; i++)
	{
		flag_sorted = 1;

		//number of comparisons in each scan
		for (j = 0; j< length -1 - i; j++)
		{
			if(A[j] > A[j+1])
			{
				swap(A[j], A[j+1]);
				flag_sorted = 0;
			}
		}

		if(flag_sorted)
		{
			return;
		}
	}
}


int Array :: is_sorted()
{
	for (int i = 0; i< length -1; i++)
	{
		if(A[i] > A[i+1])
			return 0;
	}
	return 1;
}


int Array :: get(int index)
{
	if(index >= length)
		return -1;

	return A[index];
}

void Array :: set(int index, int x)
{
	if(index >= length)
	{
		return;
	}

	A[index] = x;
}

int Array :: max()
{
	if(length <= 0)
		return -1;

	int max = A[0];

	for(int i = 0; i < length; i++)
	{
		if(A[i] > max)
			max = A[i];
	}

	return max;
}

int Array :: min()
{
	if(length <= 0)
		return -1;

	int min = A[0];

	for(int i = 0; i < length; i++)
	{
		if(A[i] < min)
			min = A[i];
	}

	return min;
}

int Array :: sum()
{
	int sum = 0;
	for(int i = 0; i < length; i++)
	{
		sum += A[i];
	}

	return sum;
}

float Array :: avg()
{
	if(length <= 0)
		return 0;

	return (float)sum()/length;
}

void Array :: swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void Array :: reverse()
{
	if(length <= 1)
	{
		return;
	}

	int i = 0, j = length -1;
	while(i < j)
	{
		swap(A[i], A[j]);
		i++;
		j--;
	}
}

void Array :: rearrange()
{
	int i = 0, j = length -1;
	while(i > j)
	{
		while(A[i] < 0)
			i++;
		while(A[j] > 0)
			j--;
		if(i < j)
			swap(A[i], A[j]);
	}
}


//Set operations
Array * Array :: merge_sorted_arrays(Array arr2)
{
	int i, j, k;

	Array * new_arr = new Array(length + arr2.length);

	i = 0; //first array indexing
	j = 0; //second array indexing
	k = 0; //result array indexing

	//merge sort
	while(i < length && j < arr2.length)
	{
		if(A[i] < arr2.A[j])
		{
			new_arr->A[k] = A[i];
			i++; k++;
		}
		else
		{
			new_arr->A[k] = arr2.A[j];
			j++; k++;
		}
	}

	while(i < length)
	{
		new_arr->A[k] = A[i];
		i++; k++;
	}

	while(j < arr2.length)
	{
		new_arr->A[k] = arr2.A[j];
		j++; k++;
	}

	new_arr->length = k;

	return new_arr;
}

int main ()
{
	Array arr;

	//Append elements
	arr.append(1);
	arr.append(2);
	arr.append(3);
	arr.append(11);
	arr.append(12);
	arr.append(13);
	arr.append(21);
	arr.append(22);
	arr.append(23);
	arr.display();
	//Insert an element
	arr.insert(1, 1000);
	arr.display();
	//Delete an element
	arr.delete_element_at(1);
	arr.display();

	//Linear search
	arr.display();
	cout << endl << "Linear search : searching for key 10: found at index ";
	cout << arr.linear_search(10);
	cout << endl << "Linear search : searching for key 12: found at index ";
	cout << arr.linear_search(12);

	//Binary search
	arr.display();
	cout << endl << "Binary search : searching for key 10: found at index ";
	cout << arr.binary_search(10);
	cout << endl << "Binary search : searching for key 12: found at index ";
	cout << arr.binary_search(12);

	//Binary search - recursive
	arr.display();
	cout << endl << "Binary search - recursive : searching for key 10: found at index ";
	cout << arr.binary_search(10);
	cout << endl << "Binary search - recursive : searching for key 12: found at index ";
	cout << arr.binary_search(12);

	//get, set, min, max, sum, avg
	arr.display();
	cout << endl<< "Get element at index 0 : " << arr.get(0);
	cout << endl<< "Set element at index 0 to 5: ";
	arr.set(0, 5);
	arr.display();
	cout << endl<< "Min val : " << arr.min();
	cout << endl<< "Max val : " << arr.max();
	cout << endl<< "Sum : " << arr.sum();
	cout << endl<< "Avg : " << arr.avg();

	//reverse
	arr.display();
	arr.reverse();
	cout << endl<< "In reverse order : ";
	arr.display();

	//sort
	cout << endl<< "Bubble sort : ";
	arr.bubble_sort();
	arr.display();

	//insert an element in a sorted list
	cout << endl<< "Insert 20 in the sorted list : ";
	arr.insert_in_sorted_array(20);
	arr.display();

	//create a new array
	Array arr2;
	arr2.append(6);
	arr2.append(10);
	arr2.append(2);
	arr2.append(100);
	arr2.append(50);
	arr2.bubble_sort();

	//Merge sort two arrays
	Array * arr3;

	cout << endl << "Array 1 : " ;
	arr.display();
	cout << endl << "Array 2 : " ;
	arr2.display();
	arr3 = arr.merge_sorted_arrays(arr2);
	cout << endl << "Merging Array 1 and Array 2 : ";
	arr3->display();
}
