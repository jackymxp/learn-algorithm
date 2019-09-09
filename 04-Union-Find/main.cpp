#include "union-find-test.hpp"


int main(void)
{
    int len = 100000;
    
    UnionFindTestHelper::testUF1(len);
    cout << "test UF1 over..." << endl;

    UnionFindTestHelper::testUF2(len);
    cout << "test UF2 over..." << endl;
    
    UnionFindTestHelper::testUF3(len);
    cout << "test UF3 over..." << endl;
    return 0;
}
