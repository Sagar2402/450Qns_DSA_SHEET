#include <bits/stdc++.h>
using namespace std;
static int flag=0;
class node
{
    public:
    int data;
    node* left, *right;
};

void printLevelOrder(node* root)
{
    if(root==NULL)
        return;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            node* temp=q.front();
            q.pop();
            if(n==0)
            cout<<temp->data<<"\t";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}
