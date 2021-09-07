#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node* newNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->next=NULL;
    return temp;
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
node* addOne(node* head)
{
    if(head->next==NULL)
    {
        head->data=head->data+1;
        int carry=head->data/10;

    }
}
int main()
{
    node* head=NULL;
    head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    head = addOne(head);
    display(head);
    return 0;
}

