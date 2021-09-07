#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
};
node* createNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->next=NULL;
    return temp;
}
node* insert(node* head, int key)
{
    if(head==NULL)
    {
        return createNode(key);;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=createNode(key);
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->next;
    }
    cout<<endl<<endl;
}
void reverse(node **head)
{
    node *current=*head;
    node *prev=NULL;
    node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
bool isPalin(node* head)
{
    node* temp=head;
    node* temp1=head;
    int n=0;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        n++;
    }
    temp1=head;
    int mid=n/2;
    while(mid>0)
    {
        temp1=temp1->next;
        mid--;
    }
    if(n%2==1)
        temp1=temp1->next;
    reverse(&temp1);
    while(temp1!=NULL)
    {
        if(temp->data != temp1->data)
            return false;
        temp1=temp1->next;
        temp=temp->next;
    }
    return true;
}
int main()
{
    node* head=NULL;
    int key,i,j;
    cin>>key;
    while(key!=-1)
    {
        head=insert(head,key);
        cin>>key;
    }
    cout<<isPalin(head);
    //display(head);
    return 0;
}
