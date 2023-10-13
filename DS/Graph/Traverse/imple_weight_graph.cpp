#include<bits/stdc++.h>
using namespace std;


// * create edges
struct Edge{
     int src,dest,weight;
};



//* create a graph
struct Graph{
     int Vertex,Edge;

     // ! Graph is represented as an array of edges.
    struct Edge* edge;

};



// *** function for create a graph and return a graph
struct Graph* CreateGraph(int V,int E)
{
     struct Graph*  graph = new Graph;
     graph->Edge=E;
     graph->Vertex=V;

      
      // ! creating edges array
     graph->edge= new Edge[graph->Edge];

     return graph; 
}




void setValueEdge(Graph* graph,int i,int s,int d,int w)
{
    graph->edge[i].src=s;
    graph->edge[i].dest=d;
    graph->edge[i].weight=w;
}


int main()
{


    Graph* graph =CreateGraph(4,5);
     

     setValueEdge(graph,0,0,3,3);
     setValueEdge(graph,1,0,2,-3);
     setValueEdge(graph,2,2,1,5);
     setValueEdge(graph,3,3,0,13);
     setValueEdge(graph,4,1,3,39);




     for(int i=0;i<5;i++){
         
         cout<<graph->edge[i].src<<" "<<graph->edge[i].dest<<" "<<graph->edge[i].weight<<endl;
     }
}