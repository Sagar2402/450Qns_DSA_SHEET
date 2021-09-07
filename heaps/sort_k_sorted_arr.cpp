//complexity :: nlogk
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            result.push_back(pq.top());
            pq.pop();
        }
    }
    while(pq.empty()==false)
    {
        result.push_back(pq.top());
        pq.pop();
    }
    for(i=0;i<n;i++)
        cout<<result[i]<<"\t";
    return 0;
}
/*
7 3
6 5 3 2 8 10 9
*/
