#include<bits/stdc++.h>
using namespace std;
#define V 9
int minDist(int dist[], bool spset[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (spset[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool spset[V];
    int i;
    for(i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        spset[i]=false;
    }
    dist[src]=0;
    for(int cnt=0;cnt<V-2;cnt++)
    {
        int u=minDist(dist,spset);
        spset[u]=true;
        for(int v=0;v<V;v++)
        {
            if ((!spset[v]) && (graph[u][v]) && (dist[u] != INT_MAX) && (dist[u] + graph[u][v] < dist[v]))
                dist[v] = dist[u] + graph[u][v];
        }
    }
    for(i=0;i<V;i++)
    {
        cout<<i<<" : "<<dist[i]<<endl;
    }
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
    //0 is starting pt
    return 0;

}
