#include "sparseGraph.hpp"
#include "denseGraph.hpp"
#include "readGraph.hpp"
#include "components.hpp"


int main(void)
{
    cout << "learn  graph...." << endl;

    string fileg1 = "testG1.txt";
    SparseGraph sg(13, false);  
    ReadGraph<SparseGraph> readG1(sg, fileg1);
//    cout << sg << endl;
    sg.show();

    string fileg2 = "testG2.txt";
    DenseGraph dg(6, false);  
    ReadGraph<DenseGraph> readG2(dg, fileg2);
    dg.show();
//    cout << dg << endl;

    Component<SparseGraph> cg1(sg);
    cout << cg1.count() << endl;
    
    Component<DenseGraph> dg1(dg);
    cout << dg1.count() << endl;
    return 0;
}
