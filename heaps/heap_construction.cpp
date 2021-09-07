#include<bits/stdc++.h>
using namespace std;
void printheap(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[],int n)
{
    int strtindx=(n/2)-1;
    for(int i=strtindx;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    buildHeap(arr,n);
    printheap(arr,n);
    return 0;
}
/*
11
1 3 5 4 6 13 10 9 8 15 17
*/
