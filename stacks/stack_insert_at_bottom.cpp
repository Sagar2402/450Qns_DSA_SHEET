#include<bits/stdc++.h>
using namespace std;
void insertbottom(stack<int>* s, int n)
{
    int a=(*s).top();
    (*s).pop();
    if((*s).empty()==true)
    {
        (*s).push(n);
    }
    else
    {
        insertbottom(s,n);
    }
    (*s).push(a);
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
    int n;
    cin>>n;
    insertbottom(&s,n);
    for(;s.empty()==false;)
    {
        cout<<s.top()<<"\t";
        s.pop();
    }

    return 0;
}
/*
15 47 34 12 1 -1
18
*/
