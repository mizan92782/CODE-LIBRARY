#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

// Data structure to represent a weighted edge
struct Edge {
    int source, destination, weight;
};

// Function to find the shortest paths from a given source vertex
void BellmanFord(vector<Edge>& edges, int V, int E, int source, int target) {
    vector<int> distance(V, INT_MAX);

    // for tracking path
    vector<int> parent(V, -1);
    distance[source] = 0;

    // Relax all edges V - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    
    

    // Print the shortest path
    if (distance[target] == INT_MAX) {
        cout << "No path from source to target" << endl;
    } else {
        cout << "Shortest path from source to target:" << endl;
        stack<int> path;
        int current = target;
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }
        cout << "Path: ";
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
        cout << "Shortest distance: " << distance[target] << endl;
    }
}

// Driver code
int main() {
    // Example graph represented by edges
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, -2}, {1, 3, 4},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -5}
    };

    int V = 5; // Number of vertices in the graph
    int E = edges.size(); // Number of edges in the graph

    // Source and target vertex
    int source = 0;
    int target = 2;

    // Run the Bellman-Ford algorithm and print the path
    BellmanFord(edges, V, E, source, target);

    return 0;
}
