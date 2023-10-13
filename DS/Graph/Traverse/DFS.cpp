#include<bits/stdc++.h>
using namespace std;


class Graph{

     map<int,bool>visited;
     map<int,list<int>>adj;

     public:
   
     void addEdge(int v,int u);
     void DFS(int s);
     
};




void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}





void Graph::DFS(int s)
{
     visited[s]=true;
     cout<<s<<" ";

     for(auto it:adj[s])
     {
         if(!visited[it])
         {
            DFS(it);
         }
     }
    
}




int main()
{ 

     /*
       !https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
       !https://cp-algorithms.com/graph/breadth-first-search.html#breadth-first-search
    */
    
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}