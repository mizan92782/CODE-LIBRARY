#include<bits/stdc++.h>
using namespace std;



// ! graphn;
vector<vector<int>>graph;


void addEdge(int u,int v,vector<int>& indegree){
 
 graph[u].push_back(v);

 indegree[v]++;
 

}



void DFS(int u,vector<bool>& visited)
{
      visited[u]=true;

      for(int v:graph[u])
      {
         if(visited[v]==false)
         {
              DFS(v,visited);
         }
      }
}



vector<vector<int>> Transponse(int V)
{
             vector<vector<int>>gra(V);
             for(int i=0;i<V;i++)
             {
                 for(int j=0;j<graph[i].size();j++)
                 {
                    gra[graph[i][j]].push_back(i);
                 }
             }
    return gra;
}





// ! check is this directed grap is Scc ro not

bool isScc(int V)
{

     vector<bool>visited(V,false);

 
     //! check its nozero nodes are connected or not

    int count=0;
    for(int i=0;i<V;i++)
    {
       // zero degree nodes
       if(graph[i].size()==0)
       { 
        continue;
       }


      // ! check connected nodes group number
       if(visited[i]==false)
       {
            count++;
            if(count>1) return false;
            DFS(i,visited);
       }


    }

     
     

       //! Transponse matrix
       graph=Transponse(V);




        //! traverse again
    fill(visited.begin(),visited.end(),false);
     count=0;
    for(int i=0;i<V;i++)
    {
       // zero degree nodes
       if(graph[i].size()==0)
       { 
        continue;
       }


      // ! check connected nodes group number
       if(visited[i]==false)
       {
            count++;
            if(count>1) return false;
            DFS(i,visited);
       }


    }


  return true;

}





//! check is this directes graph is  Eulerian cycle
void  isEulerian(int V,vector<int>& indegree,vector<vector<int>>& graph1)
{
         
    bool equal_indegree =true;

    for(int i=0;i<V;i++)
    {
      if(indegree[i]!=graph1[i].size())
      {
        
        equal_indegree=false;
        break;
      }

    }


    if(isScc(V) && equal_indegree==true)
    {
    cout<<"Thsi directed graph is Eulerian path\n";
    }else{
     cout<<"Thsi directed graph is not  Eulerian path\n";
    }
      
}


int  main()
{

     int V=5;
     graph.resize(V);

     vector<int>indegree(V,0);

     addEdge(1,0,indegree);
     addEdge(0,2,indegree);
     addEdge(2,1,indegree);
     addEdge(0,3,indegree);
     addEdge(3,4,indegree);
     addEdge(4,0,indegree);
     
     vector<vector<int>>graphCpy=graph;

     isEulerian(V,indegree,graphCpy);



return 0;
}


