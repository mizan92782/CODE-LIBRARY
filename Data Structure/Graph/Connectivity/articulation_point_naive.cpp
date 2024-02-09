#include<bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}



void DFS(vector<vector<int>>& graph,vector<int>& visited,int s)
{
         visited[s]=true;
         for(auto it:graph[s])
         {
             if(visited[it]==false)
             {
                DFS(graph,visited,it);
             }
         }
}


//! ******** For a single node checking
bool ChecktAC_node(vector<vector<int>>& graph,int v,int s)
{    
     /*
     component defines how many time break graph with s node;
     if graph not break without this node,
     we will can taverse by DFS in one time
     so compnent will be 1;
     but if componect bigger than 1 
     that means we had to traverse all node by dfs more than one time
     so its a ac node;
     */
     

     int component=0;
     vector<int>visited(v,false);

     visited[s]=true;

     for(int i=0;i<v;i++)
     {

          
           if(visited[i]==false)
           {
                  //for everytimes componect increase 1,
                  //that indicates the disconnect component
                  component++;
                  DFS(graph,visited,i); 
           }
     }


   if(component>1)
   {
    return true;
   }

   return false;
}






/*

! **************** check Ac for graph;

*/




void GraphAC(vector<vector<int>>& graph,int v)
{

     vector<int>ac;
     
     for(int i=0;i<v;i++)
     {
         if(ChecktAC_node(graph,v,i)==true)
         {
            ac.push_back(i);
         }
     }



     if(ac.size()==0)
     {
        cout<<"There is no acticulation pint \n";
        return ;
     }


    cout<<"No of articulation point : "<<ac.size()<<endl;
    for(int i=0;i<ac.size();i++)
    {
        cout<<ac[i]<<" ,";
    }


    cout<<endl;

}





 int main(int argc, const char** argv) {

        
        int v=7;
        vector<vector<int>>graph(v,vector<int>());

        addedge(graph,0,2);
        addedge(graph,1,2);
        addedge(graph,3,2);
        addedge(graph,4,2);
        addedge(graph,4,5);
        addedge(graph,5,6);


        cout<< ChecktAC_node(graph,v,0)<<endl;
        cout<< ChecktAC_node(graph,v,1)<<endl;
        cout<< ChecktAC_node(graph,v,2)<<endl;
        cout<< ChecktAC_node(graph,v,3)<<endl;
        cout<< ChecktAC_node(graph,v,4)<<endl;
        cout<< ChecktAC_node(graph,v,5)<<endl;
        cout<< ChecktAC_node(graph,v,6)<<endl;


        GraphAC(graph,v);





       



 
    return 0;
}