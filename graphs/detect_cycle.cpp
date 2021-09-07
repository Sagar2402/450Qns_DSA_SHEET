//check whether a directioned graph is cyclic or not
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int mat[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int visited[n];
    for(i=0;i<n;i++)
        visited[i]=0;
    int flag=0;
    for(i=0;i<n&&flag==0;i++)
    {
        int k=i;
        for(j=0;j<n;j++)
        {
            if(mat[k][j]==1&&visited[j]==0&&j!=i)
            {
                cout<<k<<" "<<j<<endl;
                visited[j]=1;
                k=j;
                j=0;
                continue;
            }

            if(mat[k][j]==1 && j==i)
            {
                flag=1;
                break;
            }
        }
        for(k=i;k<n;k++)
            visited[k]=0;
    }
    if(flag==1)
        cout<<"Cyclic"<<endl;
    else
        cout<<"Not Cyclic"<<endl;

    return 0;
}
