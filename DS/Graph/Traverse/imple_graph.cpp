#include<bits/stdc++.h>
using namespace std;


struct  Graph
{
    int V;
    vector<vector<int>>adj;
    Graph(int v)
    {
        this->V=v;
        adj.resize(v);
    };


};


void add_edge(Graph& graph,int u,int v)
{
     graph.adj[u].push_back(v);
     graph.adj[v].push_back(u);
     
}





int main()
{
     int V = 5; // Number of vertices
    Graph graph(V);

    

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    // Print the adjacency list
    for (int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j : graph.adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}