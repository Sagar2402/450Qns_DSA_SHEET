#include<bits/stdc++.h>
using namespace std;
int tab[101][101];
int subsetsum(int arr[], int n, int sum)
{
    if(sum==0)
        return 1;
    if(n<=0)
        return 0;
    if(tab[n-1][sum]!=-1)
    {
        return tab[n-1][sum];
    }
    if(arr[n-1]>sum)
        return tab[n-1][sum]=subsetsum(arr,n-1,sum);
    else
    {
        return tab[n-1][sum]=subsetsum(arr,n-1,sum) || subsetsum(arr,n-1,sum-arr[n-1]);
    }
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(tab,-1,sizeof(tab));
    cout<<subsetsum(arr,n,sum);
    return 0;
}
/*
5 12
1 5 3 7 4
*/
