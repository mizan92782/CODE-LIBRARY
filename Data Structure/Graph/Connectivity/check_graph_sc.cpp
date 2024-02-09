#include<bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
    
}




void DFS(vector<vector<int>>& graph,vector<bool>& visited,int i)
{
     visited[i]=true;

     for(int v:graph[i])
     {
        if(!visited[v])
        {
            DFS(graph,visited,v);
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


void Check_gaphp_SC(vector<vector<int>>& graph,int v)
{
        vector<bool>visited(v,false);

        
        /*
         * *** after first dfs ,if we can see that first dfs 
         *  not obtaianed all node that means for this is node Strongly component;
         * 
        */
          
          DFS(graph,visited,0);
         for(int i=0;i<v;i++)
         {
             if(visited[i]==false)
             {
                  cout<<i<<" ->This graph is not Strongly connected \n";
                  return ;
             }
         }


           
          // 1->2->4->5->9

         //! as after first dfs,all node could visited
         // so we reverse edge,if graph be a Sc
         // again it also can travese
       
         graph=Transponse(graph,v);



         
          fill(visited.begin(),visited.end(),false);

          // Second DFS
          // after second dfs if all node can
          //visite than its a Sc

          DFS(graph,visited,0);



         for(int i=0;i<v;i++)
         {
             if(visited[i]==false)
             {
                  cout<<"This graph is not Strongly connected \n";
                  return ;
             }
         }





    cout<<"This  a strongly Connected\n";


}







 int main(int argc, const char** argv) {

        //https://www.geeksforgeeks.org/strongly-connected-components/
        
        
        int v=4;
        vector<vector<int>>graph(v,vector<int>());

        addedge(graph,0,1);
        addedge(graph,1,2);
        addedge(graph,2,3);

       addedge(graph,3,0);


       



        Check_gaphp_SC(graph,v);




       



     

 
    return 0;
}