#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int maxim=INT_MIN;
    int maxhere=0;
    for(i=0;i<n;i++)
    {
        maxhere+=arr[i];
        if(maxim<maxhere)
        {
            maxim=maxhere;
        }
        if(maxhere<0)
        {
            maxhere=0;
        }

    }
    cout<<maxim<<endl;
    return 0;
}
//8
//2 -3 4 -1 -2 1 5 -3
