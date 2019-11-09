/*
@author: Rajasekhar Mugada
@brief : Function overloading example
*/

#include <iostream>
using namespace std;

int add(int a, int b);
int add(int a, int b)
{
    return a+b;
}

int add(int a, int b, int c);
int add(int a, int b, int c)
{
    return a+b+c;
}

float add(float a, float b);
float add(float a, float b)
{
    return a+b;
}

/*
//Following code makes name-conflict for fn. overloading since
//input arg. data types are same as fn. int add(int a, int b);
float add(int a, int b)
{
    return a+b;
}
*/


int main()
{
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    //Implicitly specify the data type as float, otherwise
    //default type is double
    cout << add(1.5f, 2.0f) << endl;
    return 0;
}
