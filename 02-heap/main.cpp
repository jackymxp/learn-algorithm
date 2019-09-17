#include "heap.hpp"

template<typename T>
void heapify(T* arr, const int len, int k)
{
    if(k < len)
    {
        int leftChild = 2 * k + 1;
        int rightChild = 2 * k + 2;
        int max = k;
        if(leftChild < len && arr[max] < arr[leftChild])
            max = leftChild;
        if(rightChild < len && arr[max] < arr[rightChild])
            max = rightChild;
            
        if(max != k)
        {
            swap(arr[max], arr[k]);
            heapify(arr, len, max);
        }
    }
}

template<typename T>
void buildHeap(T* arr, const int len)
{
    for(int i = (len-1)/2; i >=0; i--)
    {
        heapify(arr, len, i);
    }
}



int main(void)
{
    cout << "heap learning..." << endl;
    
    MaxHeap<int>  mp(100);
    int len = 10;
    for(int i = 0; i < len; i++)
    {
        mp.insert(i*2+1);
    }

    
    for(int i = 0; i < len; i++)
    {
        int m = mp.extractMax();
        cout << m << "    ";
    }
    cout << endl;


    int a[] = {2, 3, 6, 8, 1, 5, 7, 9, 4, 10};
    buildHeap(a, len);
    
    for(int i = 0; i < len; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    return 0;
}
