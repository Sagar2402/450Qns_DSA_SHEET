#include<bits/stdc++.h>
using namespace std;
int cnt(int a[], int n, int diff)
{
    int sum=0,i,j;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int s2=diff+sum;
    s2/=2;

    int tab[n + 1][s2 + 1];
	tab[0][0] = 1;
	for (int i = 1; i <= s2; i++)
		tab[0][i] = 0;
	for (int i = 1; i <= n; i++)
		tab[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			if (a[i - 1] > j)
				tab[i][j] = tab[i - 1][j];
			else
			{
				tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
			}
		}
	}


	return tab[n][s2];
}
int main()
{
    int n,sum,i;
    cin>>n>>sum;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<cnt(arr,n,sum);
    return 0;
}
/*
4 1
1 1 2 3
*/
