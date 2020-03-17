//============================================================================
// Name        : Stack abstract data type
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : stack adt implemented using linked list
//
//============================================================================
#include <iostream>
using namespace std;

#include "13_linked_list_adt.h"
#include "16_stack_adt.h"

#if 0
/*
 * here base class - linked_list
 * derived class - stack
 */

class stack : public linked_list
{
public:
	stack();
	~stack();

	void push(int x);
	int pop();
	void display(); //function override
};
#endif

stack :: stack()
{
	//parent class (linked list) constructor call is sufficient
}

stack :: ~stack()
{
	//clear memory allotted to all stack elements
		//internally clear all linked list memory allocation
		//parent class (linked list) destructor call is sufficient
}

void stack::push(int x)
{
	//always insert from the front of list
	linked_list :: insert(0, x);
}

int stack::pop()
{
	//always delete element from the front
	return linked_list :: delete_element(0);
}

void stack::display()
{
	linked_list :: display();
}

int main()
{

	stack stk;

	cout << endl << "Stack : push(10)";
	stk.push(10);
	stk.display();
	cout << endl << "Stack : push(20)";
	stk.push(20);
	stk.display();
	cout << endl << "Stack : push(30)";
	stk.push(30);
	stk.display();

	cout << endl << "Stack : pop";
	stk.pop();
	stk.display();
	cout << endl << "Stack : pop";
	stk.pop();
	stk.display();


	cout << endl << "Good Bye !!";
	return 0;
}
