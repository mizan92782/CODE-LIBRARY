#include<bits/stdc++.h>
using namespace std;


class Graph{

     int V;
     vector<list<int>>adj;

     public:
     Graph(int v);
     void addEdge(int v,int u);
     void BFS(int s);
     
};




Graph::Graph(int v){
    this->V=v;
    adj.resize(v);
}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}





void Graph::BFS(int s)
{
     queue<int>que;
     vector<int>visited(V,false);

     que.push(s);
     visited[s]=true;
   
    

    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        cout<<x<<" ";

       for(auto it:adj[x]){

        if(!visited[it])
        {
            que.push(it);
            visited[it]=true;
        }
       }

        
    }
    
}




int main()
{ 

     /*
       !https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
       !https://cp-algorithms.com/graph/breadth-first-search.html#breadth-first-search
    */
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}