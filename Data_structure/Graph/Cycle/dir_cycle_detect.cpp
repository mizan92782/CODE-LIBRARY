
#include<bits/stdc++.h>
using namespace std;


class Graph{
     int V;
     map<int,list<int>>adj;
     
      
     

     bool isCycleutil(int u,vector<bool>visited,vector<bool>recSta);
     public:
     Graph(int v);
     void addEdge(int u,int v);
     bool isCycle();
};



Graph::Graph(int v)
{
     this->V=v;
}



void Graph::addEdge(int u,int v)
{
     adj[u].push_back(v);
}



bool Graph::isCycleutil(int u,vector<bool>visited,vector<bool>recSta)
{
          
          if(!visited[u])
          {
              
               visited[u]=true;
               recSta[u]=true;

               for(auto it=adj[u].begin();it!=adj[u].end();it++)
               {
                      if(!visited[*it] && isCycleutil(*it,visited,recSta))
                      {
                        return true;
                      }else if(recSta[*it])
                      {
                        return true;
                      }
               }
          }


    recSta[u]=false;
    return false;
}

bool Graph::isCycle()
{
      vector<bool>visited(V,false);
      vector<bool>recSta(V,false);


      for(int i=0;i<V;i++)
      {
         if(!visited[i] && isCycleutil(i,visited,recSta))
         {
            return true;
         }
      }


      return false;
}


int main(){


          //https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);


    if(g.isCycle())
    {
        cout<<"there is a cycle";
    }else{
         cout<<"there is no cycle";
    }
    
}



