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
node* rev(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    node* n1=NULL;
    node* temp1=temp;
    while(temp->prev != NULL)
    {
        node* n=temp->prev;
        temp->prev=n1;
        temp->next=n;
        n1=temp;
        temp=temp->next;
    }
    temp->next=NULL;
    return temp1;
}
int main()
{
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtTail(head,7);
    display(head);
    head=rev(head);
    display(head);
    return 0;
}
