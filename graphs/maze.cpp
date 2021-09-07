#include<bits/stdc++.h>
using namespace std;
int mat[4][4];
int visit[4][4];
int ini[2],target[2];
int mx[4]={1,0,0,-1};
int my[4]={0,-1,1,0};
char mov[4]={'B','L','R','T'};
int stackx[16];
int stacky[16];
char stack1[16];
int tos=0;
int tosx=0,tosy=0;
void prints()
{
    int i=0;
    while(i<=tos)
    {
        cout<<stack1[i]<<"\t";
        i++;
    }
    cout<<endl;
}
void dfsv(int xi, int yi)
{
    int x,y;
    int i,j;
    for(i=0;i<4;i++)
    {
        x=xi+mx[i];
        y=yi+my[i];
        if(x>=0 && y>=0 && x<=3 && y<=3 && mat[x][y]==1 && visit[x][y]==0)
        {
            cout<<x<<"  "<<y<<endl;
            visit[x][y]=1;
            stackx[tosx++]=x;
            stacky[tosy++]=y;
            stack1[tos++]=mov[i];

            if(x==target[0]&&y==target[1])
            {
                prints();
                //return;
            }

            dfsv(x,y);
            tosx--;
            tosy--;
            tos--;
        }
    }
}
int main()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin>>mat[i][j];
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            visit[i][j]=0;
    cin>>ini[0]>>ini[1];
    cin>>target[0]>>target[1];
    visit[ini[0]][ini[1]]=1;
    dfsv(ini[0],ini[1]);
    return 0;
}
/*
1 0 0 1
1 1 1 0
1 0 1 0
1 1 1 1
0 0
3 3
*/
