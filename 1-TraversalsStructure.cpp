// Preorder traversal using structure

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node
{
    int value;
    node *left;
    node *right;
} node;

node *root = NULL;
node *createnode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void preOrderTraversal(node *node) //ROOT LEFT RIGHT
{
    if (node != NULL)
    {
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void inordertraversal(node *node)  // LEFT ROOT RIGHT
{
    if (node != NULL)
    {
        inordertraversal(node->left);
        cout << node->value << " ";
        inordertraversal(node->right);
    }
}

void postOrderTraversal(node *node)  //LEFT RIGHT ROOT
{
    if (node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value<< " ";
    }
}

void levelOrderTraversal(node *t)
{
    if (t == NULL)
        return;
    queue<node *> qnode;
    qnode.push(t);

    while (!qnode.empty())
    {
        node *temp = qnode.front();
        qnode.pop();
        cout << temp->value << " ";
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
    if (n == NULL || n->value == key)
        return n;

    if (key < n->value)
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

int main()
{
    root = createnode(7);
    root->left = createnode(5);
    root->right = createnode(11);

    root->left->left = createnode(3);
    root->left->right = createnode(6);

    root->right->left = createnode(8);
    root->right->right = createnode(15);

    cout << "Preorder Traversal = "
         << " ";
    preOrderTraversal(root);
    cout << endl;

    cout << "inorder Traversal = "
         << " ";
    inordertraversal(root);
    cout << endl;
    cout << "postorder Traversal = "
         << " ";
    postOrderTraversal(root);
    cout << endl;

    cout << "level order Traversal = "
         << " ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "height= " << maxheight(root) << endl;
    cout << "size= " << size(root) << endl;


    search(7);
    search(34);
  

    return 0;
}
