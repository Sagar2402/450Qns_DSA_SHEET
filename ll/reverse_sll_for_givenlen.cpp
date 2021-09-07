#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node* createNode(int key)
{
    node *temp=new node();
    temp->data=key;
    temp->next=NULL;
    return temp;
}
void addNode(node **head, int key)
{
    if(key!=-1)
    {
        *head=createNode(key);
        cout<<"Enter key"<<endl;
        cin>>key;
        addNode(&((*head)->next),key);
    }
}
void display(node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
node* reverse(node **head, int k)
{
    node *current=*head;
    node *prev=NULL;
    node *next=NULL;
    int k1=k;
    while(current!=NULL && k1>0)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        k1--;
    }
    if(next!=NULL)
        (*head)->next=reverse(&next,k);
    return prev;
}
int main()
{
    node *head;
    int key,k;
    cout<<"Enter key (-1 to exit)"<<endl;
    cin>>key;
    addNode(&head,key);
    display(head);
    cout<<"Enter size"<<endl;
    cin>>k;
    head=reverse(&head,k);
    display(head);
    return 0;
}
