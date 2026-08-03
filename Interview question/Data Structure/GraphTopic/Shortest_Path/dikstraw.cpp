#include <bits/stdc++.h>
using namespace std;
#define V 9

//! =========== sigle souce shortest path=====
int findminNode(vector<int> &dist, vector<bool> &visited)
{
    int index = -1;
    int minV = INT_MAX;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < minV)
        {
            index = i;
            minV = dist[i];
        }
    }

    return index;
}

void dijkstra(int graph[V][V], int src,int targetNode)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int>parent(V,-1);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int minNode = findminNode(dist, visited);
        

        visited[minNode] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[minNode][v] != 0 &&
                dist[v] > dist[minNode] + graph[minNode][v])
            {
                dist[v] = dist[minNode] + graph[minNode][v];
                //parent track
                parent[v]=minNode;
            }
        }
    }

    cout << "Shortest path from node " << src << ": ";
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << "\n";

    cout<<endl<<endl;
   
    cout<<"target node spt ; "<<dist[targetNode]<<endl;
    cout<<"target node shortest path: ";

     stack<int>path;
     while (parent[targetNode]!=-1)
     {
         path.push(targetNode);
         targetNode=parent[targetNode];
     }

      while(!path.empty())
          {
            cout<<path.top()<<" -> ";
            path.pop();
          }
     

}

int main()
{
    int graph[V][V] =
        {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph,0, 8);

    return 0;
}
