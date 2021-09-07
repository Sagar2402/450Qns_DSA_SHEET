#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int a[n],b[m];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    int k=n-1;
    for(i=0,j=0;i<=k&&j<m;)
    {
        if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            swap(a[k--],b[j++]);
        }
    }
    sort(a,a+n);
    sort(b,b+m);
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    for(j=0;j<m;j++)
        cout<<b[j]<<"\t";

    return 0;
}
/*
4 5
1 3 5 7
0 2 6 8 9
*/
