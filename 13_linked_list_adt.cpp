//============================================================================
// Name        : linked list abstract data type
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Linked list representation and commonly used methods
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

class linked_list
{
private:
	node * first;

public:
	linked_list(){ first = NULL;};
	linked_list(int A[], int n);	//Convert array to linked list
	~linked_list();

	void display();					//Display linked lest elements
	void display_rec();				//Display elements - in recursive method
	void insert(int index, int x);	//insert a given element in the given position
	int delete_element(int index);	//delete an element from the given position
	int length();					//number of elements in the linked list
};

//Convert given array in to linked list
linked_list :: linked_list(int A[], int n)
{
	node * t;		//temp node	pointer
	node * last;	//last added node pointer

	if(n <= 0)
	{
		first = NULL;
		return;
	}

	first = new node;		//first node
	first->data = A[0];
	first->next = NULL;
	last = first;

	for(int i = 1; i < n; i++)
	{
		t = new node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

//Destructor //Clear all the allocated memory
linked_list :: ~ linked_list()
{
	node * n, * last;
	n = first;
	last = n;

	while(n)
	{
		n = n->next;
		delete last;
		last = n;
	}

	first = NULL;
}

//Display all the elements in the list
void linked_list::display()
{
	node * n = first;
	cout << endl << "list elements : ";
	while(n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}

//Display list elements using recursive
void linked_list::display_rec()
{
	static node * p = first; //p -> current node and q -> tail pointer

	if(p != NULL)
	{
		cout << p->data << " ";
		p = p -> next;
		display_rec();
	}
}


//Insert a given element at the given position
void linked_list::insert(int index, int x)
{
	//insert the given element between (index-1) and (index)
	//node at given index => n, node at previous index = > p(following/tail pointer)

	node * n = first;	//current node
	node * p = first;	//tail pointer
	int pos = 0;	///current node position

	node * t = new node;	//node to insert
	t->data = x;
	t->next = NULL;

	if(index < 0)
	{
		delete t;
	}
	else if(index == 0)	//update head node
	{
		t->next = first;
		first = t;
	}
	else
	{
		//go to required position
		while(n != NULL && pos < index)
		{
			p = n;
			n = n->next;
			pos++;
		}

		//index out of range
		if(pos < index)
		{
			delete t;
		}
		//index is within the list
		else
		{
			t->next = n;
			p->next = t;
		}
	}
}

//delete an element from the given position
int linked_list::delete_element(int index)
{
	node * n = first, *p = first;	//current node , tail pointer
	int x;	//value being deleted

	//invalid index
	if(index < 0 || index > length() || length() == 0)
	{
		return -1;
	}
	if(index == 0)
	{
		p = first;
		first = first->next;
		x = p->data;
		delete p;
	}

	//go to the right index
	while(index > 0)
	{
		p = n;
		n = n->next;
		index--;
	}

	//delete the link and the memory
	p->next = n->next;
	x = n->data;
	delete n;

	return x;
}

//no. of elements in the list
int linked_list::length()
{
	int len = 0;

	node * n = first;
	while(n != NULL)
	{
		n = n->next;
		len++;
	}
	return len;
}

int main()
{
	int A[] = {1, 2, 3, 4};

	//convert array to linked list
	linked_list list(A, sizeof(A)/sizeof(A[0]));

	//display linked list elements
	list.display();

	//display list elements using recursion
	cout << endl << "List elements - display using recursion : ";
	list.display_rec();


	//list length
	cout << endl <<  "list length : " << list.length();

	//add an element to the list
	cout << endl << "Inserting 0 at index 0 : ";
	list.insert(0, 0);
	list.display();
	cout << endl << "Inserting 5 at index 5 : ";
	list.insert(5, 5);
	list.display();
	cout << endl << "Inserting 20 at index 2 : ";
	list.insert(2, 20);
	list.display();
	cout << endl << "Inserting 10 at index 10 : ";
	list.insert(10, 10);
	list.display();

	//delete an element from the list
	cout << endl << "Deleting an element at index 0 : ";
	list.delete_element(0);
	list.display();
	cout << endl << "Deleting an element at index 5 : ";
	list.delete_element(5);
	list.display();
	cout << endl << "Deleting an element at index 1 : ";
	list.delete_element(1);
	list.display();
	cout << endl << "Deleting an element at index 10 : ";
	list.delete_element(10);
	list.display();

	return 0;
}
