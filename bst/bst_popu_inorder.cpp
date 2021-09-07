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
    node* temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insertkey(node* head, int key)
{
    node *temp =head;
    if(temp==NULL)
    {
        temp=createNode(key);
        return;
    }
    while(true)
    {
        if(temp->data < key)
        {
            if(temp->right==NULL)
            {
                temp->right=createNode(key);
                break;
            }
            temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                temp->left=createNode(key);
                break;
            }
            temp=temp->left;
        }
    }
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void populateNext(node *root)
{
        //code here
        int temp;
        int flag=1;
        stack<node *> s;
        node* curr=root;
        while(curr!=NULL || s.empty()==false)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            //inorder data
            //cout<<curr->data<<"\t";
            if(flag==1)
            {
                cout<<curr->data<<"->";
                flag=0;
            }
            else
            {
                cout<<curr->data<<" "<<curr->data<<"->";
            }
            curr=curr->right;
        }
        cout<<-1;
}
int main()
{

    int key;
    cin>>key;
    node *head;
    head = createNode(key);
    cin>>key;
    while(key!=-1)
    {
        insertkey(head,key);
        cin>>key;
    }
    inorder(head);
    cout<<endl;
    populateNext(head);
    return 0;
}
