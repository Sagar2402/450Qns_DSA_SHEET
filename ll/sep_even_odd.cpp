#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node* createNode(int key)
{
    Node *temp=new Node();
    temp->data=key;
    temp->next=NULL;
    return temp;
}
Node* divide(int N, Node *head)
    {
        // code here
        Node* odd=NULL;
        Node* even=NULL;
        Node *e1=NULL, *o1=NULL;
        Node* temp=head;
        if(temp->next==NULL)
            return temp;
        while(temp!=NULL)
        {
            if(temp->data%2==0)
            {
                if(even==NULL)
                {
                   even=new Node(temp->data);
                   cout<<even->data<<endl;
                   e1=even;
                }
                else
                {
                    even->next=new Node(temp->data);
                    even=even->next;
                }

            }
            else
            {
                if(odd==NULL)
                {
                   odd=new Node(temp->data);
                   o1=odd;
                }
                else
                {
                    odd->next=new Node(temp->data);
                    odd=odd->next;
                }

            }
            temp=temp->next;
        }
        even->next=o1;
        return e1;
    }
int main()
{
    Node* head=NULL;
    head=
    return 0;
}
