#include<bits/stdc++.h>
using namespace std;
int un_kp(int price[], int length[], int w, int n)
{
    // w is length
    int i,j;
    int t[n+1][w+1];
    for(i=0;i<=n;i++)
        t[i][0]=0;
    for(i=0;i<=w;i++)
        t[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=w;j++)
        {
            if(length[i-1]<=j)
            {
                t[i][j]=max(price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
    cout << "Maximum obtained value  is "
         << un_kp(price, length, Max_len, n) << endl;
}
