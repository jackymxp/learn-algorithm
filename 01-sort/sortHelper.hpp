#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <cassert>

using namespace std;

namespace SortHelper{
    int* generateRandomArray(const int len, const int left, const int right)
    {
        int* arr = new int[len];
        srand(time(NULL));
        for(int i = 0; i < len; i++)
        {
            arr[i] = rand() % (right - left + 1) + left;
        }
        return arr;
    }
    template <typename T>
    int* copyArray(T* arr, const int len)
    {
        int* a = new int[len];
        for(int i = 0; i < len; i++)
            a[i] = arr[i];
        return a;
    }
    bool isSorted(const int* arr, const int len)
    {
        for(int i = 1; i < len; i++)
            if(arr[i-1] > arr[i])
                return false;
        return true;
    }
    template<typename T>
    void testSort(string sortName, void(*fun)(T*, const int), T* arr, const int len)
    {
        clock_t start = clock();
        fun(arr, len);
        clock_t end = clock();
        assert(isSorted(arr, len) == true);
        cout << sortName << " cost " << (end - start) / CLOCKS_PER_SEC << " s" << endl;
    }
    template<typename T>
    void printArray(T* arr, const int len)
    {
        cout << "[" ;
        for (int i = 0; i < len; ++i)
        {
            cout << arr[i] << "  ";
        }
        cout << "]" << endl;
    }
}
