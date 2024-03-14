#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> adj[], int start, vector<int> &visited)
{
    visited[start] = 1;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (visited[adj[start][i]] == 0)
        {
            DFS(adj, adj[start][i], visited);
        }
    }
}
int main()
{
    int n, temp, index;
    cin >> n;
    vector<int> adj[n+1];
    vector<int> visited(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> index;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == 0)
            {
                break;
            }
            else
            {
                adj[index].push_back(temp);
            }
        }
    }

    int m;
    cin >> m;
    int ans[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ans[i];
    }
    for (int i = 0; i < m; i++)
    {
        DFS(adj, ans[i], visited);
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0)
            {
                cout << j << " ";
            }
            else
            {
                visited[j] = 0;
            }
        }
        cout << endl;
    }
    return 0;
}