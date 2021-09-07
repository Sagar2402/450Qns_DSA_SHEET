//dll shud be the inorder traversal of the tree
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
    node *temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert(node* &dll, int key)
{
    if(dll==NULL)
    {
        dll=createNode(key);
        return;
    }
    node* temp=dll;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    node* n=createNode(key);
    temp->right=n;
    n->left=temp;
}
void display(node* head)
{

    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->right;
    }
}
int main()
{
    node* root = createNode(10);
    root->left = createNode(12);
    root->right = createNode(15);
    root->left->left = createNode(25);
    root->left->right = createNode(30);
    root->right->left = createNode(36);
    stack<node *> s;
    node* curr=root;
    node* dll=NULL;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        insert(dll,curr->data);
        curr=curr->right;
    }
    display(dll);
    return 0;
}
