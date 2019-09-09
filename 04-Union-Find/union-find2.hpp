#include <iostream>
#include <cassert>

using namespace std;

class UF2{
public:
    UF2(int n)
    {
        count = n;
        parent = new int[n];
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    ~UF2()
    {
        delete parent;
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
        parent[pRoot] = qRoot;
    }

private:
    int* parent;
    int count;
};
