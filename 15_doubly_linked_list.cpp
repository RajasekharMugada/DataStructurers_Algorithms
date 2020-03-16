//============================================================================
// Name        : doubly linked  linked list abstract data type
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : doubly linked  Linked list representation and commonly used methods
//
//============================================================================
#include <iostream>
using namespace std;


class node
{
public:
	int data;
	node * next;
	node * prev;
};

class doubly_ll
{
private:
	node * first;

public:
	doubly_ll()
	{
		first = NULL;
	}
	doubly_ll(int A[], int len);
	~doubly_ll();

	void display();
	int length();
	void insert(int index, int x);
	void delete_elem(int index);

};


doubly_ll :: doubly_ll(int A[], int len)
{

	node * q; //tail pointer

	if(len <= 0)
		return;

	//first node
	node * p = new node;
	p->data = A[0];
	first = p;
	first->next = NULL;
	first->prev = NULL;
	q = first;

	for(int i = 1; i< len; i++)
	{
		node * p = new node;
		p->data = A[i];
		p->next = NULL;
		p->prev = q;
		q->next = p;
		q = p;
	}
}

doubly_ll :: ~doubly_ll()
{
	node * p = first;

	if(first == NULL)//no elements in the list
		return;

	while(p->next != NULL)
	{
		delete p->prev;
	}
	//delete last element
	delete p;
	first = NULL;
}

void doubly_ll::display()
{
	node * p = first;

	cout << endl << "doubly linked  list elements are : ";
	if(first == NULL)
		return;

	while(p->next != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	//last element
	cout << p->data;
}

int doubly_ll::length()
{
	node * p = first;
	int len = 0;

	if(first == NULL)
		return 0;

	while(p->next != NULL)
	{
		len++;
		p = p->next;
	}

	return ++len; //including last node
}

void doubly_ll :: insert(int index, int x)
{
	int len = length();
	int pos = 0;
	node * p;

	if(index < 0 || index > len)
	{
		return;
	}

	//create memory for new node
	node * n = new node;
	n->data = x;

	//insert at index 0
	if(index == 0)
	{
		p = first;
		n->next = p;
		n->prev = NULL;
		p->prev = n;
		first = n;
	}
	else if(index == len) //insert at the end of the list
	{
		p = first;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = n;
		n->prev = p;
		n->next = NULL;
	}
	else //insert in betrween list
	{
		//go to that index
		p = first;
		while(pos < index)
		{
			pos++;
			p = p->next;
		}
		p->prev->next = n;
		n->prev = p->prev;
		p->prev = n;
		n->next = p;
	}
}

void doubly_ll::delete_elem(int index)
{
	int len = length();
	int pos = 0;

	node * p = first;

	if(index < 0 || index >= len || first == NULL)
	{
		return;
	}

	//only single element in the list
	if(len == 1)
	{
		delete first;
		first = NULL;
	}
	else if(index == 0) //delete the first element
	{
		p = first;
		first = p->next;
		first->prev = NULL;
		delete p;
	}
	else //between first and last node
	{
		p = first;
		//reach to the node
		while(pos < index && p->next != NULL)
		{
			pos++;
			p = p->next;
		}

		p->prev->next = p->next;
		if(index < len -1)
		{
			p->next->prev = p->prev;
		}

		delete p;
	}
}

int main()
{
	//create doubly linked  linked list
	int A[4] = {1, 2, 3};
	doubly_ll dll(A, 3);

	//display doubly linked  linked list elements
	dll.display();

	//length
	cout << endl << "List length : " << dll.length();

	//insert an element
	dll.insert(0, 0);
	cout << endl << "Inserting 0 at index 0";
	dll.display();
	cout << endl << "Inserting 50 at end of the list";
	dll.insert(dll.length(), 50);
	dll.display();
	cout << endl << "Inserting 10 at index 1";
	dll.insert(1, 10);
	dll.display();
	//length
	cout << endl << "List length : " << dll.length();

	//deleting an element from the given location
	dll.delete_elem(0);
	cout << endl << "Deleting first node";
	dll.display();
	dll.delete_elem(1);
	cout << endl << "Deleting element at index 1";
	dll.display();
	dll.delete_elem(dll.length()-1);
	cout << endl << "Deleting last node";
	dll.display();

	cout << endl << "Good Bye !!";
	return 0;
}



