#include<bits/stdc++.h>
using namespace std;
class interval
{
public:
    int start,end;
};
bool IntervalSort(interval a, interval b)
{
    if(a.start < b.start)
        return true;
    else if(b.start>a.start)
        return false;
    else
        return (a.end<b.end);
}
int main()
{
    int n,i;
    cin>>n;
    interval a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i].start;
        cin>>a[i].end;
    }
    sort(a,a+n,IntervalSort);
    stack <interval> s;
    s.push(a[0]);
    for(i=1;i<n;i++)
    {
        if(s.top().end > a[i].start)
        {
            interval b=s.top();
            s.pop();
            b.end=a[i].end;
            s.push(b);
        }
        else
        {
            s.push(a[i]);
        }
    }
    while(!s.empty())
    {
        cout<<s.top().start<<"\t"<<s.top().end<<endl;
        s.pop();
    }
    /*for(i=0;i<n;i++)
    {
        cout<<a[i].start<<"\t"<<a[i].end;
        cout<<endl;
    }*/
    return 0;
}
//for merging in place
/*
void mergeIntervals(Interval arr[], int n)
{
    // Sort Intervals in increasing order of
    // start time
    sort(arr, arr+n, mycomp);

    int index = 0; // Stores index of last element
    // in output array (modified arr[])

    // Traverse all input Intervals
    for (int i=1; i<n; i++)
    {
        // If this is not first Interval and overlaps
        // with the previous one
        if (arr[index].e >=  arr[i].s)
        {
               // Merge previous and current Intervals
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else {
            index++;
            arr[index] = arr[i];
        }
    }

    // Now arr[0..index-1] stores the merged Intervals
    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}
*/
