#include<bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(vector<int> &A, int B) {
    vector<int> ans;
    if(A.size()<B)
    {
        return ans;
    }
    deque<int> Q;
    int i=0;
    Q.push_back(A[i]);
    for(int j=1; j<A.size();j++)
    {
        if(j-i<B)
        {
            while(!Q.empty() && Q.back()<A[j])
            {
                Q.pop_back();
            }
            Q.push_back(A[j]);
        }

        else
        {
            ans.push_back(Q.front());
            if(A[i]==Q.front())
            {
                Q.pop_front();
            }
            while(!Q.empty() && Q.back()<A[j])
            {
                Q.pop_back();
            }
            Q.push_back(A[j]);
            i++;
        }
    }
    ans.push_back(Q.front());
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> A;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    vector<int> result=slidingMaximum(A,k);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<"\t";
    return 0;
}
/*
9 3
1 2 3 1 4 5 2 3 6
*/
