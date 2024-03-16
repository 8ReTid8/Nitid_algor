#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<pair<int, int>> adj[], int V, int src)
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
    return dist;
}

int main()
{
    int f, n;
    cin >> f >> n;
    int hospital[f];
    for (int i = 0; i < f; i++)
    {
        cin >> hospital[i];
    }
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        int s, d, l;
        cin >> s >> d >> l;
        adj[s].push_back({d, l});
        adj[d].push_back({s, l});
    }

    vector<int> roadmin (n+1,999);
    vector<int> temp(n+1);
    for(int i=0;i<f;i++){
        temp = Dijkstra(adj,n+1,hospital[i]);
        for(int j=1;j<roadmin.size();j++){
            roadmin[j] = min(roadmin[j],temp[j]);
        }
    }
    int sumAns = INT_MAX;
    int ans;
    for(int i=1;i<=n;i++){
        int tempSum = 0;
        temp = Dijkstra(adj,n+1,i);
        for(int j=1;j<roadmin.size();j++){
            tempSum += min(roadmin[j],temp[j]);
        }
        if(sumAns>tempSum){
            sumAns = tempSum;
            ans = i;
        }
    }
    cout<<ans;
    return 0;
}