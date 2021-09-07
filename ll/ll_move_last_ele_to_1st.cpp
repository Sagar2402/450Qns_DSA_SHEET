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
    node* temp=new node();
    temp->data=key;
    temp->next=NULL;
    return temp;
}
node* putFirst(node* head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* temp1=temp->next;
    temp1->next=head;
    temp->next=NULL;
    return temp1;
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
int main()
{
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    head->next->next->next->next->next->next=createNode(7);
    head=putFirst(head);
    display(head);
    return 0;
}
