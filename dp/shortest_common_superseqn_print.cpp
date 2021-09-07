#include<bits/stdc++.h>
using namespace std;
string lcs(string x, string y, int n, int m)
{
    int i,j;
    int t[n+1][m+1];
    for(i=0;i<=n;i++)
        t[i][0]=0;
    for(i=0;i<=m;i++)
        t[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    string result="";
    i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            result+=x[i-1];
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                result+=y[j-1];
                j--;
            }
            else
            {
                result+=x[i-1];
                i--;
            }
        }
    }
    while(i>0)
    {
        result+=x[i-1];
        i--;
    }
    while(j>0)
    {
        result+=y[j-1];
        j--;
    }
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    cout<<lcs(s1,s2,n,m)<<endl;
    return 0;
}
/*
AGGTAB
GXTXAYB

9
*/




