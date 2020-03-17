//============================================================================
// Name        : linked list abstract data type header
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Linked list adt interfaces
//
//============================================================================

#ifndef _13_LINKED_LIST_ADT_H_
#define _13_LINKED_LIST_ADT_H_


class node
{
public:
	int data;
	node * next;
};

class linked_list
{
private:
	node * first;

public:
	linked_list();
	linked_list(int A[], int n);	//Convert array to linked list
	~linked_list();

	void display();					//Display linked lest elements
	void display_rec();				//Display elements - in recursive method
	void insert(int index, int x);	//insert a given element in the given position
	int delete_element(int index);	//delete an element from the given position
	int length();					//number of elements in the linked list

	int sum();	//sum of all elements in a linked list
	int max();
	int min();
	int search(int key);	//linear search //T(n) = O(n)

	bool is_sorted();
	void remove_duplicates();
	void reverse(); //reverse list
	linked_list *  merge(linked_list list2); //new list is created
	void merge_inplace(linked_list & list2); //no new memory is needed
	bool check_loop(); //check there is a loop or not in the list

	int middle_element();
};







#endif /* 13_LINKED_LIST_ADT_H_ */
