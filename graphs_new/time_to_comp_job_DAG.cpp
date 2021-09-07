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
    vector<int> result(V,0);
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
        {
            q.push(i);
            result[i]=1;
        }
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
        {
            if (--indegree[*itr] == 0)
            {
                result[*itr]=result[u]+1;
                q.push(*itr);
            }
        }
        cnt++;
    }
    if(cnt!=V)
    {
        cout<<"THere is a cycle;;;graph shud be acyclic"<<endl;
        return;
    }
    for(int i=0;i<V;i++)
    {
        cout<<result[i]<<"\t";
    }
}
int main()
{
    graph g(10);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 9);
    g.toposort();
    return 0;
}

