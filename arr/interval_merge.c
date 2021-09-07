#include<bits/stdc++.h>
using namespace std;
class interval
{
public:
    int start,end;
};
bool IntervalSort(interval a, interval b)
{
    if(a->start<b->start)
        return true;
    else
        return false;
}
int main()
{
    int n,i;
    cin>>n;
    interval a[n];
    for(i=0;i<n;i++)
    {
        a[i]=new interval();
        cin>>a[i]->start;
        cin>>a[i]->end;
    }
    sort(a,a+n,IntervalSort);
    return 0;
}
