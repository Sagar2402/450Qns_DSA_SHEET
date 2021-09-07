#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *left, *right;
};

node* mirror(node *root)
{
    if(root==NULL)
    {
        return root;
    }
    node* temp=new node;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
    return root;

}
node* newNode(int ele)
{
    node *temp=new node;
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inorder(root);
    cout<<endl;
    root=mirror(root);
    inorder(root);
    cout<<endl;
    return 0;
}
