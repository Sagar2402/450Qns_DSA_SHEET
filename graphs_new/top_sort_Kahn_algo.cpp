#include<bits/stdc++.h>
using namespace std;
class graph
{
    int V;
    list<int>* adj;
public:
    graph(int v);
    void addEdge(int u, int v);
    void toposort();
};
graph::graph(int v)
{
    V=v;
    adj=new list<int>[V];
}
void graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void graph::toposort()
{
    vector<int> indegree(V,0);
    for(int u=0;u<V;u++)
    {
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++)
        {
            indegree[*i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int cnt=0;
    vector<int> toporder;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        toporder.push_back(u);
        list<int>::iterator itr;
        for (itr = adj[u].begin();itr != adj[u].end(); itr++)
            if (--indegree[*itr] == 0)
                q.push(*itr);
        cnt++;
    }
    if(cnt!=V)
    {
        cout<<"THere is a cycle;;;graph shud be acyclic"<<endl;
        return;
    }
    for(int i=0;i<V;i++)
    {
        cout<<toporder[i]<<"\t";
    }
}
int main()
{
    graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.toposort();
    return 0;
}
