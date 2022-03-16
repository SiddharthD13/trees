#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class bst
{
public:
    node *root;

    bst()
    {
        root = NULL;
    }

    node *insertnode(node *n, int key)
    {
        if (n == NULL)
        {
            n = new node(key);
            return n;
        }
        if (key < n->data)
            n->left = insertnode(n->left, key);
        else if (key > n->data)
            n->right = insertnode(n->right, key);

        return n;
    }

    void addnode(int key)
    {
        root = insertnode(root, key);
    }

    void preordertraversal(node *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preordertraversal(node->left);
            preordertraversal(node->right);
        }
    }

    void inordertraversal(node *node)
    {
        if (node != NULL)
        {
            inordertraversal(node->left);
            cout << node->data << " ";
            inordertraversal(node->right);
        }
    }

    node *searchkey(node *n, int key)
    {
        if (n == NULL || n->data == key)
            return n;

        if (key < n->data)
            return searchkey(n->left, key);
        else
            return searchkey(n->right, key);
    }

    void search(int key)
    {
        node *n = searchkey(root, key);
        if (n != NULL)
            cout << "Key " << key << " is found" << endl;
        else
            cout << "Key " << key << " is not found" << endl;
    }

    int minimumVal(node *n)
    {
        int minival = n->data;
        while (n->left != NULL)
        {
            minival = n->left->data;
            n = n->left;
        }
        return minival;
    }

    node *deletenoderec(node *n, int key)
    {
        if (n == NULL)
            return n;
        if (key < n->data)
            n->left = deletenoderec(n->left, key);
        else if (key > n->data)
            n->right = deletenoderec(n->right, key);
        else
        {
            if (n->left == NULL)
                return n->right; // for single child
            else if (n->right == NULL)
                return n->left; // for single child

            n->data = minimumVal(n->right);
            n->right = deletenoderec(n->right, n->data);
        }
    }
    void deletenode(int key)
    {
        root = deletenoderec(root, key);
    }
};

int main()
{
    bst bt;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        bt.addnode(ele);
    }

    cout << "Preorder Traversal = "
         << " ";
    bt.preordertraversal(bt.root);
    cout << endl;

    bt.search(100);
    bt.deletenode(100);
    bt.search(100);
    return 0;
}