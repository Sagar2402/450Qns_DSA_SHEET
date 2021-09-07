#include<bits/stdc++.h>
using namespace std;
int siz=10; //max size
int arr[10];
int nxt[10];
int n=5;    // k arrays thus 5 arrays
int free1=0;
int top[5];//index of top ele
void push(int ele, int num)
{
    int i=free1;
    free1=nxt[i];
    nxt[i]=top[num];
    top[num]=i;
    arr[i]=ele;
}
int pop(int num)
{
    if(top[num]==-1)
        return -1;
    int i=top[num];
    top[num]=nxt[i];
    nxt[i]=free1;
    free1=i;
    return arr[i];
}
int main()
{
    int i,j;
    for(i=0;i<n;i++)
        nxt[i]=i+1;
    nxt[n-1]=-1;
    for(i=0;i<n;i++)
        top[i]=-1;
    push(5,0);
    push(10,0);
    push(11,1);
    push(12,1);
    push(13,2);
    cout<<pop(0)<<endl;
    cout<<pop(1)<<endl;
    cout<<pop(1)<<endl;
    cout<<pop(1)<<endl;
    cout<<pop(2)<<endl;
    return 0;
}
