#include <stdio.h>
#include <stdlib.h>
int g[100][100];
int V;
int visited[100];
int stack1[100];
int popseqn[100],pop=0;
int visit[100],visit1=0;
int top=0;
void dfsv(int v)
{
    int flag=0;
	printf("Pushed vertex %d\n", v);
	visit[visit1]=v;
	visit1++;
	visited[v] = 1;
	int i;
	stack1[top]=v;
	top++;
	for(i = 0; i < V; ++i)
	{
		if(!(visited[i]) && (g[v][i] == 1) && (i != v))
		{
  			dfsv(i);
		}
	}
	popseqn[pop]=v;
	pop++;
	top--;
}

void dfs()
{
	int i;

	for(i = 0; i < V; ++i)
	{
		if(!visited[i])
		{
  			dfsv(i);
		}
	}
}

int main()
{
	printf("Enter the Number of Vertices: \n");
	scanf("%d", &V);
	int i, j;
	printf("Enter the Adjacency Matrix: \n");
	for(i = 0; i < V; ++i)
	{
		for(j = 0; j < V; ++j)
        {
            scanf("%d", &g[i][j]);
        }
    }
    for(i=0;i<=V;i++)
        visited[i]=0;
	dfs();
	printf("Traversal sequence:\t");
	for(i=0;i<V;i++)
        printf("%d\t",visit[i]);
    printf("\n");
    printf("Pop sequence:\t");
	for(i=0;i<V;i++)
        printf("%d\t",popseqn[i]);
	return 0;
}
/*
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
