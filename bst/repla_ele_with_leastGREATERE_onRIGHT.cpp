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
    node* temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insert(node* root,int arr[], int i, int present)
{
    if(root==NULL)
    {
        node *n=createNode(arr[i]);
        //cout<<n->data<<endl;
        arr[i]=present;
        return n;
    }
    if(arr[i]<root->data)
    {
        root->left=insert(root->left,arr,i,root->data);
    }
    if(arr[i]>root->data)
    {
        root->right=insert(root->right,arr,i,present);
    }
    return root;
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
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    node* root=NULL;
    for(i=n-1;i>=0;i--)
    {
        cout<<arr[i]<<endl;
        root=insert(root,arr,i,-1);
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}
/*
15
8 58 71 18 31 32 63 92 43 3 91 93 25 80 28
*/
