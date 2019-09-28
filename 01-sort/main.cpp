#include "sortHelper.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertSort.hpp"
#include "quickSort.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"

int main(void)
{
    const int len = 9999;
    int* arr1 = SortHelper::generateRandomArray(len, 0, len);
    int* arr2 = SortHelper::copyArray(arr1, len);
    int* arr3 = SortHelper::copyArray(arr1, len);
    int* arr4 = SortHelper::copyArray(arr1, len);
    int* arr5 = SortHelper::copyArray(arr1, len);
    int* arr6 = SortHelper::copyArray(arr1, len);
    int* arr7 = SortHelper::copyArray(arr1, len);
    int* arr8 = SortHelper::copyArray(arr1, len);
    
    //SortHelper::testSort("bubbleSort", bubbleSort, arr1, len);
    //SortHelper::testSort("selectionSort", selectionSort, arr2, len);
    //SortHelper::testSort("insertSort", insertSort, arr3, len);
    SortHelper::testSort("quickSort", quickSort, arr4, len);
    SortHelper::testSort("quickSort3Ways", quickSort3Ways, arr5, len);
    SortHelper::testSort("mergeSort", mergeSort, arr6, len);
    SortHelper::testSort("mergeSortBU", mergeSortBU, arr7, len);
    SortHelper::testSort("heapSort", heapSort, arr8, len);
   
    delete arr1;   
    delete arr2;   
    delete arr3;   
    delete arr4;   
    delete arr5;   
    delete arr6;   
    delete arr7;   
    delete arr8;   
   
    return 0;
}
