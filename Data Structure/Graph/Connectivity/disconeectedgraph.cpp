#include<bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}



void DFS(vector<vector<int>>& graph,vector<int>& path,vector<bool>& visited,int s)
{
        //adding in path
         visited[s]=true;
         path.push_back(s);


         for(auto it:graph[s])
         {
             if(visited[it]==false)
             {
                DFS(graph,path,visited,it);
             }
         }
}




// ! find all disconnected component

void FindDisconnectedComponent(vector<vector<int>>& graph,int v)
{
      // for track connected node
       vector<int>path;
       
       //for store all disconnected component
       vector<vector<int>> component;


       vector<bool>visited(v,false);

       for(int i=0;i<v;i++)
       {
          if(visited[i]==false)
          {
             DFS(graph,path,visited,i);

             // **** if one dfs back trackin that means we can a connectd conppnent
             component.push_back(path);
             path.clear();
          }
       }






        //!! component

        cout<<"No of Disconnnected componect :  "<<component.size()<<endl;
        for(int i=0;i<component.size();i++)
        {
            for(int j=0;j<component[i].size();j++)
            {
                cout<<component[i][j]<<" ";
            }

            cout<<endl;
        }



    
}



 int main(int argc, const char** argv) {

        // thid code for find all dis connected componenet
        
        int v=10;
        vector<vector<int>>graph(v,vector<int>());


        //componect 1
        addedge(graph,0,1);
        addedge(graph,0,2);
        addedge(graph,2,1);

        //componect 
        addedge(graph,3,4);
        addedge(graph,3,5);
        addedge(graph,5,4);


         //componect 3
          // 6 singel node



          //componect 
        addedge(graph,7,8);
        addedge(graph,7,9);
        addedge(graph,9,8);



        FindDisconnectedComponent(graph,v);
       

 
    return 0;
}