#include <bits/stdc++.h>
using namespace std;
void Dijkstra(vector<pair<int, int>> adj[], int V, int src,int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 999);
    vector<int> parent(V, -1);
    vector<bool> intree(V, false);
    pq.push({0, src}); 
    dist[src] = 0;     
    while (!pq.empty())
    {
        int u = pq.top().second; 
        intree[u] = true;
        pq.pop();
        for (int j = 0; j < adj[u].size(); ++j)
        {
            int v = adj[u][j].first; 
            int weight = adj[u][j].second;
            if (intree[v] == false && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; 
                pq.push({dist[v], v});      
                parent[v] = u;
            }
        }
    }
    cout<<dist[end]<<endl;
}

int main()
{
    int Connect;
    cin >> Connect;
    for (int i = 0; i < Connect; i++)
    {
        int n, m, start, end;
        cin >> n >> m >> start >> end;
        vector<pair<int, int>> adj[n];
        for (int j = 0; j < m; j++)
        {
            int a, b, wt;
            cin >> a >> b >> wt;
            adj[a].push_back({b, wt});
            adj[b].push_back({a, wt});
        }
        Dijkstra(adj,n,start,end);
    }
    return 0;
}