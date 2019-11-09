/*
@author: Rajasekhar Mugada
@brief : template function/ generic function
*/

#include <iostream>
using namespace std;

template <class T>
T max_num(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    cout << max_num(1, 2) << endl;
    cout << max_num(1.0f, 2.5f) << endl;

    return 0;
}
