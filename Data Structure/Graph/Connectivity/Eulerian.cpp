#include<bits/stdc++.h>
using namespace  std;

vector<vector<int>>graph;

int V=0;






// ! Check is connected grpah *******;

void dfs(int u,vector<bool>& visited)
{      
         visited[u]=true;

         for(int v: graph[u])
         {
             if(!visited[v])
             {
                dfs(v,visited);
             }
         }

}



bool isConnectedGraph()
{
    

     vector<bool>visited(V,false);

     int count=0;

     for(int i=0;i<V;i++)
     {   
         //single node
         if(graph[i].size()==0)
         {
            continue;
         }

         if(!visited[i])
         {
            cout<<i<<endl;
             count++;

              if(count>1)
              {
                return false;
              }
             dfs(i,visited);
         }
     }


     return true;
}








//! Count odd degree*******
int CountOddDegere()
{
     int count=0;
     for(int i=0;i<graph.size();i++)
     {
         if(graph[i].size()%2==1)
         {
            count++;
         }
     }



     return count;
     
}






//! Check Eulerian
string CheckEulerian()
{
     int odd_degree=CountOddDegere();
     cout<<odd_degree<<endl;

     //** discconnect + odd_degree > 2;
     if(isConnectedGraph()==false || odd_degree>2) 
     {
        return "This is not Eulerian path";
     }

     if(odd_degree==0)
     {
        return "this is Eulerian cycle";
     }

     // if degree==2
     return  "this is semi Eulerian of  of path";

}





int main()
{
     

    //https://www.geeksforgeeks.org/eulerian-path-and-circuit/

     /*
     graph.push_back({1,2,3}); // 0 connect with 1, 2
     graph.push_back({0, 2}); // 1 connect with 0, 2
     graph.push_back({0, 1}); // 0 connect with 1,2
     graph.push_back({0,4}); // 0 connect with 1,2
     graph.push_back({3}); // 0 connect with 1,2

     */

     graph.push_back({1,2});
     graph.push_back({0,2});
     graph.push_back({1,0});

     string str=CheckEulerian();
     cout<<str<<endl;




    

    return 0;

}