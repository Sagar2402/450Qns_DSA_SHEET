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
void printPath(node* root, int sum, int sumhere, vector<int> &path)
{
    if(root==NULL)
        return;
    sumhere+=root->data;
    path.push_back(root->data);
    if(sumhere==sum)
    {
        for(int j=0; j<path.size(); j++)
            cout<<path[j]<<"\t";
        cout<<endl;
    }
    printPath(root->left,sum,sumhere,path);
    printPath(root->right,sum,sumhere,path);
    path.pop_back();
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(6);
    root->left->right = newNode(5);
    root->right->left = newNode(4);
    root->right->right = newNode(7);
    int sum;
    cin>>sum;
    vector<int> path;
    printPath(root,sum,0,path);
    return 0;
}

