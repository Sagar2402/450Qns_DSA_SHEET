#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[],int V)
{
    for(int v=0;v<V;v++)
    {
        int n=adj[v].size();
        for(int i=0;i<n;i++)
        {
            cout<<adj[v][i]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    print(adj,V);
    return 0;
}
