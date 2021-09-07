#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev,*next;
};
node* createNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insert(node* head, int key)
{
    if(head==NULL)
    {
        head=createNode(key);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {

    }
}
int main()
{
    node* head=NULL;
    cin>>key;
    while(key!=-1)
    {
        insert(head,key);
        cin>>key;
    }
    return 0;
}
