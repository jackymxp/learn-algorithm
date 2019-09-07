#include <iostream>

using namespace std;

template<typename Key, typename Value>
class BST
{
private:
    struct TreeNode
    {
        TreeNode* left;
        TreeNode* right;
        Key key;
        Value value;
        TreeNode(Key k, Value v):key(k), value(v), left(NULL), right(NULL)
        {}
    };
    TreeNode* root;
    int count; 
public:
    BST()
    {
        root = NULL;
        count = 0;
    }
    ~BST()
    {
    
    }
    int size(){return size;}
    bool empty(){return size == 0;}
    void insert(Key key, Value value)
    {
        root = insert(root, key, value);
    }
    bool contain(Key key)
    {
        return contain(root, key);
    }
    Value* search(Key key)
    {
        return search(root, key);
    }
    void preOrder()
    {
        preOrderRec(root);
    }
    void inOrder()
    {
        inOrderRec(root);
    }
    void postOrder()
    {
        postOrderRec(root); 
    }
private:
    void preOrderRec(TreeNode* root)
    {
        if(root == NULL)
            return ;
        cout << "key: " <<root->key << "value: " << root->value << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrderRec(TreeNode* root)
    {
        if(root == NULL)
            return ;
        inOrderRec(root->left);
        cout << "key: " <<root->key << "value: " << root->value << endl;
        inOrderRec(root->right);
    }
    void postOrderRec(TreeNode* root)
    {
        if(root == NULL)
            return ;
        postOrderRec(root->left);
        postOrderRec(root->right);
        cout << "key: " <<root->key << "value: " << root->value << endl;
    }
    Value* search(TreeNode* root, Key key)
    {
        if(root == NULL)
            return NULL;
        if(root->key == key)
            return &(root->value);
        else if(root->key > key)
            return search(root->left, key);
        else if(root->key < key)
            return search(root->right, key);
        return NULL;
    }
    TreeNode* insert(TreeNode* root, Key key, Value value)
    {
        if(root == NULL)
        {
            count++;
            return new TreeNode(key, value);
        }
        if(root->key == key)
            root->value = value;
        else if(root->key > key)
            root->left = insert(root->left, key, value);
        else if(root->key < key)
            root->right = insert(root->right, key, value);
        return root;
    }

    bool contain(TreeNode* root, Key key)
    {
        if(root == NULL)
            return false;
        if(root->key == key)
            return true;
        else if(root->key > key)
            return contain(root->left, key);
        else if(root->key < key)
            return contain(root->right, key);
        return false;
    }
};
