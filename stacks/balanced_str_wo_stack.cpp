#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
    {
        // code here
        int i=0,len=0;
        stack<int> st;
        st.push(-1);
        //so that st.pop isnt segmentation fault
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                len=max(len, i-st.top());
            }
        }
        return len;
    }
int main()
{
    string s;
    cin>>s;
    int len=0;
    int i,j;
    int left=0,right=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if(right==left)
        {
            len=max(len, 2*right);
        }
        if(right>left)
        {
            right=left=0;
        }
    }
    left=right=0;
    for(i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='(')
            left++;
        else
            right++;
        if(right==left)
            len=max(len, 2*right);
        if(left>right)
            left=right=0;
    }
    cout<<len<<endl;
    cout<<findMaxLen(s)<<endl;
    return 0;
}
