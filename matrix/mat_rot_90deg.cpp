#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m-i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
