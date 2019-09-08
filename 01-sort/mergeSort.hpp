#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;


template <typename T>
static void merge(T* arr, const int left, const int mid, const int right)
{
   T aux[right - left + 1];
   for(int i = left; i <= right; i++)
       aux[i-left] = arr[i];
    int i = left;
    int j = mid+1;
    for(int k = left; k <= right; k++)
    {
        if(i > mid)
        {
            arr[k] = aux[j-left];
            j++;
        }
        else if(j > right)
        {
            arr[k] = aux[i-left];
            i++;
        }
        else if(i <= mid && aux[i-left] < aux[j-left])
        {
            arr[k] = aux[i-left];
            i++;
        }
        else
        {
            arr[k] = aux[j-left];
            j++;
        }
    }
}

template <typename T>
static void mergeSort(T* arr, const int left, const int right)
{
    if(left >= right)
        return;
    int mid = (right - left) / 2 + left;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

template <typename T>
static void mergeSort(T* arr, const int len)
{
    mergeSort(arr, 0, len-1);
}


template <typename T>
void mergeSortBU(T* arr, const int len)
{
    for(int size = 1; size < len; size += size)
    {
        for(int i = 0; i < len-size; i += (size+size))
        {
            if(arr[i+size-1] > arr[i+size])
                merge(arr, i, i+size-1, min(len-1, i+size+size-1));
        }
    }

    
}


