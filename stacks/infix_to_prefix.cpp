#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string prefix(string s)
{
    stack<char> st;
    string result="";
    //we reverse attack so ) becomes ( and ( becomes )
    int i;
    for(i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='a'&&s[i]<='z')
            result+=s[i];
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(st.top()!=')' && st.empty()==false)
            {
                result=result+st.top();
                st.pop();
            }
            st.pop();
        }
        else //operatot
        {
            while(!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    int n=result.length();
    for(i=0;i<n/2;i++)
    {
        swap(result[i],result[n-i-1]);
    }
    return result;
}
int main()
{
    string s;
    cin>>s;
    s=prefix(s);
    cout<<s<<endl;
    return 0;
}
//(a-b/c)*(a/k-l)
