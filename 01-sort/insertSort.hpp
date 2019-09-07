#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
void insertSort(T* arr, const int len)
{
    for (int i = 1; i < len; i++)
    {
        T tmp = arr[i];
        int  j = i;
        for(j = i-1; j >= 0; j--)
        {
            if(arr[j] > tmp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = tmp;
    }
}