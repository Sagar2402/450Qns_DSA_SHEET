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
int helper(node* root, int &ans)
{
    if(root==NULL)
        return 0;
    int currsum=root->data+helper(root->left,ans)+helper(root->right,ans);
    ans=max(ans,currsum);
    return currsum;
}
int largest_subtr_sum(node* root)
{
    if(root==NULL)
        return 0;
    int ans=INT_MIN;
    helper(root,ans);
    return ans;
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
    cout<<largest_subtr_sum(root);
    return 0;
}

