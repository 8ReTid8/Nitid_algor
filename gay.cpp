#include <bits/stdc++.h>
using namespace std;
void Dijkstra(vector<pair<int,int>> adj[],int V,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,99999);
    vector<int> parent(V, -1);
    vector<bool> intree(V,false);

    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        intree[u] = true;
        pq.pop();
        for(int j =0;j<adj[u].size();j++){
            int v = adj[u][j].first;
            int weight = adj[u][j].second;
            if(intree[v] == false && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    for(int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
 }
int main(){
    int n = 5;

vector<pair<int, int > > adj[n];

adj[0].push_back({1, 5}); adj[1].push_back({0, 5});
adj[0].push_back({3, 9}); adj[3].push_back({0, 9});
adj[0].push_back({4, 1}); adj[4].push_back({0, 1});
adj[1].push_back({2, 2}); adj[2].push_back({1, 2});
adj[2].push_back({3, 6}); adj[3].push_back({2, 6});
adj[3].push_back({4, 2}); adj[4].push_back({3, 2});
Dijkstra(adj, n, 0);
}