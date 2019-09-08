#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <time.h>

using namespace std;

template<typename T>
void shift(T* arr, int k, int len)
{
    while(2*k+1 <= len)
    {
        int maxChild = 2*k+1;
        if(maxChild+1 <= len && arr[maxChild+1] > arr[maxChild])
            maxChild++;
        if(arr[maxChild] > arr[k])
        {
            swap(arr[maxChild], arr[k]);
            k = maxChild;
        }
        else
            break;
    }
}

template<typename T>
void heapSort(T* arr, const int len)
{
    //build heap
    for(int i = (len-1) / 2; i >= 0; i--)
        shift(arr, i, len - 1);

    for(int i = len - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        shift(arr, 0, i-1);
    }
}
