#include <bits/stdc++.h>
using namespace std;
int minDistance(int dist[], int inTree[],int V)
{
    int min = 999, min_index;
    for (int v = 0; v < V; v++)
        if (inTree[v] == -1 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(vector<vector<int>> graph, int src,int V)
{
    int dist[V], inTree[V], parent[V];
    for (int i = 0; i < V; i++) // initial values
        dist[i] = 999, parent[i] = -1, inTree[i] = -1;

    dist[src] = 0; // start vertex
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, inTree,V); // find next vertex
        inTree[u] = 1;                     // add u into the tree
        for (int v = 0; v < V; v++)        // update all minimum weights
            if (inTree[v] == -1 && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // update parent of v
            }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<vector<int>> arr(n, vector<int>(n, 999));
    for (int i = 0; i < n; i++)
    {
        int st, des, w;
        cin >> st >> des >> w;
        arr[st][des] = w;
        arr[des][st] = w;
    }
    dijkstra(arr,s,n);
    return 0;
}

for(int i=0;i<V-1;i++){
    int u = mindis(intree,dist,n)
    intree[U] = 1
    for(int j = 0;j<V;j++){
        if(intree[j==-1&&dist[u]+arr[U][v]<idst[v]])
    }
}