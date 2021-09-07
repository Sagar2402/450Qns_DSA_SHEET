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
    node *temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* consTree1(int arr[], int *preIndex, int key, int min, int max, int n)
{
    if(*preIndex>=n)
        return NULL;
    node *root=NULL;
    if(key>min && key<max)
    {
        root=newNode(key);
        *preIndex=*preIndex+1;
        if(*preIndex < n)
        {
            root->left = consTree1(arr, preIndex,arr[*preIndex],min, key, n);
        }
        if (*preIndex < n)
        {
            root->right = consTree1(arr, preIndex,arr[*preIndex],key, max, n);
        }
    }
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
node* consTree(int arr[], int n)
{
    int preIndex=0;
    return consTree1(arr,&preIndex,arr[0],INT_MIN,INT_MAX,n);
}
int main()
{
    int n;
    cin>>n;
    int i,j;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    node *root=consTree(arr,n);
    inorder(root);
    return 0;
}
/*
6
10 5 1 7 40 50
*/
