#include <iostream>
#include <queue>
#include <cassert>

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
        destroy(root); 
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
    void levelOrder()
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                cout << "key: " <<node->key << "value: " << node->value << endl;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
    }
    Key minimum()
    {
        assert(count > 0);
        return minimum(root)->key;
    }
    Key maximum()
    {
        assert(count > 0);
        return maximum(root)->key;
    }
    void removeMin()
    {
        root = removeMin(root);
    }
    void removeMax()
    {
        root = removeMax(root);
    }
    void remove(Key key)
    {
        root = remove(root, key);
    }
    Key* floor(Key key)
    {
        if(count <= 0 || key < minimum())
            return NULL;
        TreeNode* node = floor(root, key);
        return &(node->key);
    }
    Key* ceil(Key key)
    {
        if(count <= 0 || key > maximum())
            return NULL;
        TreeNode* node = ceil(root, key);
        return &(node->key);
    }
private:
    TreeNode* ceil(TreeNode* root, Key key)
    {
        if(root == NULL)
            return NULL;
        if(root->key == key)
            return root;
        if(root->key < key)
            return ceil(root->right, key);
        TreeNode* tmpNode = ceil(root->left, key);
        if(tmpNode != NULL)
            return tmpNode;
        return root;
    }

    TreeNode* floor(TreeNode* root, Key key)
    {
        if(root == NULL)
            return NULL;
        if(root->key == key)
            return root;
        if(root->key > key)
            return floor(root->left, key);
        
        TreeNode* tmpNode = floor(root->right, key);
        if(tmpNode != NULL)
            return tmpNode;
        return root;
    }
    TreeNode* remove(TreeNode* root, Key key)
    {
        if(root == NULL)
            return NULL;
        if(root->key < key)
        {
            root->right = remove(root->right, key);
            return root;
        }
        else if(root->key > key)
        {
            root->left = remove(root->left, key);
            return root;
        }
        else if(root->key == key)
        {
            if(root->left == NULL)
            {
                TreeNode* rightChild = root->right;
                delete root;
                count--;
                return rightChild;
            }
            else if(root->right == NULL)
            {
                TreeNode* leftChild = root->left;
                delete root;
                count--;
                return leftChild;
            }
            else
            {
                //find right child min node
                TreeNode* minNode = minimum(root->right);
                //delete right child min node
                removeMin(root->right);
                minNode->left = root->left;
                minNode->right = root->right;
                delete root;
                count--;
            }
        }
    }
    
    TreeNode* removeMax(TreeNode* root)
    {
        if(root->right == NULL)
        {
            TreeNode* leftChild = root->left;
            delete root;
            count--;
            return leftChild;
        }
        root->right = removeMax(root->right);
        return root;
    }
    TreeNode* removeMin(TreeNode* root)
    {
        if(root->left == NULL)
        {
            TreeNode* rightChild = root->right;
            delete root;
            count--;
            return rightChild;
        }
        root->left = removeMin(root->left);
        return root;
    }
    TreeNode* maximum(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        return maximum(root->right);
    }
    TreeNode* minimum(TreeNode* root)
    {
        if(root->left == NULL)
            return root;
        return minimum(root->left);
    }
    void destroy(TreeNode* root)
    {
        if(root == NULL)
            return ;
        destroy(root->left);
        destroy(root->right);
        delete root;
        count--;
    }
    void preOrderRec(TreeNode* root)
    {
        if(root == NULL)
            return ;
        cout << "key: " <<root->key << "value: " << root->value << endl;
        preOrderRec(root->left);
        preOrderRec(root->right);
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
