#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int partitiones(int arr[], int l, int r)
{
    int i,j;
    int pivot=arr[r];
    i=l-1;
    for(j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            cout<<"HELLO"<<endl;
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        int temp=arr[r];
        arr[r]=arr[i+1];
        arr[i+1]=temp;

        return (i+1);
    }
}
void Quicksort(int arr[],int l,int r)
{
    /*for(int i=0;i<=r;i++)
    {
        cout<<arr[i]<<"\t";
    }cout<<"\n";*/
    if(l<r)
    {
        int pi=partitiones(arr,l,r);
        cout<<pi<<endl;
        Quicksort(arr,l,pi-1);
        Quicksort(arr,pi+1,r);
    }
}
int main()
{
    int arr[7];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    Quicksort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}

