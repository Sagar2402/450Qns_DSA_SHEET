#include<bits/stdc++.h>
using namespace std;
string post_to_in(string s)
{
    stack<string> st;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            string s1="";
            s1=s1+s[i];
            // other way to convert char to str
            //string s1(1,s[i]);
            st.push(s1);
        }
        else
        {
            string a=st.top();
            st.pop();
            string b=st.top();
            st.pop();
            string s1="";
            s1=s1+'('+b+s[i]+a+')';
            st.push(s1);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    s=post_to_in(s);
    cout<<s;
    return 0;
}
