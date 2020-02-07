//============================================================================
// Name        : tower_of_hanoi.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Tower of hanoi problem -
//					where we have to transfer all discs from one tower to other,
//					keeping the original order of the pile.
//Rules:
//1) Only one disk can be moved at a time.
//2) Each move consists of taking the upper disk from one of the stacks and
	//placing it on top of another stack i.e. a disk can only be moved
	//if it is the uppermost disk on a stack.
//3) No disk may be placed on top of a smaller disk.
//============================================================================

#include <iostream>
using namespace std;


/*
 * Tower of Hanoi problem- solving by recursion
 * (Tower 1 - source, Tower 3 - destination, Tower 2 - intermediate tower)
 * 1. Move (n-1) discs from tower 1 to tower 2, via tower 3
 * 2. Move last disc from tower 1 to tower 3
 * 3. Move the (n-1) discs from tower 2 to tower 3, via tower 1
 *
 * S: source tower
 * d: destination tower
 * b: buffer/intermediate tower
 */

void tower_of_hanoi(int n, int s, int d, int b)
{

	if(n == 1)
	{
		cout << "(source, destination) = ( " << s << ", " << d << " )" << endl;
		return;
	}

	//1. Move (n-1) discs from tower 1 to tower 2, via tower 3
	tower_of_hanoi(n-1, s, b, d);
	//2. Move last disc from tower 1 to tower 3
	tower_of_hanoi(1, s, d, b);
	//3. Move the (n-1) discs from tower 2 to tower 3, via tower 1
	tower_of_hanoi(n-1, b, d, s);
}


int main()
{
	//Transfer discs from tower 1 to tower 3 via tower 2
	tower_of_hanoi(3, 1, 3, 2);

	return 0;
}
