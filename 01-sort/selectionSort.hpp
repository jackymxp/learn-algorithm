#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
void selectionSort(T* arr, const int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for(int j = i+1; j < len; j++)
            if(arr[j] < arr[min])
                min = j;
        swap(arr[min], arr[i]);
    }
}