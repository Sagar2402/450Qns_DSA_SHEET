#include<bits/stdc++.h>
using namespace std;
void rev(stack<int> s,int x)
{
    if(!s.empty())
    {
        int x1=s.top();
        //cout<<"x1 ="<<x1<<"\tx="<<x<<endl;
        s.pop();
        rev(s,x1);
    }
    //cout<<x<<"\t"<<s.empty()<<endl;
    s.push(x);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    int x=s.top();
    s.pop();
    rev(s,x);
    s.push(x);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
/*
int insert_at_bottom(stack<int> st,int x)
{

    if(st.empty())
    st.push(x);

    else
    {
        int a = st.top();
        st.pop();
        insert_at_bottom(st,x);
        st.push(a);
    }
}
char rev(stack<int> s)
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        rev(s);
        insert_at_bottom(s,x);
    }
}
*/
