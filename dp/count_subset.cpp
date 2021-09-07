#include<bits/stdc++.h>
using namespace std;
int subsetsum(int a[], int n, int sum)
{
    int tab[n + 1][sum + 1];
	tab[0][0] = 1;
	for (int i = 1; i <= sum; i++)
		tab[0][i] = 0;
	for (int i = 1; i <= n; i++)
		tab[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (a[i - 1] > j)
				tab[i][j] = tab[i - 1][j];
			else
			{
				tab[i][j] = tab[i - 1][j] + tab[i-1][j - a[i - 1]];
			}
		}
	}


	return tab[n][sum];
}
int main()
{
    int n,sum,i;
    cin>>n>>sum;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<subsetsum(arr,n,sum);
    return 0;
}
/*
6 12
2 3 4 7 8 10

*/
