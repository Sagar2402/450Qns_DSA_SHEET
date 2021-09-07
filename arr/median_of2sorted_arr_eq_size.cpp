#include<bits/stdc++.h>
using namespace std;
int findmed(int arr1[], int arr2[], int n)
{

}
int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    int i,j;
    for(i=0;i<n;i++)
        cin>>arr1[i];
    for(i=0;i<n;i++)
        cin>>arr2[i];
    cout<<findmed(arr1,arr2,n);
    return 0;
}
