#include <iostream>
using namespace std;

//Binary search algorithm for a sorted array
int binary_search(int * array, int len, int key)
{
    int left = 0, right = 0, middle = 0;
    int position = -1; //not found

    left = 0;
    right = len -1;

    while(left <= right)
    {
        middle = (left + right)/2;

        if(key < array[middle])
        {
            right = middle -1;
        }
        else if(key > array[middle])
        {
            left = middle +1;
        }
        else
        {
            return position = middle;
        }
    }

    return position;
}


int main ()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    int pos = binary_search(a, sizeof(a)/sizeof(int), 3);

    cout << pos;

    return 0;
}
