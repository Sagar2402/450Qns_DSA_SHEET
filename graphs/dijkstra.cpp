#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mat[6][6];
void dij(int mat[6][6], int j)
{
    int mini=9999,i;
    for(i=0;i<6;i++)
    {
        if(mini>mat[j][i]&&mat[j][i]!=0 && mat[j][i]!=-1)
        {
            mini=mat[j][i];
            return i;
        }
    }

}
int main()
{
    int i,j,k;
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            cin>>mat[i][j];

    dij(mat,0);
    return 0;
}
/*
0 2 4 -1 -1 -1
-1 0 1 7 -1 -1
-1 -1 0 -1 3 -1
-1 -1 -1 0 -1 1
-1 -1 -1 2 0 5
-1 -1 -1 -1 -1 0
*/
