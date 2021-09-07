#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    j=0;  //-ve nums
    for(i=0;i<n-j;i++)
    {
        if(arr[i]<0)
        {
            swap(arr[i],arr[n-1-j]);
            j++;
            i--;
        }
    }
    if(n%2==0)
    {
        j=1;
    }
    else
    {
        j=0;
    }
    for(i=1;i<n-j;)
    {
        swap(arr[i],arr[n-1-j]);
        i+=2;
        j+=2;
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t"<<endl;
    }
    return 0;
}
