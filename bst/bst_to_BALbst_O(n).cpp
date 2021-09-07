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
    temp->left=NULL;
    temp->right=NULL;
    temp->data=key;
    return temp;
}
node* insert(node* root, int key)
{
    if(root==NULL)
        return createNode(key);
    if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    if(key>root->data)
    {
        root->right=insert(root->right,key);
    }
    return root;
}
int getcnt(node *root)
{
    node* curr=root;
    stack<node *> s;
    int cnt=0;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cnt++;
        curr=curr->right;
    }
    return cnt;
}
node* createBalTree(node* root, int l , int h, int arr[])
{
    if(l>h)
        return NULL;
    int mid=(l+h)/2;
    if(root==NULL)
        root=createNode(arr[mid]);
    root->left = createBalTree(root->left,l,mid-1,arr);
    root->right = createBalTree(root->right,mid+1,h,arr);
}
void preorder(node *root)
{
    if(root==NULL)
        return;

    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root;
    root=createNode(5);
    root->left=createNode(4);
    root->right=createNode(7);
    root->right->right=createNode(9);
    root->right->left=createNode(6);
    root->right->right->right=createNode(11);
    int cnt=getcnt(root);
    cout<<cnt<<endl;
    node* curr=root;
    stack<node *> s;
    int n=0;
    int arr[1000];
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        arr[n++]=curr->data;
        curr=curr->right;
    }
    int mid=n/2;
    node* temp=NULL;
    temp=createBalTree(temp, 0 ,n-1 , arr);
    cout<<"HI"<<endl;
    preorder(temp);
    return 0;
}
