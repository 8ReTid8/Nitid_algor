#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
void DFS(vector<int> adj[], int start, int end, vector<int> visited, int count)
{
    count++;
    if (start == end)
    {
        ans = min(count, ans);
        return;
    }
    visited[start] = 1;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (visited[adj[start][i]] == 0)
        {
            // cout<<adj[start][i]<<" ";
            DFS(adj, adj[start][i], end, visited, count);
        }
    }
    visited[start] = 0;
}
int main()
{
    int n, temp, index;
    cin >> n;
    vector<int> adj[n];
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> index;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == -1)
            {
                break;
            }
            else
            {
                adj[index].push_back(temp);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j];
    //     }
    //     cout<<endl;
    // }
    int start, end;
    cin >> start >> end;
    DFS(adj, start, end, visited, -1);
    cout << ans;
    return 0;
}