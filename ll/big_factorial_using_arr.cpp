#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int main()
{
    int n;
    cin>>n;
    int arr[MAX];
    int j=0,i;
    int n1=n;
    while(n1>0)
    {
        arr[j]=(n1%10);
        j++;
        n1/=10;
    }
    n--;
    while(n>1)
    {
        int carry=0, val1;
        for(i=0;i<j;i++)
        {
            val1=(arr[i]*n)+carry;
            carry=val1/10;
            val1=val1%10;
            arr[i]=val1;
        }
        while(carry>0)
        {
            j++;
            arr[j-1]=carry%10;
            carry=carry/10;
        }
        n--;
    }
    for(i=j-1;i>=0;i--)
        cout<<arr[i]<<"\t";
    return 0;
}
