#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev, *next;

    node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void insertAtHead(node* &head, int val)
{
    node *n=new node(val);
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;

}
void insertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node *n=new node(val);
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
void findPairs(node* head, int k1, int k)
{
    node* temp=head;
    node* temp1=head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    while(true)
    {
        int sum=temp->data + temp1->data;
        if(sum>(k-k1))
        {
            temp1=temp1->prev;
        }
        else if(sum<(k-k1))
        {
            temp=temp->next;
        }
        else
        {
            if(temp==temp1)
                return;
            cout<<k1<<" + "<<temp->data<<" + "<<temp1->data<<" = "<<k<<endl;
            temp=temp->next;
        }
        if(temp==temp1)
        {
            return;
        }
    }
}
void findTriplet(node* head, int k)
{
    node* temp1=head;
    //temp1 holds the last ptr till which 1st ele can go
    while(temp1->next->next!=NULL)
    {
        temp1=temp1->next;
    }
    node* temp=head;
    while(temp!=temp1)
    {
        findPairs(temp->next, temp->data, k);
        temp=temp->next;
    }
}
int main()
{
    node* head=NULL;
    int key;
    cin>>key;
    while(key!=-1)
    {
        insertAtTail(head,key);
        cin>>key;
    }
    int k;
    cin>>k;
    findTriplet(head,k);
    return 0;
}
/*
1 2 4 5 6 8 9 -1
12

1 4 6 8 10 45 -1
22

1 2 4 5 6 8 9 -1
15

1 2 4 5 6 8 9 -1
17
*/

