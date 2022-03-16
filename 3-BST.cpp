// To implement binary search tree

// if deleting a node with two children either return max node from left or minimum node from right

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node
{
    int data;
    node *left;
    node *right;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node *root = NULL;

node *insertnode(node *n, int key)
{
    if (n == NULL)
    {
        n = createnode(key);
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

void preorderTraversal(node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
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
        cout << "Key " << key << "is found" << endl;
    else
        cout << "Key " << key << " is not found" << endl;
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

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        addnode(ele);
    }

    cout << "Preorder=  \n";
    preorderTraversal(root);
    cout<<endl;

    search(5);
    cout<<endl;

    deletenode(5);

    search(5);
    cout<<endl;

    return 0;
}