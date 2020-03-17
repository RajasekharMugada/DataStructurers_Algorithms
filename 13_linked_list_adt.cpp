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

#include "13_linked_list_adt.h"


linked_list :: linked_list()
{
	first = NULL;
}


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

//sum of all elements in a linked list
int linked_list::sum()
{
	node * p = first;
	int sum = 0;

	while(p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int linked_list::min()
{
	node * p = first;
	int min = INT_MAX;

	while(p != NULL)
	{
		if(min > p->data)
			min = p->data;

		p = p->next;
	}
	return min;
}

int linked_list::max()
{
	node * p = first;
	int max = INT_MIN;

	while(p != NULL)
	{
		if(max < p->data)
			max = p->data;

		p = p->next;
	}
	return max;
}

//Search for a given key
int linked_list::search(int key)
{
	node * p = first;
	int index = 0;

	while(p != NULL)
	{
		if(key == p->data)
			return index;

		p = p->next;
		index++;
	}
	return -1;	//not found
}

bool linked_list::is_sorted()
{
	node * p = first, *q = first; //p, q are current and following node pointers

	if(p == NULL)
		return true;

	p = p->next; //2nd node

	while(p != NULL)
	{
		if(p->data < q->data )
		{
			return false;
		}
		q = p;
		p = p->next;
	}

	return true;
}

//Remove duplcates in the list
void linked_list::remove_duplicates()
{
	node * p, *q;

	if(first == NULL)
		return;

	p = first->next;
	q = first;

	while(p != NULL)
	{
		if(p->data == q->data)
		{
			q->next = p->next;
			delete p;
			p = q->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}

/*
 * Reversing linked list:
 *  Take 3 sliding pointers
 *  Reverse link b/w n1, n2 and point n3 to 3rd node
 *  Move the sliding pointer one step at a time
 */
void linked_list::reverse()
{
	//i/p : n3->n2->n1    o/p: n3<-n2<-n1
	node *n1 = first, *n2 = NULL, *n3 =NULL;

	//1. Initial list:
	// first-> x-> x-> x-> x-> x-> x->NULL

	//2. At any point of time:
	// last <-x <-x <-p  q-> r-> x-> NULL
	while(n1 != NULL)
	{
		//move sliding pointers to next node
		n3 = n2;
		n2 = n1;
		n1 = n1->next;

		//reverse a link
		n2->next = n3;
	}
	//3. last link
	// last <-x <-x <-x <-x <-p <-q  r=(NULL)
	first = n2;
}



//Merging two sorted lists
linked_list * linked_list::merge(linked_list list2)
{
	linked_list * list3 = new(linked_list);
	int k = 0;

	node * p = first, *q = list2.first;

	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			list3->insert(k++, p->data);
			p = p->next;
		}
		else
		{
			list3->insert(k++, q->data);
			q = q->next;
		}
	}
	while(p != NULL)
	{
		list3->insert(k++, p->data);
		p = p->next;
	}
	while(q != NULL)
	{
		list3->insert(k++, q->data);
		q = q->next;
	}
	return list3;
}

/*
 * Merging two sorted lists - in place
 * only links get updated
 */

void linked_list::merge_inplace(linked_list & list2)
{
	node * p = first, *q = list2.first, *r = NULL;


	//first node
	if(p->data <= q->data)
	{
		first = p;
		r = p;		// sorted list
		p = p->next;
	}
	else
	{
		first = q;
		r = q;		// sorted list
		q = q->next;
	}

	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	while(p != NULL)
	{
		r->next = p;
		r = p;
		p = p->next;
	}
	while(q != NULL)
	{
		r->next = q;
		r = q;
		q = q->next;
	}

	r->next = NULL;
}



/*
 * Linked list with a loop - doen not have a last node (next node will never be NULL)
 * Linked list with out loop - always has a last node(with next node is NULL)
 * Take two pointers and increment first one by 1 node and second one by 2 nodes
 *  -if these is no loop then, the two pointers never meet
 *  -if these is a loop the two pointers will meet at some point of time because of LCM principle.
 */
bool linked_list::check_loop()
{
	node *p = first, *q = first;

	while(p != NULL && q != NULL)
	{
		//increment p by one node
		p = p->next;
	    if(q->next == NULL)
	    {
	    	return false; //no loop
	    }
	    //increment q by two nodes
	    q = q->next->next;

	    if(p == q)
	    {
	    	return true; //these is a loop
	    }
	}

	return false; //no loop found
}

/*
 * Find middle element in the list
 * -Take two pointers and at each stage move first pointer by one step,
 *  second pointer by 2 steps
 * -When second pointer reaches last node, first pointer data gives the middle element
 */

int linked_list::middle_element()
{
	node *p, *q;

	if(first == NULL)
	{
		return -1; //list is empty
	}
	else if (first->next == NULL)
	{
		return first->data;
	}

	p = first;
	q = first;

	while(q != NULL && q->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	return p->data;;
}

int main_ll()
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

	//min, max, sum,
	cout << endl << "sum of all elements = " << list.sum();
	cout << endl << "min element in the list = " << list.min();
	cout << endl << "max element in the list = " << list.max();

	//linear search
	cout << endl << "searching for the key = 10, found at index = " << list.search(10);
	cout << endl << "searching for the key = 100, found at index = " << list.search(100);

	list.display();
	//check whether list is sorted or not
	cout << endl << "is listed sorted ? " << list.is_sorted();

	list.insert(list.length(), 8);
	list.insert(list.length(), 8);
	list.insert(list.length(), 8);
	list.insert(list.length(), 10);
	list.insert(list.length(), 15);
	list.insert(list.length(), 15);
	list.display();

	//delete duplicates
	cout << endl << "After removing duplicates : ";
	list.remove_duplicates();
	list.display();

	//reverse list
	cout << endl << "Reversing the list : ";
	list.reverse();
	list.display();

	cout << endl << "List 1: ";
	list.reverse();
	list.display();

	int B[] = {1, 5, 5, 6, 8, 9, 12, 12, 18};
	linked_list list2(B, sizeof(B)/sizeof(B[0]));

	cout << endl << "List 2: ";
	list2.display();

	linked_list * list3;

	//Merging two lists
	cout << endl << "Merging two lists : ";
	list3 = list.merge(list2);
	list3->display();

	cout << endl << "List 1: ";
	list.display();
	cout << endl << "List 2: ";
	list2.display();

	//Merging two lists  - inplace
	cout << endl << "Merging two lists - in place: ";
	list.merge_inplace(list2);
	list.display();

	//check loop in the list
	list.display();
	cout << endl << "checking loop in the list : " << list.check_loop();

	//Middle element in the list
	list.display();
	cout << endl << "Middle element in the list : " << list.middle_element();

	cout << endl << "Good bye !!" ;

	return 0;
}
