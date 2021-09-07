#include<bits/stdc++.h>
using namespace std;
void inorder(vector<int> &result, int arr[], int n, int i)
{
    if(i>=n)
        return;
    inorder(result,arr,n,2*i+1);
    result.push_back(arr[i]);
    inorder(result,arr,n,2*i+2);
}
void swap(vector<int> &arr,int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
int main()
{
    int n;
    cin>>n;
    int i,j,arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    vector<int> in;
    inorder(in,arr,n,0);
    for(i=0;i<n;i++)
        cout<<in[i]<<"\t";
    cout<<endl;
    map <int, int> h;
    vector<int> temp=in;
    int ans=0;
    //hashmap
    for (int i = 0; i < n; i++)
    {
        h[in[i]] = i;
    }
    sort(temp.begin(),temp.end());
    for(i=0;i<n;i++)
    {
        if(in[i]!=temp[i])
        {
            ans++;
            int init=in[i];
            swap(in, i, h[temp[i]]);
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
7
5 6 7 8 9 10 11
*/
