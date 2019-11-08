/*
@author: Rajasekhar Mugada
@brief : Reverse a number
*/

#include <iostream>
using namespace std;

unsigned int revese_number(unsigned int n)
{
    int rev_num = 0;
    int r = 0;  //remainder

    while(n > 0)
    {
        r = n%10; //Find least significant digit
        n /= 10;

        rev_num = rev_num*10 + r;
    }
    return rev_num;
}

int main()
{
    int n = 153;
    int rev = 0;

    rev = revese_number(n);
    cout << "number : " << n << " reverse number : " << rev;
}
