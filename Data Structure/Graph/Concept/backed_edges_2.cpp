#include<bits/stdc++.h>
using namespace std;

static int V = 10; // Renamed v to V to avoid conflict

void addedge(vector<vector<int>> & graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS(vector<vector<int>>& graph, vector<bool>& visited, vector<pair<int,int>>& backedges, set<int>& parent, int u, int parent_vertex) {
    visited[u] = true;

    for(int v : graph[u]) {
        if(visited[v] && v != parent_vertex) { // Check if v is visited and not the parent
            backedges.push_back({u, v});
        } else if(!visited[v]) {
            DFS(graph, visited, backedges, parent, v, u); // Pass u as parent_vertex to the recursive call
        }
    }

    visited[u] = false; // Backtrack
}

void FindAllBackedEdge(vector<vector<int>>& graph) {
    vector<bool> visited(V, false);
    set<int> parent;
    vector<pair<int,int>> backedges;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS(graph, visited, backedges, parent, i, -1); // Pass -1 as parent for the starting vertex
        }
    }

    cout << "Back edges: \n";
    for(pair<int,int> edge : backedges) {
        cout << edge.first << " -> " << edge.second << endl;
    }
}

int main(int argc, const char** argv) {
    vector<vector<int>> graph(V, vector<int>());

    // this code not give path

    addedge(graph, 0, 2);
    addedge(graph, 0, 1);
    addedge(graph, 1, 4);
    addedge(graph, 1, 5);
    addedge(graph, 2, 6);
    addedge(graph, 2, 7);
    addedge(graph, 6, 3);
    addedge(graph, 3, 7);
    addedge(graph, 1, 2);

    FindAllBackedEdge(graph);

    return 0;
}
