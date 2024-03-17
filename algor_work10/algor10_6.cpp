#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Define infinity as a very large number
const int INF = numeric_limits<int>::max();

// Define a structure to represent edges
struct Edge {
    int destination;
    int weight;
};

// Define a structure to represent vertices
struct Vertex {
    vector<Edge> edges;
};

// Dijkstra's Algorithm
int shortestPath(const vector<Vertex>& graph, int source, int destination, int capacity, int passengers) {
    // Initialize distances and visited flags
    vector<vector<int>> distances(graph.size(), vector<int>(passengers + 1, INF));
    vector<vector<bool>> visited(graph.size(), vector<bool>(passengers + 1, false));

    // Priority queue to select the vertex with the smallest distance
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Push the source vertex into the priority queue
    pq.push({0, source, 0});
    distances[source][0] = 0;

    while (!pq.empty()) {
        // Extract the vertex with the smallest distance
        auto [dist, u, passengers_left] = pq.top();
        pq.pop();

        // If the destination is reached, return the distance
        if (u == destination) return dist;

        // Skip if this state is already visited
        if (visited[u][passengers_left]) continue;
        visited[u][passengers_left] = true;

        // Iterate through all neighboring vertices
        for (const Edge& edge : graph[u].edges) {
            int v = edge.destination;
            int w = edge.weight;

            // Calculate the new number of passengers
            int new_passengers_left = min(passengers + 1, passengers_left + w);

            // Relax the edge if a shorter path is found
            if (!visited[v][new_passengers_left] && dist + 1 < distances[v][new_passengers_left]) {
                distances[v][new_passengers_left] = dist + 1;
                pq.push({dist + 1, v, new_passengers_left});
            }
        }
    }

    // If destination is unreachable, return -1
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Create the graph
    vector<Vertex> graph(n);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].edges.push_back({v, weight});
        graph[v].edges.push_back({u, weight});
    }

    int source, destination, passengers;
    cin >> source >> destination >> passengers;

    // Find the minimum number of rounds required
    int min_rounds = shortestPath(graph, source, destination, 0, passengers);

    cout << min_rounds << endl;

    return 0;
}
