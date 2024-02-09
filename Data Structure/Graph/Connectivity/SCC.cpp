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



void Find_SSC(vector<vector<int>>& graph,int v)
{

    //store all ssc component;
    vector<vector<int>>component;

    // store weater a node is included in ssc
    vector<bool>is_ssc(v,false);



    //check for all node that is they are in ssc

    for(int i=0;i<v;i++)
    {
           //if not in ssc
            if(is_ssc[i]==false)
            {

                //as not is scc ,add this node in a ssc;
                vector<int>scc;
                scc.push_back(i);

                //! check for node
                for(int j=i+1;j<v;j++)
                {
                     //  ssc ruless ;  u -->v and u < -- v
                     //check for both i to j and j to,i

                     if(is_ssc[j]==false && is_path(graph,v,i,j) && is_path(graph,v,j,i))
                     {
                          is_ssc[j]=true;
                          scc.push_back(j);
                     }
                }


                // stroe the ssc for this node in resutl
                component.push_back(scc);


            }
    }








    cout << "Strongly Connected Components are:\n";
    for (auto x : component) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }


}




 int main(int argc, const char** argv) {

        //https://www.geeksforgeeks.org/strongly-connected-components/
        
        
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



        Find_SSC(graph,v);




       



     

 
    return 0;
}