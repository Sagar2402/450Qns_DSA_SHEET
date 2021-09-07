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
void printleft(node* root, vector<int> &result)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
        if(root->left!=NULL)
        {
            result.push_back(root->data);
            printleft(root->left, result);
        }
        else if(root->right!=NULL)
        {
            result.push_back(root->data);
            printleft(root->right,result);
        }
    }
    void printright(node* root, vector<int> &result)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
        if(root->right!=NULL)
        {
            result.push_back(root->data);
            printright(root->right,result);
        }
        else if(root->left!=NULL)
        {
            result.push_back(root->data);
            printright(root->left, result);
        }
    }
    void printleaves(node* root, vector<int> &result)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            result.push_back(root->data);
        printleaves(root->left,result);
        printleaves(root->right,result);
    }
    void printBoundary(node *root)
    {
        //Your code here
        vector<int> result;
        result.push_back(root->data);
        printleft(root->left,result);
        printleaves(root,result);
        printright(root->right,result);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<"\t";
        }

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
    printBoundary(root);
    return 0;
}


