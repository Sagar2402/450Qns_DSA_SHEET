#include<bits/stdc++.h>
using namespace std;
int findPivot(int arr[],int i,int n)
{
    if(i==n-1)
        return arr[i];
    int mid=(i+n)/2;
    if(mid==0)
    {
        if(arr[mid+1]<arr[mid])
            return (mid+1);
    }
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return mid+1;
    else if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1])
        return mid;
    else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]&&arr[mid]>=arr[0])
    {
        return findPivot(arr,mid+1,n);
    }
    else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]&&arr[mid]<arr[0])
    {
        return findPivot(arr,i,mid-1);
    }
}
int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int pivot=findPivot(arr,0,n-1);
    cout<<pivot<<endl;
    return 0;
}
/*
7
4 5 6 7 1 2 3
10
4 5 6 7 8 9 10 1 2 3
*/
