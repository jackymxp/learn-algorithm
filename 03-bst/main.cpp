#include "BST.hpp"

int main(void)
{
    cout << "test BST" << endl;
    
    BST<int, string> *bst = new BST<int, string>();

    bst->insert(100, "laowang");
    bst->insert(150, "laoli");
    bst->insert(70, "laosong");
    bst->insert(88, "laozhang");

    bst->inOrder();
    return 0;
}
