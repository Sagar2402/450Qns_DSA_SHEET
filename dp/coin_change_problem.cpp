#include <bits/stdc++.h>
using namespace std;

int count( int S[], int m, int n )
{
 int table[n+1];
 memset(table, 0, sizeof(table));
 table[0] = 1;
 for(int i=0; i<m; i++)
 for(int j=S[i]; j<=n; j++)
 table[j] += table[j-S[i]];
 return table[n];
}
int countrecursive_notDP(int S[], int m, int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m<=0 && n>=1)
        return 0;
    return count(S,m-1,n)+ count(S,m,n-S[m-1]);

}



int main()
{
    int i, j;
    int m,n;
    cin>>m>>n;
    int arr[m];
    for(i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    cout <<count(arr, m, n);
    return 0;
}
/*
3 5
1 2 3
*/
