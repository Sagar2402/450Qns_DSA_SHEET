#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,j;
    int n=s.length();
    int cnt=0;
    int z=0, o=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
            z++;
        else
            o++;
        if(z==o)
        {
            z=0;
            o=0;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
0100110101
0111100010
0000000000
*/
