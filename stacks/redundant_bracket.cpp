#include<bits/stdc++.h>
using namespace std;
bool redun(string s)
{
    stack<char> st;
    for (int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if (ch == ')')
        {
            char top = st.top();
            st.pop();
            bool flag = true;
            while (!st.empty() and top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/' || top=='^')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if (flag == true)
                return true;
        }
        else
            st.push(ch);
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<redun(s);
    return 0;
}
