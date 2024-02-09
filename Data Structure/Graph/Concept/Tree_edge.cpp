#include<bits/stdc++.h>
using namespace std;

static int v=10;

void addedge(vector<vector<int>> & graph,int w,int v)
{
     graph[w].push_back(v);
     graph[v].push_back(w);
}





void DFS(vector<vector<int>>& graph,vector<bool>& visited,set<pair<int,int>>& treeEdges,int i)
{

      visited[i]=true;

      for(int v:graph[i])
      {
        // as we findout tree node ,
        //so a node in tree not comes more than one time
        // it its visit past,then not include it
        if(visited[v]==false)
        {
             //stor as treeEdge
            if(treeEdges.count({i,v})==0 && treeEdges.count({v,i})==0) 
            {
                treeEdges.insert({i,v});
            } 

            DFS(graph,visited,treeEdges,v);


        }
      }
}






void FindAllTreeEdge(vector<vector<int>>& graph)
{
                   

       vector<bool>visited(v,false);
       //for store TreeEdge
       set<pair<int,int>>treeEdges;

       for(int i=0;i<v;i++)
       {
              if(visited[i]==false)
              {
                DFS(graph,visited,treeEdges,i);
              }
       }



    cout << "Edges in the tree:\n";
    for (auto& edge : treeEdges) {
        cout << edge.first << " - " << edge.second << "\n";
    }

       
      
}




 int main(int argc, const char** argv) {

        
        
        vector<vector<int>>graph(v,vector<int>());

        addedge(graph,0,2);
        addedge(graph,0,1);
        addedge(graph,1,4);
        addedge(graph,1,5);
        addedge(graph,2,6);
        addedge(graph,2,7);
        addedge(graph,6,3);
        addedge(graph,3,7);
        addedge(graph,1,2);


        FindAllTreeEdge(graph);







       



 
    return 0;
}