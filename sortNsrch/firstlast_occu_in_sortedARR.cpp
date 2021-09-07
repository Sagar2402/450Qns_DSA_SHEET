#include<bits/stdc++.h>
using namespace std;
int firstoccu(int arr[], int n, int k)
{
    int l=0,h=n;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(mid==0 || (arr[mid-1]<k&&arr[mid]==k))
            return mid;
        else if(k>arr[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid;
        }
    }
}
int lastoccu(int arr[], int n, int k)
{
    int l=0,h=n;
    while(l<=h)
    {
        int mid=((l+h)/2)-1;
        if(mid==n-1 || (arr[mid+1]>k&&arr[mid]==k))
            return mid;
        else if(k<arr[mid])
        {
            h=mid;
        }
        else
        {
            l=mid+1;
        }
    }
}
int main()
{
    int i,j,n,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int f_o=firstoccu(arr,n,k);
    int l_o=lastoccu(arr,n,k);
    cout<<f_o<<"\t"<<l_o<<endl;
    return 0;
}
