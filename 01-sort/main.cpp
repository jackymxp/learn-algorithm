#include "sortHelper.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertSort.hpp"
#include "quickSort.hpp"
int main(void)
{
    const int len = 100;
    int* arr1 = SortHelper::generateRandomArray(len, 0, len);
    int* arr2 = SortHelper::copyArray(arr1, len);
    int* arr3 = SortHelper::copyArray(arr1, len);
    int* arr4 = SortHelper::copyArray(arr1, len);
    int* arr5 = SortHelper::copyArray(arr1, len);
    SortHelper::testSort("bubbleSort", bubbleSort, arr1, len);
    SortHelper::testSort("selectionSort", selectionSort, arr2, len);
    SortHelper::testSort("insertSort", insertSort, arr3, len);
    SortHelper::testSort("quickSort", quickSort, arr4, len);
    SortHelper::testSort("quickSort3Ways", quickSort3Ways, arr5, len);
    return 0;
}
