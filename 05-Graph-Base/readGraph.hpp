#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

using namespace std;

template<typename G>
class ReadGraph
{
public:
    ReadGraph(G& graph, string filepath)
    {
        ifstream file(filepath);
        string line;
        int V, E;
        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> V >> E;
        assert(graph.V() == V);

        //read edge info
        for(int i = 0; i < E; i++)
        {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b);
        }
    }

private:
};
