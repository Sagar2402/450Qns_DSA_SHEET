#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    vector<int> arr1(n,-1);
    for(i=0;i<n;i++)
        cin>>arr[i];
    stack<int> s;
    stack<int> s1;
    s.push(arr[0]);
    s1.push(0);
    for(i=1;i<n;i++)
    {
        if(arr[i]>s.top())
        {
            while(s.empty()==false && s.top()<arr[i])
            {
                int a1=s1.top();
                arr1[a1]=arr[i];
                s1.pop();
                s.pop();
            }
            s.push(arr[i]);
            s1.push(i);
        }
        else
        {
            s.push(arr[i]);
            s1.push(i);
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"<<::>>"<<arr1[i]<<"\n";
    }
    return 0;
}
