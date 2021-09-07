#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
    public:
int data;
node *left;
node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{
    if(Node == NULL)
    return 0;
    int old_val = Node->data;
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
    return Node->data + old_val;
}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout<<" "<<Node->data;
    printInorder(Node->right);
}

/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/* Driver code */
int main()
{
    node *root = NULL;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left = newNode(6);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right = newNode(7);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    toSumTree(root);

    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout<<"Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}
