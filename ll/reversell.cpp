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
int main()
{
    node *head;
    int key;
    cout<<"Enter key (-1 to exit)"<<endl;
    cin>>key;
    addNode(&head,key);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}
