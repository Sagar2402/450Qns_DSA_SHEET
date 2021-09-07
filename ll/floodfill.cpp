//4dir up down left right
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int xm[4]={1,0,-1,0};
int ym[4]={0,1,0,-1};
int mat[5][5];
int visit[5][5];
int qx[25],qy[25];
int fx=0,rx=0,fy=0,ry=0;
int sr,sc,col;
void enq(int x, int y)
{
    qx[rx++]=x;
    qy[ry++]=y;
    visit[x][y]=1;
}
int deqx()
{
    if(fx==rx)
        return -1;
    return qx[fx++];
}
int deqy()
{
    if(fy==ry)
        return -1;
    return qy[fy++];
}
void bfsv(int x, int y)
{
    int x1,y1,i;
    for(i=0;i<4;i++)
    {
        x1=x+xm[i];
        y1=y+ym[i];
        if(x1>=0 && y1>=0)
        {
            if((mat[sr][sc]==mat[x1][y1]) && visit[x1][y1]!=1)
            {
                enq(x1,y1);
                mat[x1][y1]=col;
            }
        }
    }

}
void bfs(int xi,int yi)
{
    enq(xi,yi);
    int x,y;
    do
    {
        x=deqx();
        y=deqy();
        cout<<x<<" "<<y<<endl;
        if(x>=0 && y>=0 && x<=4 && y<=4)
        {
            bfsv(x,y);
        }

    }while(x!=-1 && y!=-1);
}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>mat[i][j];
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            visit[i][j]=0;
    cin>>sr>>sc>>col;
    bfs(sr,sc);
    mat[sr][sc]=col;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<mat[i][j];}
                cout<<endl;}
    return 0;
}
/*
0 0 0 0 0
0 1 1 1 0
0 1 1 0 0
0 1 0 1 0
0 0 0 0 0
2 2 2
*/

