#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left, *right;
};
node* createNode(int key)
{
    node* temp=NULL;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
bool checkUsingStack(int arr[], int n)
{
    int root=INT_MIN,i;
    stack<int> s;
    for(i=0;i<n;i++)
    {
        if(arr[i]<root)
            return false;
        while(!s.empty() && s.top()<arr[i])
        {
            root=s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return true;
}
int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<checkUsingStack(arr,n);
    return 0;
}
/*
5
40 30 35 80 100
6
40 30 35 20 80 100
*/
