#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next, *down;
};
node* createNode(int key)
{
    node* temp=new node();
    temp->data=key;
    temp->next=NULL;
    temp->down=NULL;
    return temp;
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
        answer->down=mergeit(first->down,second);
    }
    else
    {
        answer=second;
        answer->down=mergeit(first,second->down);
    }
    return answer;
}
void flatten(node* &head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        node* first=temp;
        node* second=temp->next;
        temp=mergeit(first,second);
        temp->next=temp->next->next;
    }
}
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->down;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    head=createNode(5);
    head->down=createNode(7);
    head->down->down=createNode(8);
    head->down->down->down=createNode(30);
    head->next=createNode(10);
    head->next->down=createNode(20);
    head->next->next=createNode(19);
    head->next->next->down=createNode(22);
    head->next->next->down->down=createNode(50);
    head->next->next->next=createNode(28);
    head->next->next->next->down=createNode(35);
    head->next->next->next->down->down=createNode(40);
    head->next->next->next->down->down->down=createNode(45);
    flatten(head);
    display(head);

}
