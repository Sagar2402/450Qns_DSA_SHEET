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
void inorder(node* head, vector<int> &in)
{
    if(head==NULL)
        return;
    inorder(head->left,in);
    in.push_back(head->data);
    inorder(head->right,in);
}
void preorder(node* head, vector<int> &in, int *i)
{
    if(head==NULL)
        return;
    head->data=in[(*i)++];
    preorder(head->left,in,i);
    preorder(head->right,in,i);
}
void inorderprint(node* head)
{
    if(head==NULL)
        return;
    inorderprint(head->left);
    cout<<head->data<<"\t";
    inorderprint(head->right);
}
int main()
{
    node* head=createNode(4);
    head->left=createNode(2);
    head->left->left=createNode(1);
    head->left->right=createNode(3);
    head->right=createNode(6);
    head->right->left=createNode(5);
    head->right->right=createNode(7);
    vector<int> in;
    inorder(head,in);
    int i=0;
    preorder(head,in,&i);
    inorderprint(head);
    return 0;
}
