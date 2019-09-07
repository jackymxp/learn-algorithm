#include "sortHelper.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertSort.hpp"

int main(void)
{
    const int len = 100;
    int* arr1 = SortHelper::generateRandomArray(len, 0, len);
    int* arr2 = SortHelper::copyArray(arr1, len);
    int* arr3 = SortHelper::copyArray(arr1, len);

    SortHelper::testSort("bubbleSort", bubbleSort, arr1, len);
    SortHelper::testSort("selectionSort", selectionSort, arr2, len);
    SortHelper::testSort("insertSort", insertSort, arr3, len);

    return 0;
}