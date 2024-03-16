#include <bits/stdc++.h>
using namespace std;
// kruskal
// int find(vector<int> &parent, int i)
// {
//     if (parent[i] == i)
//     {
//         return i;
//     }
//     return find(parent, parent[i]);
// }
// void union1(vector<int> &parent, int x, int y)
// {
//     int xroot = find(parent, x);
//     int yroot = find(parent, y);
//     parent[xroot] = yroot;
// }
// int is_cycle(vector<int> &parent, int u, int v)
// {
//     int x = find(parent, u);
//     int y = find(parent, v);
//     return (x == y) ? true : false;
// }
// void kruskal(vector<pair<int, int>> adj[], int V)
// {
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//     vector<int> parent(V);
//     for (int i = 0; i < V; ++i)
//     {
//         parent[i] = i;
//     }
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < adj[i].size(); j++)
//             pq.push({adj[i][j].second, {i, adj[i][j].first}});
//     }
//     int ne = 0;
//     while (ne < V - 1)
//     {
//         int u = pq.top().second.first;
//         int v = pq.top().second.second;
//         int w = pq.top().first;
//         pq.pop();
//         if (!is_cycle(parent, u, v))
//         {
//             ne++;
//             union1(parent, u, v);
//             cout << "(" << u << "," << v << "," << w << ")" << endl;
//         }
//     }
// }

// prim

int Count = 0;
void Prim(vector<pair<int, int>> adj[], int V, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, 999);      // keep distance of vertex
    vector<int> parent(V, -1);    // keep path of MST
    vector<bool> inMST(V, false); // keep status of vertex
    pq.push({0, src});
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second; 
        pq.pop();
        inMST[u] = true; 
        for (int j = 0; j < adj[u].size(); ++j)
        {
            int v = adj[u][j].first; 
            int weight = adj[u][j].second;
            if (inMST[v] == false && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v}); 
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<V;i++){
        if(key[i]!=0){
            Count += key[i]-1;
        }
        // cout<<key[i]<<" ";
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int s, d, l;
        cin >> s >> d >> l;
        adj[s].push_back({d, l});
        adj[d].push_back({s, l});
    }
    Prim(adj,n+1,1);
    cout<<Count;
    return 0;
}
