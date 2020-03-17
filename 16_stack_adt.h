/*
 * 17_stack_adt.h
 *
 *  Created on: 17-Mar-2020
 *      Author: rajasm
 */

#ifndef _16_STACK_ADT_H_
#define _16_STACK_ADT_H_

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


#endif /* 17_STACK_ADT_H_ */
