#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    priority_queue<int> q;
    for(i=0;i<n;i++)
    {
        q.push(arr[i]);
    }
    int maxim=1, maximc=1;
    int a,b;
    a=q.top();
    q.pop();
    while(!q.empty())
    {
        b=q.top();
        q.pop();
        if((a-b)==1)
        {
            //cout<<a<<"\t"<<b<<endl;
            maximc++;
            a=b;
        }
        else if(a!=b)
        {
            maximc=1;
            a=b;
        }
        if(maximc>maxim)
        {
            maxim=maximc;
        }
    }
    cout<<maxim<<endl;
    return 0;
}
