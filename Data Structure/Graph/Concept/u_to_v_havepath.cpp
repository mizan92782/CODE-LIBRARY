#include<bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
    
}



//!  DFS + is_path() :for is ther their is path for src to dis;

bool DFS(vector<vector<int>>& graph,vector<bool>& visited,int src, int dis)
{
         //if find ssc paht ,meet with distanaiton nod
         if(src==dis){
    
            return true;

         }


       
         visited[src]=true;


         for(auto it:graph[src])
         {
             if(visited[it]==false)
             {
                if(DFS(graph,visited,it,dis)){
                    return true;
                }
             }
         }


         return false;
}




bool is_path(vector<vector<int>>& graph, int v,int src,int dis)
{
          vector<bool> visited(v,false);
        return DFS(graph,visited,src,dis);

}




 int main(int argc, const char** argv) {

        // thid code for find all dis connected componenet
        
        int v=8;
        vector<vector<int>>graph(v,vector<int>());

        addedge(graph,0,1);
        addedge(graph,1,2);
        addedge(graph,2,0);

        addedge(graph,0,3);


        addedge(graph,3,4);

        addedge(graph,4,5);
        addedge(graph,5,6);
        addedge(graph,6,4);

        addedge(graph,4,7);
        addedge(graph,6,7);



        cout<<"3 to  7  : " <<is_path(graph,v,3,7)<<endl;
        cout<<" 4 to 0  : " <<is_path(graph,v,4,0)<<endl;
        cout<<" 0 to 4  : " <<is_path(graph,v,0,4)<<endl;



        cout<<"is U->V and V->U both have path they make cycle : \n";

        if(is_path(graph,v,0,2) && is_path(graph,v,2,0))
        {
            cout<<" they make cycle or scc : "<<endl;
        }else{
            cout<<" no cycle :  "<<endl;
        }




        if(is_path(graph,v,0,7) && is_path(graph,v,7,0))
        {
            cout<<" they make cycle or scc : "<<endl;
        }else{
            cout<<" no cycle :  "<<endl;
        }




       



     

 
    return 0;
}