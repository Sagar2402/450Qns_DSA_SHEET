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
bool checkutil(node* root, int lvl, int *lflvl)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
    {
        if(*lflvl==0)
        {
            *lflvl=lvl;
            return true;
        }
        return (*lflvl==lvl);
    }
    return (checkutil(root->left,lvl+1,lflvl)&&checkutil(root->right, lvl+1, lflvl));
}
bool check(node* root)
{
    int lvl=0,lflvl=0;
    return checkutil(root,lvl,&lflvl);
}

int main()
{
    node* root = createNode(10);
    root->left = createNode(12);
    root->right = createNode(15);
    root->left->left = createNode(25);
    root->left->right = createNode(30);
    root->right->left = createNode(36);
    //root->right->left->left = createNode(40);
    cout<<check(root)<<endl;
    return 0;
}

