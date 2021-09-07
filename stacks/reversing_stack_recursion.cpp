#include<bits/stdc++.h>
using namespace std;
void insertbottom(stack<int>* s, int n)
{
    if((*s).empty()==true)
    {
        (*s).push(n);
    }
    else
    {
        int a=(*s).top();
        (*s).pop();
        insertbottom(s,n);
        (*s).push(a);
    }
}
void reverse(stack<int>* st)
{
    if((*st).size()>0)
    {
        int x = (*st).top();
        //cout<<x<<endl;
        (*st).pop();
        reverse(st);
        insertbottom(st,x);
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
    int i=0;
    int n=s.size();
    reverse(&s);
    for(i=0;i<n;i++)
    {
        cout<<s.top()<<"\t";
        s.pop();
    }
    return 0;
}
/*
1 5 4 6 8 3 -1
*/
