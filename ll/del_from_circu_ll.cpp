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
void display(node* head1)
{
    node* head=head1;
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->next;
        if(head1==head)
        {
            break;
        }
    }
    cout<<endl<<endl;
}
node* del(node* head, int key)
{
    node* temp=head->next;
    node* curr=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            curr->next=temp->next;
            if(temp==head)
            {
                head=temp->next;
                //cout<<head->data;
            }
            return head;
        }
        curr=curr->next;
        temp=temp->next;
    }
}
int main()
{
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    head->next->next->next->next->next->next=head;
    int key=1; //to be deleted
    head=del(head,key);
    display(head);
    return 0;
}
