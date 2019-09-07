#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
void bubbleSort(T* arr, const int len)
{
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[i])
                swap(arr[i], arr[j]);
        }
    }
}