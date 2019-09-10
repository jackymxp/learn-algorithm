#include <iostream>
#include <vector>
#include <cassert>
#include <ostream>

using namespace std;
//linjiebiap
class SparseGraph
{
public:
    SparseGraph(int v, bool dir)
    {
        this->v = v;
        this->e = 0;
        this->directed = dir;
        g = vector<vector<int>>(v, vector<int>());
    }
   int V() {return v;}
   int E() {return e;}
   //add  a--->b edge
   void addEdge(int a, int b)
   {
        assert(a >= 0 && a < v);
        assert(b >= 0 && b < v);
        g[a].push_back(b);
        if(!directed)
            g[b].push_back(a);
        e++;
   }
   // has edge a--->b
   bool hasEdge(int a, int b)
   {
        assert(a >= 0 && a < v);
        assert(b >= 0 && b < v);
        for(auto i : g[a])
            if(i == b)
                return true;
        return false;
   }
   class adjIterator
   {
   public:
        adjIterator(SparseGraph& graph, int v):G(graph), v(v), index(0)
        {}
        ~adjIterator(){}
        int begin()
        {
            index = 0;
            if(G.g[v].size())
                return G.g[v][0];
            return -1;
        }
        int next()
        {
            index++;
            if(index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }
        bool end()
        {
            return index >= G.g[v].size();
        }

    
    private:
        SparseGraph& G;
        int v;
        int index;
   };
   void show()
   {
        cout << "====SparseGraph====" << endl;
        cout << "V = " << v  << "    E = " << e << endl;
        for(int i = 0; i < v; i++)
        {
            cout << "vertex " << i << ":\t";
            for(int j = 0; j < g[i].size(); j++)
                cout << g[i][j] << "\t";
            cout << endl;
        }
   }
friend ostream& operator<<(ostream& os, SparseGraph& G);
private:
    int v, e;
    bool directed;
    vector<vector<int>> g;
};


#if 1 
ostream& operator<<(ostream& os, SparseGraph& G)
{
    os << "====SparseGraph====" << endl;
    os << "V = " << G.V() << "    E = " << G.E() << endl;
    for(int i = 0; i < G.V(); i++)
    {
        os << "vertex :" << i << ":\t";
        for(int j = 0; j < G.g[i].size(); j++)
        {
            os << G.g[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

#endif
