#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
node* newNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
bool findPath(node* root, int n, vector<int> &path)
{
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==n)
    {
        return true;
    }
    if ( (root->left && findPath(root->left, n, path)) ||
         (root->right && findPath(root->right, n, path)) )
        return true;
    path.pop_back();
    return false;

}
int LCA(node* root, int n1, int n2)
{
    int i;
    vector<int> path1,path2;
    if(!findPath(root,n1,path1)|| !findPath(root,n2,path2))
        return -1;
    for(i=0;i<path1.size()&&i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<LCA(root,4,6);
    return 0;
}
