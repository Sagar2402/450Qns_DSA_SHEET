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
node* reverse(node **head)
{
    if(*head==NULL || (*head)->next == NULL)
        return *head;
    node *rest=reverse(&((*head)->next));
    (*head)->next->next=(*head);
    (*head)->next=NULL;
    return rest;
}
int main()
{
    node *head;
    int key;
    cout<<"Enter key (-1 to exit)"<<endl;
    cin>>key;
    addNode(&head,key);
    display(head);
    head=reverse(&head);
    display(head);
    return 0;
}

