#include "BST.hpp"

int main(void)
{
    cout << "test BST" << endl;
    
    BST<int, string> *bst = new BST<int, string>();

    bst->insert(100, "laowang");
    bst->insert(150, "laoli");
    bst->insert(70, "laosong");
    bst->insert(88, "laozhang");
    cout << bst->contain(88) << endl;
    cout << bst->contain(99) << endl;
    cout << "============preOrder==============" << endl;
    bst->preOrder();
    cout << "============inOrder==============" << endl;
    bst->inOrder();
    cout << "============postOrder==============" << endl;
    bst->postOrder();
    cout << "============levelOrder==============" << endl;
    bst->levelOrder();
    cout << "============minimum==============" << endl;
    cout << bst->minimum() << endl;
    cout << "============maximum==============" << endl;
    cout << bst->maximum() << endl;
    cout << "============floor==============" << endl;
    cout << *bst->floor(75) << endl;
    cout << "============ceil==============" << endl;
    cout << *bst->ceil(75) << endl;

     
    return 0;
}
