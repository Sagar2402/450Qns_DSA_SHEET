#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_fn(string s)
{
    int n=s.length();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}
int main()
{
    string s1="apnaxnancollege";
    string s="nan";
    vector<int> pre=prefix_fn(s);
    int pos=-1;
    int i=0,j=0;
    while(i<s1.size())
    {
        if(s1[i]==s[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=pre[j-1];
            else
                i++;
        }
        if(j==s.length())
        {
            pos=i-s.length();
            break;
        }
    }
    cout<<pos<<endl;
    return 0;
}

