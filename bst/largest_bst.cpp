#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
node* createNode(int key)
{
    node *temp;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main()
{
    node* root;
    root=createNode(6);
    root->left=createNode(6);
    root->left->right=createNode(2);
    root->left->right->right=createNode(8);
    root->right=createNode(3);
    root->right->right=createNode(3);
    root->right->left=createNode(9);
    root->right->left->left=createNode(8);
    root->right->left->right=createNode(2);

    return 0;
}
