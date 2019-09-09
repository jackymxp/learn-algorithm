#include <iostream>
#include <ctime>
#include <cassert>

#include "union-find1.hpp"
#include "union-find2.hpp"
#include "union-find3.hpp"


namespace UnionFindTestHelper
{

    void testUF1(const int len)
    {
        srand(time(NULL));
        UF1 uf = UF1(len);
        time_t start = clock();
        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.unionElement(p, q);
        }

        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.isConnect(p, q);
        }
        time_t end = clock();
        cout << "test " << len << "cost " << (end-start)/CLOCKS_PER_SEC << " s" << endl;
   }
    void testUF2(const int len)
    {
        srand(time(NULL));
        UF2 uf = UF2(len);
        time_t start = clock();
        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.unionElement(p, q);
        }

        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.isConnect(p, q);
        }
        time_t end = clock();
        cout << "test " << len << "cost " << (end-start)/CLOCKS_PER_SEC << " s" << endl;
   }
   
    void testUF3(const int len)
    {
        srand(time(NULL));
        UF3 uf = UF3(len);
        time_t start = clock();
        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.unionElement(p, q);
        }

        for(int i = 0; i < len; i++)
        {
            int q = rand() % len;
            int p = rand() % len;
            uf.isConnect(p, q);
        }
        time_t end = clock();
        cout << "test " << len << "cost " << (end-start)/CLOCKS_PER_SEC << " s" << endl;
   }
}
