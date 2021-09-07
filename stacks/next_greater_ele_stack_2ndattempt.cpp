#include<bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr1, int n){
        // Your code here
        stack<int> pos;
        vector<long long> arr;
        for(int i=0;i<n;i++)
            arr.push_back(arr1[i]);
        for(int i=0;i<n;i++)
        {
            cout<<i<<endl;
            if(pos.empty())
            {
                pos.push(i);
            }
            else
            {
                if(arr[i]>arr[pos.top()])
                {
                    while(!pos.empty() && arr[pos.top()]<arr[i])
                    {
                        arr[pos.top()]=arr[i];
                        pos.pop();
                    }
                    pos.push(i);
                }
                else
                {
                    pos.push(i);
                    arr[pos.top()]=-1;
                }
            }
        }
        return arr;
    }
int main()
{
    vector<long long> a={6,8,0,1,3};
    vector<long long> res=nextLargerElement(a,5);
    for(int i=0;i<5;i++)
        cout<<res[i]<<"\t";
    return 0;
}
