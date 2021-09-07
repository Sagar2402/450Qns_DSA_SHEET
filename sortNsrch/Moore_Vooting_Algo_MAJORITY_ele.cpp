#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt=1;
    int max_index=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]==arr[max_index])
            cnt++;
        else
            cnt--;
        if(cnt==0)
        {
            max_index=i;
            cnt=1;
        }
        if(cnt==n/2)
            break;
    }
    int cnt1=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==arr[max_index])
        {
            cnt1++;
        }
    }
    if(cnt1>n/2)
    cout<<arr[max_index]<<endl;
    else
    cout<<-1<<endl;
    return 0;
}
