#include<bits/stdc++.h>
using namespace std;
void bottom(stack<int> &s, int a)
{
    if(s.empty())
    {
        s.push(a);
        return;
    }
    int b=s.top();
    s.pop();
    bottom(s,a);
    s.push(b);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    bottom(s,6);
    bottom(s,7);
    while(s.empty()==false)
    {
        cout<<s.top()<<"\t";
        s.pop();
    }
}
