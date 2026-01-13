#include <bits/stdc++.h>
using namespace std;
#define V 4


//!================= Directed Graph
/*
 ! approch:
  1. backed edge detection
  2.ind (i,j) and (j,i) path
  3. topological sorting
*/
//!----------- ( Backed edge detection )
vector<vector<int>> makeGraph(vector<vector<int>> &edges)
{

  vector<vector<int>> graph(V, vector<int>());

  for (int i = 0; i < edges.size(); i++)
  {
    graph[edges[i][0]].push_back(edges[i][1]);
  }

  return graph;
}

bool BackedEdgeDetection(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &path, int src)
{

  //* if curr src is already in path,that means  backed edge find,cycle detect
  if (path[src] == true)
    return true;

  //* if node already  visited;
  if (visited[src] == true)
    return false;

  // if not viisted node make it visited and add in path
  visited[src] = true;
  path[src] = true;

  for (auto &x : graph[src])
  {

    //! if backed edge find
    if (BackedEdgeDetection(graph, visited, path, src) == true)
    {
      return true;
    }
  }

  // ! out the curr  src from path
  path[src] = false;

  // not backed edge find for this src;
  return false;
}

bool DG_CycleCheck_by_BackedEdge(vector<vector<int>> &edges)
{

  //* make graph
  vector<vector<int>> graph = makeGraph(edges);

  // * track visitd node
  vector<bool> visited(V, false);
  //* recursively path stack to detect backed edge
  vector<bool> path(V, false);

  for (int i = 0; i < V; i++)
  {

    // if  i not yet traver and get backed edge for i
    if (visited[i] == false && BackedEdgeDetection(graph, visited, path, i) == true)
    {
      return true;
    }
  }

  return false;
}

//!====================================== UnDirected Graph 
/*
! approch:---
 1. dfs with parent check
 2. bfs with parent
*/


//! -------------- (DFS)----------------
vector<vector<int>> makeGraph_UD(vector<vector<int>> &edges)
{

  vector<vector<int>> graph(V, vector<int>());

  for (int i = 0; i < edges.size(); i++)
  {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }

  return graph;
}

bool UDG_CycleDetection_DFS(vector<vector<int>> &graph, vector<bool> &visited, int parent, int src)
{

  visited[src] = true;

  for (auto nbr : graph[src])
  {
    //if visited and perent and child not same ,that means it a ccycle
    if (visited[nbr] == true && parent != nbr)
    {
      return true;
    }

    if (!visited[nbr])
    {

      if (UDG_CycleDetection_DFS(graph, visited, src, nbr))
      {
        return true;
      }
    }
  }

  return false;
}

bool CycleDetection_Undirected_DFS(vector<vector<int>> &edges)
{

  vector<vector<int>> graph = makeGraph_UD(edges);

  // root no parent
  int parent = -1;
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++)
  {

    if (visited[i] == false && UDG_CycleDetection_DFS(graph, visited, parent, i))
      ;
    {
      return true;
    }
  }

  return false;
}


//!---------------- (bfs)---------
bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } 
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}



 


int main()
{

  // ***  importannt concept:
  /*
   ! if data giva as edge ,then make it graph
   ! convert graph to adjacent list
  */

  // Directed edges of the graph
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

  // cout << DG_CycleCheck_by_BackedEdge(edges);
  cout << CycleDetection_Undirected_DFS(edges);
}