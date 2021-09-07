#include<bits/stdc++.h>
using namespace std;
bool visited[7][10];
int mx[]={-1,-1,-1,0,0,1,1,1}, my[]={-1,0,1,-1,1,-1,0,1};
void dfs(int M[7][10], int r, int c)
{
    int i,j;
    visited[r][c]=true;
    //cout<<r<<"\t"<<c<<endl;
    for(i=0;i<8;i++)
    {
        int x=r+mx[i];
        int y=c+my[i];
        if(x>=0 && y>=0 && visited[x][y]==false && M[x][y]==1 && x<7 && y<10)
        {
            //cout<<x<<"\t"<<y<<endl;
            dfs(M,x,y);
        }
    }
}
int main()
{
    int M[7][10];
    int i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<10;j++)
        {
            cin>>M[i][j];
            visited[i][j]=false;
        }
    }
    int cnt=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<10;j++)
        {
            if(M[i][j]==1 && visited[i][j]==false)
            {
                //cout<<"Island :"<<endl;
                dfs(M,i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
/*
1 0 0 0 0 1 0 0 0 1
1 0 1 1 1 1 1 0 0 1
1 1 1 1 1 0 0 0 1 0
1 1 1 0 1 0 0 1 0 1
0 1 0 1 0 0 0 1 0 0
0 0 0 0 0 1 1 1 1 0
0 0 1 1 0 0 0 1 0 0
*/
