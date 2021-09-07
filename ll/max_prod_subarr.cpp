#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    long long int max_val=arr[0],min_val=arr[0];
    long long int max_prod=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<0)
            swap(max_val,min_val);
        max_val=max(((long long int)arr[i]),arr[i]*max_val);
        min_val=min((long long int)arr[i],arr[i]*min_val);
        max_prod=max(max_prod, max_val);
    }
    cout<<max_prod;
    return 0;
}
