#include<bits/stdc++.h>
using namespace std;

static int v=10;

void addedge(vector<vector<int>> & graph,int w,int v)
{
     graph[w].push_back(v);
    
     
}





void DFS(vector<vector<int>>& graph,vector<bool>& visited,vector<pair<int,int>>& backeedge,vector<int>& parent,int i)
{

      //ad in parent
      parent.push_back(i);
      visited[i]=true;

      for(int v:graph[i])
      {
        
        if(find(parent.begin(),parent.end(),v)!=parent.end())
        {
          backeedge.push_back({i,v});

        }else if(visited[v]==false)
        {
            
            DFS(graph,visited,backeedge,parent,v);
        }
      }

       parent.pop_back();
     
}






void FindAllBackedEdge(vector<vector<int>>& graph)
{
                   

       vector<bool>visited(v,false);
       //for store TreeEdge

       // store parent
       vector<int>parent;
       vector<pair<int,int>>backededges;

       for(int i=0;i<v;i++)
       {
              if(visited[i]==false)
              {
                DFS(graph,visited,backededges,parent,i);
              }
       }


       
       cout<<"backed edges:  \n";
       for(int i=0;i<backededges.size();i++)
       {
        cout<<backededges[i].first<<" ->  "<<backededges[i].second<<endl;
       }



   
      
}




 int main(int argc, const char** argv) {

        
        
        vector<vector<int>>graph(v,vector<int>());

        // this code also give bckededge path;

        addedge(graph,0,2);
        addedge(graph,2,1);
        addedge(graph,1,0);

        addedge(graph,2,7);
        addedge(graph,7,3);
        addedge(graph,3,6);


        addedge(graph,6,2);
        addedge(graph,6,3);
        addedge(graph,3,7);
        



        FindAllBackedEdge(graph);










       



 
    return 0;
}