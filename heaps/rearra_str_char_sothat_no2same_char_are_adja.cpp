#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main()
{
    int i;
    string s;
    cin>>s;
    priority_queue<pii, vector<pii>> pq;
    vector<int> count(26,0);
    for(i=0;i<s.length();i++)
    {
        count[(int)(s[i]-'a')]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(count[i]>0)
        {
            pq.push({count[i],i});
        }
    }
    string s1="";
    pii x,x1={-1,-1};
    while(!pq.empty())
    {
        x=pq.top();
        pq.pop();
        if(x1.second!=-1)
        {
            pq.push(x1);
            x1={-1,-1};
        }
        s1=s1+((char)(x.second+97));
        x.first--;
        if(x.first>0)
            x1=x;
    }
    if(s1.length()!=s.length())
        cout<<-1<<endl;
    else
        cout<<s1<<endl;
    return 0;
}
