#include<bits/stdc++.h>
using namespace std;
class Q
{
    public:
    int front,rear;
    int size;
    int *arr;
    Q(int s)
    {
        front=rear=-1;
        size=s;
        arr=new int[s];
    }
};
void push(int x, Q &q)
{
    if(q.front==-1 && q.rear==-1)
    {
        q.arr[0]=x;
        q.front=0,q.rear=1;
    }
    else
    {
        q.rear=q.rear%q.size;
        if(q.rear==q.front)
        {
            cout<<"full"<<endl;
            return;
        }
        q.arr[q.rear++]=x;
    }
}
int pop(Q &q)
{
    if(q.front==-1 && q.rear==-1)
    {
        return INT_MIN;
    }
    else
    {
        int a=q.arr[q.front];
        q.front++;
        q.front=q.front%q.size;
        if(q.front==q.rear)
        {
            q.front=-1;
            q.rear=-1;
        }
        return a;
    }
}
int main()
{
    Q q(3);
    push(1,q);
    push(2,q);
    push(3,q);
    push(4,q);
    cout<<pop(q);
    push(4,q);
    push(5,q);
    cout<<pop(q)<<endl;
    cout<<pop(q)<<endl;
    cout<<pop(q)<<endl;
    cout<<pop(q)<<endl;
    cout<<pop(q)<<endl;
    return 0;
}
