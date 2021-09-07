#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > fourSum(vector<int> &arr, int sum) {
        // Your code goes here
        int i,j,k1,k2;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int sum1=0;
        vector<vector<int> > res;
        vector<int> res1;
        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                sum1=arr[i]+arr[j];
                k1=j+1,k2=n-1;
                while(k1<k2)
                {
                    if(sum1+arr[k1]+arr[k2]==sum)
                    {
                        res1.push_back(arr[i]);
                        res1.push_back(arr[j]);
                        res1.push_back(arr[k1]);
                        res1.push_back(arr[k2]);
                        res.push_back(res1);
                        res1.clear();
                        k1++;
                        k2--;
                    }
                    else
                    {
                        if(sum1+arr[k1]+arr[k2]>sum)
                        {
                            k2--;
                        }
                        else
                        {
                            k1++;
                        }
                    }
                }
            }
        }
        return res;
    }
int main()
{
    vector<int> arr;
    int i;
    for(i=0;i<7;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<vector<int> > res;
    res = fourSum(arr,23);
    int j;
    for(i=0;i<res.size();i++)
    {
        for(j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
}
//10 2 3 4 5 7 8
