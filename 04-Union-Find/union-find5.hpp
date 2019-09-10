#include <iostream>
#include <cassert>

using namespace std;

class UF5
{
public:
    UF5(int n)
    {
        parent = new int[n];
        rank = new int[n];
        count = n;
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UF5()
    {
        delete parent;
        delete rank;
    }
    int find(int p)
    {
        assert(p >= 0 && p < count);
#if 0
        while(p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
        //rec
#else
        if(p != parent[p])
        {
            parent[p] = find(parent[p]);
            return parent[p];
        }  
#endif
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
        if(rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if(rank[pRoot] > rank[qRoot])
            parent[qRoot] = pRoot;
        else
        {
            parent[pRoot] = qRoot;
            rank[qRoot]++;
        }
    }

private:
    int* parent;
    int* rank;
    int count;
};
