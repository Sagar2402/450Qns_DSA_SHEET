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
void dfs(vector<int> adj[], int st,int V)
{
    vector<bool> visited(V, false);
    stack<int> s;
    s.push(st);
    while(s.empty()==false)
    {
        st=s.top();
        s.pop();
        if(visited[st]==false)
        {
            visited[st]=true;
            cout<<st<<"\t";
        }
        int i=0;
        int n=adj[st].size();
        for(i=n-1;i>=0;i--)
        {
            if(visited[adj[st][i]]==false)
                s.push(adj[st][i]);
        }
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
    dfs(adj,0,V);
    return 0;
}
