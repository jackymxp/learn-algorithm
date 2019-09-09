#include <iostream>

using namespace std;

class UF1{
public:
    UF1(int n)
    {
        count = n;
        id = new int[n];
        for(int i = 0; i < n; i++)
            id[i] = i;
    }
    ~UF1()
    {
        delete id;
    }
    int find(int p)
    {
        assert(p >= 0 && p < count);
        return id[p];
    }
    bool isConnect(int p, int q)
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        assert(p >= 0 && p < count);
        assert(q >= 0 && q < count);
        int pID = id[p];
        int qID = id[q];
        if(qID == pID)
            return ;
        for(int i = 0; i < count; i++)
        {
            if(id[i] == pID)
                id[i] = qID;
        }
    }
private:
    int* id;
    int count;
};
