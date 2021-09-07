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
void inorder(node *root)
{
    stack<node *> s;
    node* curr=root;
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<"\t";
        curr=curr->right;
    }
    cout<<endl<<endl<<endl;
}
void preorder(node *root)
{
    stack<node *> s;
    s.push(root);
    while(!s.empty())
    {
        node *curr=s.top();
        s.pop();
        cout<<curr->data<<"\t";
        if(curr->right!=NULL)
            s.push(curr->right);
        if(curr->left!=NULL)
            s.push(curr->left);
    }
    cout<<endl<<endl<<endl;
}
void postorder(node *root)
{
    stack<node *> s;
    s.push(root);
    stack<int> otpt;
    while(!s.empty())
    {
        node* curr=s.top();
        s.pop();
        otpt.push(curr->data);
        if(curr->left!=NULL)
            s.push(curr->left);
        if(curr->right!=NULL)
            s.push(curr->right);
    }
    while(!otpt.empty())
    {
        cout<<otpt.top()<<"\t";
        otpt.pop();
    }
    cout<<endl<<endl<<endl;
}
int main()
{
    node *root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->right=newNode(3);
    root->right->right=newNode(6);
    root->right->left=newNode(5);
    root->right->left->right=newNode(8);
    root->right->left->left=newNode(7);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}
