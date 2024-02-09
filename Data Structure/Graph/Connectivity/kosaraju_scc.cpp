
#include<bits/stdc++.h>
using namespace  std;


void addedge(vector<vector<int>>& graph,int u,int v)
{
      graph[u].push_back(v);
}






 void Fillorder(vector<vector<int>>& graph,vector<bool>& visited,stack<int>& Stack,int u)
 {
         visited[u]=true;
        
         
         for(int v:graph[u])
         {
               if(visited[v]==false)
               {
                 Fillorder(graph,visited,Stack,v);
               }
         }


         // add in stack as finish node
         Stack.push(u);

 }




void DFS(vector<vector<int>>& graph,vector<bool>& visited,vector<int>& scc,int u) {
    visited[u] = true;
    scc.push_back(u);


    for(int v:graph[u])
    {
        if(visited[v]==false)
        {
             DFS(graph,visited,scc,v);
        }
    }
   

   
}



vector<vector<int>> Transponse(vector<vector<int>>& graph,int v)
{
          vector<vector<int>>Trans(v);

          for(int i=0;i<v;i++)
          {
             for(int j=0;j<graph[i].size();j++)
             {
                Trans[graph[i][j]].push_back(i);
             }
          }

  return Trans;
}
 


 void GET_SCC_Kosaraju(vector<vector<int>>& graph,int v)
 {
             vector<vector<int>> SCC;
             stack<int>Stack;
             vector<bool>visited(v,false);

             // ! 1.sorting node according to their finishing time;
             for(int i=0;i<v;i++)
             {
                if(visited[i]==false)
                {
                  Fillorder(graph,visited,Stack,i);
                }
             }

            



             // ! 2.Transpose graph
           vector<vector<int>>  g=Transponse(graph,v);


             fill(visited.begin(),visited.end(),false);

             

             // ! 3.DFS + track SSC component

             while (!Stack.empty())
             {
                    
                    int v=Stack.top();
                    Stack.pop();

                    if(visited[v]==false)
                    {

                        vector<int>scc;
                        DFS(g,visited,scc,v);
                     
                        SCC.push_back(scc);

                    }
                    
             }








             // ! 4.print resutl

             for(int i=0;i<SCC.size();i++)
             {
                for(int j=0;j<SCC[i].size();j++)
                {
                    cout<<SCC[i][j]<<" -> ";
                }

                cout<<endl;
             }
             










 }






int main()
{
      int v=8;
     vector<vector<int>> graph(v,vector<int>());

     addedge(graph,0,1);
     addedge(graph,1,2);
     addedge(graph,2,0);
     addedge(graph,2,3);
     addedge(graph,3,4);
     addedge(graph,4,5);
     addedge(graph,5,6);
     addedge(graph,6,7);
     addedge(graph,6,4);


     GET_SCC_Kosaraju(graph,v);







}




