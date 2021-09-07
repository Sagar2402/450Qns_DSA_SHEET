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
    i=n,j=m;
    string s="";
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s+=x[i-1];
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
                i--;
            else
                j--;
        }
    }
    return s;
}
int minOperations(string str1, string str2)
{
    string lcs1=lcs(str1,str2,str1.length(),str2.length());
    int max1=max(str1.length(),str2.length());
    int min1=min(str1.length(),str2.length());
    int result=max1-lcs1.length();
    result+=(min1-lcs1.length());
    return result;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<minOperations(s1,s2)<<endl;
    return 0;
}
//heap pea
//3
