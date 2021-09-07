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
void findMiddle(node* curr, node** first, node** second)
{
    node* fast;
    node* slow;
    slow=curr;
    fast=curr->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=curr;
    *second=slow->next;
    //slow was middle ele
    //we break at middle
    //first is 1st ll similarly second is 2nd ll
    slow->next=NULL;
}
node* mergeit(node* first, node* second)
{
    node* answer=NULL;
    if(!first)
        return second;
    if(!second)
        return first;
    if(first->data<=second->data)
    {
        answer=first;
        answer->next=mergeit(first->next,second);
    }
    else
    {
        answer=second;
        answer->next=mergeit(first,second->next);
    }
    return answer;
}
void mergeSortUtil(node **head)
{
    node* curr= *head;
    node* first;
    node* second;
    if(curr==NULL || curr->next==NULL)
    {
        //if no ele or 1 ele no sorting required
        return;
    }
    findMiddle(curr,&first,&second);
    mergeSortUtil(&first);
    mergeSortUtil(&second);
    *head=mergeit(first,second);
}
node* mergeSort(node* head)
{
    mergeSortUtil(&head);
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node* head;
    head=createNode(4);
    head->next=createNode(2);
    head->next->next=createNode(7);
    head->next->next->next=createNode(5);
    head->next->next->next->next=createNode(1);
    display(head);
    head=mergeSort(head);
    display(head);
}
