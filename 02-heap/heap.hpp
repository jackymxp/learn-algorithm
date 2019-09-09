#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap
{
public:
    MaxHeap(int cap = 10)
    {
        data = new T[cap+1];
        count = 0;
        capacity = cap;
    }
    ~MaxHeap()
    {
        delete data;
    }
    int size(){return count;}
    bool empty(){return count == 0;}
    
    void insert(T e)
    {
        assert(count < capacity);
        data[count] = e;
        shiftUp(count);
        count++;
    }
    T extractMax()
    {
        assert(count > 0);
        T ret = data[0];
        swap(data[0], data[count-1]);
        count--;
        shiftDown(0);
        return ret;
    }
private:
    //parent = (child-1)/2
    void shiftUp(int k )
    {
        while(k > 0 && data[k] > data[(k-1)/2])
        {
            swap(data[k], data[(k-1)/2]);
            k = (k-1)/2;
        }
    }

    void shiftDown(int k )
    {
       while(2*k+1 < count)
       {
            int maxChild = 2*k+1;
            if(maxChild+1 < count && data[maxChild+1] > data[maxChild])
                maxChild++;
            if(data[k] < data[maxChild])
            {
                swap(data[k], data[maxChild]);
                k = maxChild;
            }
            else
                break;
       }
    }
    T* data;
    int count;
    int capacity;
};
