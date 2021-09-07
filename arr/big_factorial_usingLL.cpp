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
void multi(node* &head,int num)
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    int val=(temp->data)*num;
    int val1;
    int carry=0;

    while(temp->prev!=NULL)
    {
        val=((temp->data)*num)+carry;
        val1=val%10;
        carry=val/10;
        temp->data=val1;
        temp=temp->prev;
    }
    val=((temp->data)*num)+carry;
    val1=val%10;
    carry=val/10;
    temp->data=val1;
    if(carry>0)
    {
        while(carry>0)
        {
            insertAtHead(head,(carry%10));
            carry/=10;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    node *head=NULL;
    int n1=n;
    while(n1>0)
    {
        int b=n1%10;
        n1/=10;
        insertAtHead(head,b);
    }
    display(head);
    n--;
    while(n>1)
    {
        multi(head,n);
        n--;
    }
    display(head);
    return 0;
}
