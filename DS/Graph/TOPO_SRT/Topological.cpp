#include<bits/stdc++.h>
using namespace std;


class Graph{
    
    int V;
    list<int>* adj;


    public:
    Graph(int V)
    {
        this->V=V;
        adj= new list<int>[V];
    }



    void addEdge(int u,int v)
    {
         adj[u].push_back(v);
    }



    void Topological_sorting();
    void DFS(int i,stack<int>& Stack,bool visited[]);


};





void Graph::DFS(int i,stack<int>& Stack,bool visited[])
{
         
         // ** make node visited
          visited[i]=true;


          for(auto it=adj[i].begin();it!=adj[i].end();it++)
          {
              if(visited[*it]==false)
              {
                  DFS(*it,Stack,visited);
              }


          }



    /*
      ! this line is very important;
       ! bcs this line define that 0-degree node push stack after her adjacet node by returning from all recursive
    */
    Stack.push(i);


}



void Graph::Topological_sorting()
{
    // ** stack for storing sorting node;
       stack<int>Stack;



       //!! iiv...how to declear pointer array and size;
      // *Mark all the vertices as not visited
       bool* visited = new bool[V];
       for(int i=0;i<V;i++)
       {
          visited[i]=false;
       }



       for(int i=0;i<V;i++)
       {
               if(visited[i]==false)
               {
                     DFS(i,Stack,visited);
               }
       }




       //* printing  Topological sorting;
       while (Stack.size()!=0)
       {
           cout<<Stack.top()<<"->";
           Stack.pop();
       }
       cout<<endl;


       // ! use of pointer array is more efficitent that usring stl;
       delete[] visited;
       
}



int main()
{


    int node=6;
    Graph g(node);


    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);



    g.Topological_sorting();




}