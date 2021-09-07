#include<bits/stdc++.h>
using namespace std;
int getMaxArea(int hist[], int n)
{
    stack<int> s;

    int max_area = 0; // Initialize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar

    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top

            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}
int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<getMaxArea(arr,n);
    return 0;
}
