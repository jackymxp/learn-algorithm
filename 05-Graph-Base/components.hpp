#include <iostream>
#include <cassert>

using namespace std;

template<typename G>
class Component
{
public:
    Component(G& g):g(g)
    {
        visited = new bool[g.V()];
        id = new int[g.V()];
        ccount=0;
        for(int i = 0; i < g.V(); i++)
        {
            visited[i] = false;
            id[i] = -1;
        }
    
        for(int i = 0; i < g.V(); i++)
        {
            if(!visited[i])
            {
                dfs(i);
                ccount++;
            }
        }
    }
    ~Component()
    {
        delete id;
        delete visited;
    }
    int count(){return ccount;}
    bool isConnect(int a, int b)
    {
        assert(a >= 0 && a < g.V());
        assert(b >= 0 && b < g.V());
        return id[a] == id[b];
    }
private:
    G& g;
    bool *visited;
    int ccount;
    int* id;
    void dfs(int v)
    {
        visited[v] = true;
        id[v] = ccount;
        typename G::adjIterator adj(g, v);
        for(int i = adj.begin(); !adj.end(); i = adj.next())
        {
            if(!visited[i])
                dfs(i);
        }
    }
};
