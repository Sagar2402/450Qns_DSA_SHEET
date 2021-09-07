#include<bits/stdc++.h>
using namespace std;
static int t[101][101];
int lcs(string x, string y, int n, int m)
{
    if(n==0 || m==0)
        return 0;
    if(t[n][m]!=-1)
        return t[n][m];
    if(x[n-1]==y[m-1])
    {
        return t[n][m]=1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return t[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
int main()
{
    memset(t,-1,sizeof(t));
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    cout<<lcs(s1,s2,n,m)<<endl;
    return 0;
}
/*
abcdgh
aedfhr

adh

aggtab
gxtxayb

gtab
*/

