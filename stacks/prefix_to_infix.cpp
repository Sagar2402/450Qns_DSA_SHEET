#include<bits/stdc++.h>
using namespace std;
string infix(string s)
{
    stack<string> st;
    int i;
    for(i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            string result="";
            result+=s[i];
            st.push(result);
        }
        else
        {
            string result="";
            string a=st.top();
            st.pop();
            string b=st.top();
            st.pop();
            result=result+'('+a+s[i]+b+')';
            //cout<<result<<endl;
            st.push(result);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    s=infix(s);
    cout<<s<<endl;
    return 0;
}
//*-a/bc-/akl
