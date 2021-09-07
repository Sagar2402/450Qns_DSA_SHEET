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
node* detectFloyd(node* head)
{
    node* fast=head->next->next;
    node* slow=head->next;
    int flag=0;
    while(fast->next!=NULL && fast->next->next!=NULL && slow->next!=NULL)
    {
        if(fast==slow)
        {
            flag=1;
            break;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    if(flag==0)
    {
        cout<<"No loop"<<endl;
        exit(0);
    }
    else
    {
        slow=head;
        while(slow!=fast)
        {
            //cout<<slow->data<<"\t"<<fast->data<<endl;
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    return NULL;
}
int main()
{
    node* head=NULL;
    head=newNode(1);
    head->next=newNode(2);
    //node* temp=head->next;
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    head->next->next->next->next->next=head->next;
    node *loophead= detectFloyd(head);
    cout<<loophead->data<<endl;
    return 0;
}
