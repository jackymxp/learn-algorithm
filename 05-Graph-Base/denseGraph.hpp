#include <iostream>
#include <vector>
#include <cassert>
#include <ostream>

using namespace std;

class DenseGraph
{
public:
    DenseGraph(int v, bool dir)
    {
        assert(v >= 0);
        this->v = v;
        this->e = 0;
        this->directed = dir;
        g = vector<vector<bool>>(v, vector<bool>(v, false));
    }
    
    ~DenseGraph()
    {}
    
    int V() {return v;}
    int E() {return e;}
    
    //add a--->b
    void addEdge(int a, int b)
    {
        assert(a >= 0 && a < v);
        assert(b >= 0 && b < v);
        if(hasEdge(a, b) == true)
            return;
        g[a][b] = true;
        if(!directed)
            g[b][a] = true;
        e++;
    }

    //has edge  a--->b
    bool hasEdge(int a, int b)
    {
        assert(a >= 0 && a < v);
        assert(b >= 0 && b < v);
        return g[a][b];
    }
    class adjIterator
    {
    public:
        adjIterator(DenseGraph& graph, int v):G(graph), v(v), index(0) 
       {}
        ~adjIterator(){}
        int begin()
        {
            index = -1;
            return next();
        }
        int next()
        {
            for(index +=1; index < G.V(); index++)
                if(G.g[v][index] == true)
                    return index;
            return -1;
        }
        bool end()
        {
            return index >= G.V();
        }
    private:
        DenseGraph& G;
        int v;
        int index;
    };
    void show()
    {
        cout << "====DenseGraph====" << endl;
        cout << "V = " << v << "    E = " << e << endl;
        for(auto v : g)
        {
            for(auto i : v)
                cout << i << "\t";
            cout << endl;
        }
    }
friend ostream& operator<<(ostream& os, DenseGraph& G);
private:
    int v, e;
    bool directed;
    vector<vector<bool>> g;
};

#if 0
ostream& operator<<(ostream& os, DenseGraph& G)
{
    os << "====DenseGraph====" << endl;
    os << "V = " << G.V() << "    E = " << G.E() << endl;
    for(auto v : G.g)
    {
        for(auto i : v)
            os << i << "\t";
        os << endl;
    }

}
#endif
