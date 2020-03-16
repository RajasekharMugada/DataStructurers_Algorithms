//============================================================================
// Name        : Circular linked list abstract data type
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Circular Linked list representation and commonly used methods
//
//============================================================================

#include <iostream>
using namespace std;


class node
{
public:
	int data;
	node * next;
};

class circular_ll
{
private:
	node * first;

public:
	circular_ll()
	{
		first = NULL;
	}
	circular_ll(int A[], int len);
	~circular_ll();

	void display();
	int length();
	void insert(int index, int x);
	void delete_elem(int index);

};


circular_ll::circular_ll(int A[], int len)
{
	node * q = first; //tail pointer

	if(len <= 0)
		return;

	//first node
	node * p = new node;
	p->data = A[0];
	first = p;
	p->next = first;
	q = p;

	for(int i = 1; i< len; i++)
	{
		node * p = new node;
		p->data = A[i];
		p->next = first;
		q->next = p;
		q = p;
	}
}


circular_ll :: ~circular_ll()
{
	node * p = first, *q = first ;

	if(p == NULL)//no elements in the list
		return;


	while(p->next != first)
	{
		q = p;
		p = p->next;
		delete q;
	}
	//delete last element
	delete p;
	first = NULL;
}

void circular_ll::display()
{
	node * p = first;

	cout << endl << "circular list elements are : ";
	if(p == NULL)
		return;

	while(p->next != first)
	{
		cout << p->data << " ";
		p = p->next;
	}
	//last element
	cout << p->data;
}

int circular_ll::length()
{
	node * p = first;
	int len = 0;

	if(first == NULL)
		return 0;

	while(p->next != first)
	{
		len++;
		p = p->next;
	}

	return ++len; //including last node
}

void circular_ll:: insert(int index, int x)
{
	int len = length();
	int pos = 0;

	node * p = first, *q = first;

	if(index < 0 || index > len || first == NULL)
	{
		return;
	}

	//create a node
	node * n = new node;
	n->data = x;

	if(index == 0) //insert the element at the begining
	{
		//find out last node
		p = first;
		while(p->next != first)
		{
			p = p->next;
		}

		n->next = first;
		first = n;
		p->next = first;
	}
	else if(index == len) //insert element at the end
	{
		//find out last node
		p = first;
		while(p->next != first)
		{
			p = p->next;
		}
		p->next = n;
		n->next = first;
	}
	else //insert the element between first and last element
	{
		//Insert element at node p (i.e. before p and after q)
		//go to required location
		while(pos < index)
		{
			pos++;
			q = p;
			p = p->next;
		}
		n->next = p;
		q->next = n;
	}
}

void circular_ll::delete_elem(int index)
{
	int len = length();
	int pos = 0;

	node * p = first, *q = first;

	if(index < 0 || index >= len || first == NULL)
	{
		return;
	}

	//only single element in the list
	if(len == 0)
	{
		delete first;
		first = NULL;
	}
	else if(index == 0) //delete the first element
	{
		//find out last node
		p = first;
		q = first;
		while(q->next != first)
		{
			q = q->next;
		}
		first = p->next;
		q->next = first;
		delete p;
	}
	else //between first and last node
	{
		q = first;
		p = first;
		//reach to the node
		while(pos < index)
		{
			pos++;
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
}

int main()
{
	//create circular linked list
	int A[4] = {1};
	circular_ll cll(A, 1);

	//display circular linked list elements
	cll.display();

	//length
	cout << endl << "List length : " << cll.length();

	//insert an element
	cll.insert(0, 0);
	cout << endl << "Inserting 0 at index 0";
	cll.display();
	cout << endl << "Inserting 50 at end of the list";
	cll.insert(cll.length(), 50);
	cll.display();
	cout << endl << "Inserting 10 at index 1";
	cll.insert(1, 10);
	cll.display();

	//deleting an element from the given location
	cll.delete_elem(0);
	cout << endl << "Deleting first node";
	cll.display();

	cll.delete_elem(cll.length()-1);
	cout << endl << "Deleting last node";
	cll.display();

	cout << endl << "Good Bye !!";
	return 0;
}


