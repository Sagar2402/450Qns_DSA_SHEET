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
void printPath(node* root, int sum, vector<int> &path)
{
    if(root==NULL)
        return;
    path.push_back(root->data);
    printPath(root->left,sum,path);
    printPath(root->right,sum,path);
    int sum1=0;
    for(int j=path.size()-1;j>=0;j--)
    {
        sum1+=path[j];
        if(sum1==sum)
        {
            for(int i=path.size()-1;i>=j;i--)
            {
                cout<<path[i]<<"\t";
            }
            cout<<endl;
            break;
        }
    }
    path.pop_back();
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);
    int sum;
    cin>>sum;
    vector<int> path;
    printPath(root,sum,path);
    return 0;
}
// >> 5


