#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;
    int a[n];
    int flag=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    //find first ele thats not in descending order
    for(i=0;i<n-1;i++)
    {
        if(a[i+1]>a[i])
        {
            flag=1;
            int minim=INT_MAX;
            int posn=i+1;
            for(j=i+2;j<n;j++)
            {
                if(minim>a[j])
                {
                    minim=a[j];
                    posn=j;
                }
            }
            if(minim>a[i+1])
            {
                swap(a[i+1],a[posn]);
                if(i+2 < n)
                    sort(a+(i+2),a+n);
            }
            else if(minim<a[i+1])
            {
                swap(a[i],a[posn]);
                sort(a+(i+1),a+n);
            }
            break;
        }
    }
    if(flag==0)
        sort(a,a+n);
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    return 0;
}

/*
3
1 2 3
*/
