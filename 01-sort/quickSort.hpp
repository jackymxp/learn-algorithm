#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <time.h>

using namespace std;

template <typename T>
int __partition1(T* arr, const int left, const int right)
{
    T v = arr[left];//选定基准
    //arr[left+1, i) < v
    //arr[left+1, p] < v
    int p = left;
    for(int i = left + 1; i <= right; i++)
    {
        if(arr[i] < v)
        {
            p++;
            swap(arr[i], arr[p]);
        }
    }
    swap(arr[left], arr[p]);
    return p;
}

template <typename T>
int __partition2(T* arr, const int left, const int right)
{
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    //arr[left, i) < v
    //arr(j, right] >= v
    int i = left+1, j = right;
    while(1)
    {
        while(i <= right && arr[i] < v)
            i++;
        while(j >= left+1 && arr[j] > v)
            j--;
        if(i > j)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[left], arr[j]);
    return j;
}


template <typename T>
void __quickSort(T* arr, const int left, const int right)
{
    if(left > right)
        return;
    //int p = __partition1(arr, left, right);
    int p = __partition2(arr, left, right);
    __quickSort(arr, left, p - 1);
    __quickSort(arr, p + 1, right);
}

template <typename T>
void quickSort(T* arr, const int len)
{
    srand(time(NULL));
    __quickSort(arr, 0, len - 1);
}


template <typename T>
void __quickSort3Ways(T* arr, const int left, const int right)
{
    if(left >= right)
        return ;
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    //arr[left+1, lt] < v
    //arr[lt+1, i) == v
    //arr[gt, right] > v
    int lt = left; 
    int gt = right+1;
    for(int i = left+1; i < gt; )
    {
        if(arr[i] == v)
        {
            i++;                
        }
        else if(arr[i] < v)
        {
            swap(arr[i], arr[lt+1]);
            i++;
            lt++;
        }
        else if(arr[i] > v)
        {
            swap(arr[i], arr[gt-1]);
            gt--;
        }
    }
    swap(arr[left], arr[lt]);
    __quickSort3Ways(arr, left, lt);
    __quickSort3Ways(arr, gt, right);
}


template <typename T>
void quickSort3Ways(T* arr, const int len)
{
    __quickSort3Ways(arr, 0, len - 1);
}


