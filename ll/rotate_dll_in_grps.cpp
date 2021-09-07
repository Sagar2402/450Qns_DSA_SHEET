#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next, *prev;
};
node* createNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insertAtHead(node* &head, int val)
{
    node *n=createNode(val);
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;

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
node* reverseByN(node* head, int k)
{
    node* temp=head;
    while(temp!=NULL)
    {
        int k1=k;
        while(k1--)
        {

        }
    }
}
/*node* reverseByN(node* head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k)
    {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    if (count >= k)
    {
        head->next = reverseByN(curr, k);
    }
    return newHead;
}*/
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
int main()
{
    node* head=NULL;
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    display(head);
    head=reverseByN(head,3);
    display(head);
    return 0;
}
