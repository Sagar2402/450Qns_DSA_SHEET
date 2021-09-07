#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    map<int, int> cnt;
    int prefSum=0;
    for(i=0;i<n;i++)
    {
        prefSum+=a[i];
        cnt[prefSum]++;
    }
    int ans=0;
    map<int, int>::iterator itr;
    for(itr=cnt.begin();itr!=cnt.end();itr++)
    {
        int c2=itr->second;
        ans+=(c2*(c2-1)/2);
        if(itr->first==0)
            ans+=c2;

    }
    cout<<ans<<endl;
    return 0;
}
/*
4
1 -1 1 -1
*/
