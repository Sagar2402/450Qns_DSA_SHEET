//valley peak approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int profit=0;
    for(int i=1;i<n;i++)
    {
        if(price[i]-price[i-1]>0)
        {
            profit+=price[i]-price[i-1];
        }
    }
    cout<<profit<<endl;
    return 0;
}

