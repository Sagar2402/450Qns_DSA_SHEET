#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    maxheap.push(2);
    maxheap.push(1);
    maxheap.push(3);
    minheap.push(2);
    minheap.push(1);
    minheap.push(3);
    while(maxheap.size()!=0)
    {
        cout<<maxheap.top();
        maxheap.pop();
    }
    while(minheap.size()!=0)
    {
        cout<<minheap.top();
        minheap.pop();
    }
}
