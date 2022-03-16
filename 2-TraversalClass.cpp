// Preorder traversal using class

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

class binarytree
{
public:
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

    void postordertraversal(node *node)
    {
        if (node != NULL)
        {
            postordertraversal(node->left);
            postordertraversal(node->right);
            cout << node->data << " ";
        }
    }

    void levelordertraversal(node *n)
    {
        if (n == NULL)
            return;
        queue<node *> qnode;
        qnode.push(n);

        while (!qnode.empty())
        {
            node *temp = qnode.front();
            qnode.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                qnode.push(temp->left);
            if (temp->right != NULL)
                qnode.push(temp->right);
        }
    }

    int maxheight(node *n)
    {
        if (n == NULL)
            return 0;

        int l = maxheight(n->left);
        int r = maxheight(n->right);

        return max(l, r) + 1;
    }

    int size(node *n)
    {
        if (n == NULL)
            return 0;
        else
            return (size(n->left) + size(n->right) + 1);
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

    void search(int key,node*root)
    {
        node *n = searchkey(root, key);
        if (n != NULL)
            cout << "Key " << key << "is found" << endl;
        else
            cout << "Key " << key << " is not found" << endl;
    }
};

int main()
{
    binarytree bt;
    node *root = NULL;
    root = new node(5);
    root->left = new node(6);
    root->right = new node(7);

    root->left->left = new node(4);
    root->left->right = new node(3);

    root->right->left = new node(2);
    root->right->right = new node(1);

    cout << "Preorder Traversal = "
         << " ";
    bt.preordertraversal(root);
    cout << endl;

    cout << "inorder Traversal = "
         << " ";
    bt.inordertraversal(root);
    cout << endl;

    cout << "postorder Traversal = "
         << " ";
    bt.postordertraversal(root);
    cout << endl;

    cout << "levelorder Traversal = "
         << " ";
    bt.levelordertraversal(root);
    cout << endl;

    cout << "height= " << bt.maxheight(root) << endl;
    cout << "size= " << bt.size(root) << endl;

    bt.search(43, root);

    return 0;
}