#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main()
{
    int k,i,j;
    cin>>k;
    vector<vector <int> > a(k);
    //k sorted arrs
    for(i=0;i<k;i++)
    {
        int size;
        cin>>size;
        a[i]=vector<int>(size);
        for(j=0;j<size;j++)
        {
            cin>>a[i][j];
        }

    }
    vector<int> idx(k,0); //stores index of arr ele stored in min heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(i=0;i<k;i++)
    {
        pq.push({a[i][0], i});
    }
    vector<int> ans;
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        ans.push_back(x.first);
        if(idx[x.second]+1 < a[x.second].size())
        {
            pq.push({a[x.second][idx[x.second]+1], x.second});
        }
        idx[x.second]+=1;
    }
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
/*
3
3
1 4 6
2
2 3
4
1 5 6 7
*/
