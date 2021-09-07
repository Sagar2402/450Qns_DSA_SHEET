//O(n^2) approach
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left,*right;
};
int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else
        {
          return(rheight + 1);
        }
    }
}
void currentlvl(node* root, int lvl)
{
    if(root==NULL)
        return;
    if(lvl==0)
        cout<<root->data<<"\t";
    else if(lvl>0)
    {
        currentlvl(root->left, lvl-1);
        currentlvl(root->right, lvl-1);
    }
}
void revlvlorder(node* root)
{
    int ht=height(root);
    int i;
    for(i=ht-1;i>=0;i--)
    {
        currentlvl(root,i);
    }
}
node *NewNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main()
{
    node* root;
    root=NewNode(1);
    root->left=NewNode(2);
    root->right=NewNode(3);
    root->left->left=NewNode(4);
    root->left->right=NewNode(5);
    revlvlorder(root);
    return 0;
}
