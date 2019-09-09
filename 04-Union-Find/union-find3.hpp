#include <iostream> 
#include <cassert>

using namespace std;


class UF3
{
public:
    UF3(int n)
    {
        count = n;
        parent = new int[n];
        size = new int[n];
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int p)
    {
        assert(p >= 0 && p < count);
        while(p != parent[p])
            p = parent[p];
        return p;
    }

    bool isConnect(int p, int q)
    {
        return find(p) == find(q);
    }
    
    void unionElement(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot)
            return ;
        if(size[pRoot] < size[qRoot])
        {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
        else
        {
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }
        
    }
private:
    int* parent;
    int* size;
    int count;
};
