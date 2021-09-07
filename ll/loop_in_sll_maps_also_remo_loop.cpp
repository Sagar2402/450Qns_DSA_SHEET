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
bool detNode(node *head)
{
    unordered_set<node *> s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
            return true;
        s.insert(head);
        head=head->next;
    }
    return false;
}

void removeLoop(node* head)
{
    unordered_set<node *> s;
    while(head->next!=NULL)
    {
        if(s.find(head->next)!=s.end())
            break;
        s.insert(head);
        head=head->next;
    }
    head->next=NULL;
}
int main()
{
    node *head;
    /*int key,k;
    cout<<"Enter key (-1 to exit)"<<endl;
    cin>>key;
    addNode(&head,key);
    display(head);
    if(detNode(head))
        cout<<"Cycle";
    else
        cout<<"No Cycle";*/
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=head->next;
    if(detNode(head))
        cout<<"Cycle";
    else
        cout<<"No Cycle";
    return 0;
}
