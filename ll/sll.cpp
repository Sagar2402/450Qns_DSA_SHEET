#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *llink, *rlink;
};
typedef struct node *Node;
Node createDLL(int ele, Node head)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->rlink=NULL;
    temp->llink=head;
    temp->data = ele;
    return temp;
}
void insertNode(int val1, int ele, Node head)
{
    //insert to the right
    Node temp;
    temp=head->rlink;
    while(temp!=NULL)
    {
        if(temp->data == val1)
        {
            Node n1 = (Node)malloc(sizeof(struct node));
            n1->data=ele;
            n1->llink = temp;
            n1->rlink = temp->rlink;
            Node temp1 = temp->rlink;
            temp->rlink = n1;
            if(temp1!=NULL)
            temp1->llink=n1;
            break;
        }
        temp=temp->rlink;
    }
}
void delDLL(Node head, int val)
{
    Node temp = head->rlink;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            temp->llink->rlink = temp->rlink;
        }
        temp=temp->rlink;
    }
}
void printDLL(Node head)
{
    Node temp = head->rlink;
    printf("\nList is :\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->rlink;
    }
    printf("\n");
}
int main()
{
    Node head = (Node)malloc(sizeof(struct node));
    Node temp = createDLL(5,head);
    head->rlink=temp;
    printf("%d",head->rlink->data);
    insertNode(5,3,head);
    insertNode(5,4,head);
    insertNode(3,7,head);
    insertNode(4,9,head);
    insertNode(7,6,head);
    //printf("%d",head->rlink->rlink->data);
    printDLL(head);
    delDLL(head,5);
    printDLL(head);
    return 0;
}
