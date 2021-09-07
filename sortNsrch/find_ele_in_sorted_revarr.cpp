#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;

    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
int findPivot(int arr[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;

    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);

    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);

    return findPivot(arr, mid + 1, high);
}
int main()
{
    int n,i,j,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int pivot=findPivot(arr,0,n-1);
    //if pivot=-1 normal binary srch
    //there possi arr not reversed
    if(pivot==-1)
    {
        cout<<binarySearch(arr,0,n-1,k);
        return 0;
    }
    if(arr[pivot]<k)
    {
        cout<<-1;
        return 0;
    }
    if(k<=arr[pivot] && arr[0]<=k)
    {
        cout<<binarySearch(arr,0,pivot,k);
    }
    else
    {
        cout<<binarySearch(arr,pivot+1,n,k);
    }
    return 0;
}
