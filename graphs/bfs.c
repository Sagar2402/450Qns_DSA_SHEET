#include <stdio.h>
#include <stdlib.h>
int g[100][100];
int V;
int visited[10][10];
int queue[100], f = 0, r = 0;
int visitseqn[100],visit=0;
void enqueue(int v)
{
    queue[r++] = v;
}
int dequeue()
{
    if(f == r)
        return -1;
    return queue[f++];
}
void bfsv(int v)
{
    visitseqn[visit]=v;
    visit++;
    visited[v] = 1;
    int i;
    for(i = 0; i < V; ++i)
    {
        if(!visited[i] && g[v][i] && i != v)
        {
            enqueue(i);
        }
    }
}
void bfs()
{
    int i, x;
    enqueue(0);
    do
    {
    x = dequeuex();
    y=dequeuey();
    if(x >=0 && y>=0 && visited[x][y]==0)
    {
        bfsv(x,y);
    }

    }while (x != -1);
}
void main()
{
    printf("Enter the Number of Vertices : \n");
    scanf(" %d", &V);
    int i, j;
    printf("Enter the Adjacency Matrix: \n");
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            scanf(" %d", &g[i][j]);
        }
    }
    bfs();
    printf("\nVisit sequence:\n");
    for(i=0;i<V;i++)
        printf("%d\t",visitseqn[i]);


}
/*
0 1 0 1 0 0 0 0 1
1 0 0 0 0 0 0 1 0
0 0 0 1 0 1 0 1 0
1 0 1 0 1 0 0 0 0
0 0 0 1 0 0 0 0 1
0 0 1 0 0 0 1 0 0
0 0 0 0 0 1 0 0 0
0 1 1 0 0 0 0 0 0
1 0 0 0 1 0 0 0 0



0 1 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0
0 0 0 1 1 1 0 0 1
0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0
0 0 1 0 0 0 1 0 0
0 0 0 0 0 1 0 1 1
0 0 0 0 1 0 1 0 0
1 0 1 0 0 0 1 0 0
*/
