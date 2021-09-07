#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left,*right;
};
void findminmax(node *root, int *maxim, int *minim, int hd)
{
    if(root==NULL)
        return;
    if(*maxim<hd)
        *maxim=hd;
    else if(*minim>hd)
        *minim=hd;
    findminmax(root->left,maxim,minim,hd-1);
    findminmax(root->right,maxim,minim,hd+1);
}
void printlvl(node *root, int lvl, int hd,bool arr[])
{
    if(root==NULL)
        return;
    if(hd==lvl && !arr[lvl])
    {
        arr[lvl]=true;
        cout<<root->data<<"\t";
        return;
    }

    if(lvl<=0){
    printlvl(root->left, lvl, hd-1,arr);
    printlvl(root->right, lvl, hd+1,arr);
    }
    else{
    printlvl(root->right, lvl, hd+1,arr);
    printlvl(root->left, lvl, hd-1,arr);
    }
}
void vertiorder(node *root)
{
    int maxim=0,minim=0;
    findminmax(root,&maxim,&minim,0);
    bool arr[maxim-minim];
    for(int i=minim;i<=maxim;i++)
    {
        arr[i]=false;
        printlvl(root,i,0,arr);
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
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    cout << "Top View is \n";
    vertiorder(root);
    return 0;
}
