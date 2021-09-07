#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    unordered_set<int> s;
    for(i=0;i<n;i++)
    {
        if(s.find(arr[i])!=s.end())
        {
            cout<<arr[i]<<endl;
            break;
        }
        s.insert(arr[i]);
    }
    return 0;
}
/*
5
3 1 3 4 2
*/
