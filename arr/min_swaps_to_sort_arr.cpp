#include<bits/stdc++.h>
using namespace std;
int minSwaps(int arr[],int n)
{
    int i,j;
    pair<int, int> arrpos[n];
    for(i=0;i<n;i++)
    {
        arrpos[i]={arr[i],i};
    }
    sort(arrpos,arrpos+n);
    vector<bool> vis(n,false);
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]||arrpos[i].second==i)
        {
            continue;
        }
        int cycle=0;
        j=i;
        while(vis[j]==false)
        {
            vis[j]=true;
            j=arrpos[j].second;
            cycle++;
        }
        if(cycle>0)
        {
            ans+=(cycle-1);
        }
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minSwaps(arr,n);
    return 0;
}
/*
5
1 5 4 3 2
*/
