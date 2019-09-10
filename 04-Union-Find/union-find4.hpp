#include <iostream>
#include <cassert>

using namespace std;

class UF4{
public:
    UF4(int n)
    {
        parent = new int[n];
        rank = new int[n];
        count = n;
        for(int i = 0;i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UF4()
    {
        delete parent;
        delete rank;
    }
    int find(int p)
    {
        assert(p>=0 && p<count);
        while(p!=parent[p])
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
        if(rank[pRoot] < rank[qRoot])
        {
            parent[pRoot] = qRoot;

        }
        else if(rank[pRoot] > rank[qRoot])
        {
            parent[qRoot] = pRoot;
        }
        else
        {
            parent[pRoot] = qRoot;
            rank[qRoot]++;
        }
    }



private:
    int* parent;//
    int* rank;
    int count;
};
