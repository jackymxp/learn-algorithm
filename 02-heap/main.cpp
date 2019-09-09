#include "heap.hpp"


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
    return 0;
}
