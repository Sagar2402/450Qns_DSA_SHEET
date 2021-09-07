#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
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
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}
void treecons(string s, node **root, int n)
{
    static int i=0;
    if(i<n){
    //cout<<i<<endl;
    if(s[i]!='(' && s[i]!=')')
    {
        *root=createNode(s[i]);
        i++;
        //cout<<(*root)->data<<endl;
    }
    if(s[i]=='(')
    {
        if((*root)->left==NULL)
        {
            i++;
            treecons(s,&((*root)->left),n);
        }
        if((*root)->right==NULL)
        {
            i++;
            treecons(s,&((*root)->right),n);
        }
    }
    if(s[i]==')')
    {
        i++;
        return;
    }
    }
}

int main()
{
    string s;
    cin>>s;
    node *root;
    int n=s.length();
    treecons(s,&root,n);
    cout<<"Inorder traversal :"<<endl;
    inorder(root);
    return 0;
}
//1(2)(3)
