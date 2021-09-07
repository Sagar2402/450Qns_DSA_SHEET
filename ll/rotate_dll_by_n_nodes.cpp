#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next, *prev;
};
node* createNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insertAtHead(node* &head, node* &tail, int val)
{
    if(head==NULL)
    {
        head=createNode(val);
        tail=head;
        return;
    }
    node* temp=createNode(val);
    head->prev=temp;
    temp->next=head;
    head=temp;
}
void insertAtTail(node* &head, node* &tail, int val)
{
    if(tail==NULL)
    {
        head=createNode(val);
        tail=head;
        return;
    }
    node* temp=createNode(val);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
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
void rot_n_nodes(node* &head, node* &tail, int k)
{
    node* temp=head;
    while(k--)
        temp=temp->next;
    node* temp1=temp->prev;
    tail->next=head;
    temp1->next=NULL;
    head=temp;
}
int main()
{
    node* head=NULL;
    node* tail=NULL;
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);

    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    display(head);
    rot_n_nodes(head,tail,2);
    display(head);
    return 0;
}
