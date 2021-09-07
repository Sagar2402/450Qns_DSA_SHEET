#include<bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int>* s, int x)
{
    if ((*s).empty() || x > (*s).top())
    {
        (*s).push(x);
        return;
    }
    int temp = (*s).top();
    (*s).pop();
    sortedInsert(s, x);
    (*s).push(temp);
}
void sortstack(stack<int>* s)
{
    if((*s).empty()==false)
    {
        int a=(*s).top();
        (*s).pop();
        sortstack(s);
        sortedInsert(s,a);
    }
}
int main()
{
    stack<int> s;
    int key;
    cin>>key;
    while(key!=-1)
    {
        s.push(key);
        cin>>key;
    }
    sortstack(&s);
    while((s).empty()==false)
    {
        cout<<(s.top())<<"\t";
        s.pop();
    }
    return 0;
}
/*
15 47 34 12 1 -1
*/
