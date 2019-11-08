/*
@author: Rajasekhar Mugada
@brief : Linear search algorithm
*/

#include <iostream>
using namespace std;

//Linear search algorithm
//Time complexity : O(n)
int linear_search(int * arr, int len, int key)
{
    int position = -1; //not found

    for(int i =0; i < len; i++)
    {
        if(arr[i] == key)
        {
            return position = i;
        }
    }
    return position;
}


int main ()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    int pos = linear_search(a, sizeof(a)/sizeof(int), 3);
    cout << "key found at array index : "<< pos;

    return 0;
}
