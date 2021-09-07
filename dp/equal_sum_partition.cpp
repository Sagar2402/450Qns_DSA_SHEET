#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int arr[], int n, int sum)
{
    int t[n+1][sum+1];
    int i,j;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(j==0)
                t[i][j]=true;
            if(i==0 && j!=0)
                t[i][j]=false;
        }
    }
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i][j-arr[i]] || t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
bool eqsumparti(int arr[], int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
        return false;
    else
        return subsetsum(arr,n,sum/2);
}
int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<eqsumparti(arr,n);
    return 0;
}
