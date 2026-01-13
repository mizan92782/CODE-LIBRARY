#include <bits/stdc++.h>
using namespace std;
#define V 6

//! ----------Graph
vector<vector<int>> graph(V, vector<int>());

//!------------- undirected unweight graph edge connect
void addEdgeUU(int u, int v)
{
  graph[u].push_back(v);
  graph[v].push_back(u);
}

//!--------------------BFS connected graph

void BFS(int source)
{

  queue<int> que;
  // for check visisted note
  vector<int> visited(V, false);
  // Bfs resutl
  vector<int> result;

  // for sources
  que.push(source);
  visited[source] = true;

  while (!que.empty())
  {
    int curr = que.front();
    que.pop();

    // save resutl
    result.push_back(curr);

    // get all connected nodes of cuurent node
    for (auto &node : graph[curr])
    {
      if (!visited[node])
      {
        // make visited
        visited[node] = true;
        que.push(node);
      }
    }
  }
}


//!----------------------- nodes lavel in BFS
void BFSWithNodeLavel(int source)
{

  queue<pair<int,int>> que;
  // for check visisted note
  vector<int> visited(V, false);
  // Bfs resutl
  vector<pair<int,int>> result;

  // for sources and level for souce is 1
  que.push({source,1});
  visited[source] = true;

  while (!que.empty())
  {
    pair<int,int>x = que.front();
    int curr =x.first;
    int lavel=x.second;
    que.pop();

    // save resutl
    result.push_back({curr,lavel});

    // get all connected nodes of cuurent node
    for (auto &node : graph[curr])
    {
      if (!visited[node])
      {
        // make visited
        visited[node] = true;
        que.push({node,lavel+1});
      }
    }
  }


  cout<<"BFS : node lavel "<<endl;
  for(auto& x: result){
    cout<<"node : "<<x.first<<"  -->  lavel  : "<<x.second<<endl;
  }

}


//!------------------------ BFS for Disconnected Graph
 void bfs(int s, 
        vector<bool>& visited, vector<int> &res) {

    // Create a queue for BFS
    queue<int> q; 

    // Mark source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {

        // Dequeue a vertex and store it
        int curr = q.front(); 
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : graph[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
                      
// Perform BFS for the entire graph which maybe
// disconnected
vector<int> bfsDisconnected(vector<vector<int>>& adj) {
    

    // create an array to store the traversal
    vector<int> res;

    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false); 

    // perform BFS for each node
    //! also it can use for ,to check that graph is connectd ot not
    //! and count the part of graph
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(i, visited, res);
        }
    }

    return res;
}


//!================================== DFS

void DFSUtil(vector<int>& result,vector<bool>& visited,int src){
      
       visited[src]=true;
       result.push_back(src);

       for(auto& node : graph[src]){
            if(visited[node]==false){
                DFSUtil(result,visited,node);
            }
       }

  
}

void DFS(int sources){

     vector<int> result;
     vector<bool>visited(V,false);

     DFSUtil(result,visited,sources);

     cout<<"DFS :  "<<endl;
     for(auto& x: result){
     cout<<x<<" ";
     }
}







/*
*
*
*
*
*
*
*
*
*
*
*
*

*/

int main()
{

  addEdgeUU(0, 1);
  addEdgeUU(0, 2);
  addEdgeUU(0, 3);

  addEdgeUU(1, 5);
  addEdgeUU(2, 5);
  addEdgeUU(2, 4);

  addEdgeUU(3, 5);

   /*
      

   */

  //BFS(3);
 // BFSWithNodeLavel(0);
   DFS(1);
}