#include<bits/stdc++.h>
using namespace std;

static int v=10;

void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}





void FindAllPath_Util(vector<vector<int>>& graph,vector<vector<int>>& g_path,vector<int>& path,vector<bool>& visited,int start)
{
    //make visited current node
    visited[start]=true;
    //add in path;
    path.push_back(start);

    // for check that this node havent any unvisited nodt
    //so its act like a leaf node
    bool nounvisitdnode=true;


    // dfs for all adjacet for current node one by one
    for(auto it:graph[start])
    {
         
         if(visited[it]==false)
         { 
             nounvisitdnode=false;
            FindAllPath_Util(graph,g_path,path,visited,it);
         }
    }


    

    //add the find path to the list;
    if(nounvisitdnode)
    {
         g_path.push_back(path);
    }


    //backtracking: remove the curent node which havent any adjcent any unviisted
    //make is unvisited
    visited[path.back()]=false;
    path.pop_back();


}






void FindAllPath(vector<vector<int>>& graph,int start)
{
                   
       //for track a current path
       vector<int>path;
       //for store obtainded path
       vector<vector<int>>g_path;
       vector<bool>visited(v,false);

       FindAllPath_Util(graph,g_path,path,visited,start);




       //print all find path
       for (auto &p : g_path) {
        for (auto &vertex : p) {
            cout << vertex << " ";
        }
        cout << endl;
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


        FindAllPath(graph,0);







       



 
    return 0;
}