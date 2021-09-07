#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int queuex[100];
int queuey[100];
int fx=0,rx=0,fy=0,ry=0;
int xm[8]={-2,-1,-2,1,2,-1,2,1};
int ym[8]={-1,-2,1,-2,-1,2,1,2};
int visit[10][10];
int target[2];
void enq(int x, int y)
{
    queuex[rx++]=x;
    queuey[ry++]=y;
}
int deqx()
{
    return queuex[fx++];
}
int deqy()
{
    return queuey[fy++];
}
void bfsv(int x,int y, int moves)
{
    int x1,y1,i;
    //cout<<x<<"\t"<<y<<endl;
    for(i=0;i<8;i++)
    {
        x1=x+xm[i];
        y1=y+ym[i];
        if(x1>=0 && y1>=0 && x1<=9 && y1<=9 )
        {

            if(visit[x1][y1]==0){
            enq(x1,y1);
            //if(x==2&&y==4)
            //cout<<x1<<"  "<<y1<<"\t"<<endl;
            visit[x1][y1]=moves;}
        }
    }
}
void bfs(int xi, int yi)
{
    int moves;
    int i, x, y;
    enq(xi,yi);
    //cout<<queuex[rx]<<"\t"<<queuey[ry]<<endl;
    do
    {
        x=deqx();
        y=deqy();
        moves=visit[x][y]+1;
        //cout<<x<<"\t"<<y<<endl;
        if(x==target[0]&&y==target[1])
        {
            cout<<visit[x][y]-1<<endl;
            return;
        }
        if(x >=0 && y>=0)
        {
            bfsv(x,y,moves);
        }
    }while (true);
}
int main()
{
    int mat[10][10];
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            visit[i][j]=0;

    int ini[2];
    cin>>ini[0]>>ini[1];
    visit[ini[0]][ini[1]]=1;
    cin>>target[0]>>target[1];
    bfs(ini[0],ini[1]);
    return 0;
}
