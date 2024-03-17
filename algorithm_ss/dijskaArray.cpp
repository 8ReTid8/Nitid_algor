#include <bits/stdc++.h>
using namespace std;
int minDistance(int dist[], int inTree[], int V)
{
    int min = 999, min_index;
    for (int v = 0; v < V; v++)
        if (inTree[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dist[V], inTree[V], parent[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = 999;
        parent[i] = -1;
        inTree[i] = 0;
    }

    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, inTree, V);
        inTree[u] = 1;
        for (int v = 0; v < V; v++)
            if (inTree[v] == 0 && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                
                parent[v] = u;
            }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n,999));
    for (int i = 0; i < m; i++)
    {
        int start, des, w;
        cin >> start >> des >> w;
        adj[start][des] = w;
        adj[des][start] = w;
    }
    dijkstra(adj,1,n);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}