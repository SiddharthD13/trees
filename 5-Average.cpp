//You are given a binary tree, you need to print the average of each level of the tree.

/*Start by pushing the root node into the queue. Then, remove a node from the front of the queue.
For every node removed from the queue, push all its children into a new temporary queue.
Keep on popping nodes from the queue and adding these node’ s children to the temporary queue till queue becomes empty.
Every time queue becomes empty, it indicates that one level of the tree has been considered.
While pushing the nodes into temporary queue, keep a track of the sum of the nodes along with the number of nodes pushed and 
find out the average of the nodes on each level by making use of these sum and count values.
After each level has been considered, again initialize the queue with temporary queue and continue the process till both queues become empty. */

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


void findAverageLevel(node* a)
{
  queue<node*>q;
  q.push(a);
  
  while(!q.empty())
  {
    // Compute sum of nodes and
    // count of nodes in current
    // level.
    
    int sum=0,count=0;
    queue<node*>temp;

    while(!q.empty())
    {
        node*n=q.front();
        q.pop();
        sum+=n->value;
        count++;

        if(n->left!=NULL) temp.push(n->left);
        if(n->right!=NULL) temp.push(n->right);
    }
    q=temp;
    cout<<(sum*1.0/count)<<" ";
  }
}

/*Write a function that returns true if the given Binary Tree is SumTree else false. 
A SumTree is a Binary Tree where the value of a node is equal to the
sum of the nodes present in its left subtree and right subtree. 
An empty tree is SumTree and the sum of an empty tree can be considered as 0.
A leaf node is also considered as SumTree. */

int sum(node*n)
{
  if(n==NULL) return 0;

  return sum(n->left)+n->value+sum(n->right);
}

bool checkSumTree(node* n)
{
   int ls,rs;

   //if node is NULL or its a leaf
   //node then return true

   if( n==NULL || (n->left==NULL && n->right==NULL)) return 1;

  // Get sum of nodes in left and
  // right subtrees
   ls = sum(n->left);
   rs = sum(n->right);

   
   // If the node and both of its
   // children satisfy the property
   // return 1 else 0

   if((n->value==ls + rs) && checkSumTree(n->left) && checkSumTree(n->right)) return 1;

   return 0;
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

    if(checkSumTree(root)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


