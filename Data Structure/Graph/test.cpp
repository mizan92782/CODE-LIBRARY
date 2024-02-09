
#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>>& graph,int u,int v,vector<vector<int>>& wg,int w)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    
    //for wighted graph
    wg[u][v]=w;
}



void BFS(vector<vector<int>>& graph,int s)
{
      
      queue<int>que;
      vector<bool>visited(graph.size(),false);


      que.push(s);
      visited[s]=true;


      while (!que.empty())
      {
         int x=que.front();
         cout<<x<<" ";
         que.pop();


         for (auto it:graph[x])
         {
            if(visited[it]==false)
            {
                que.push(it);
                visited[it]=true;
            }
         }
      }
      

}


void DFS_util(vector<vector<int>>&graph,vector<bool>& visited,int s)
{
     
        visited[s]=true;
        cout<<s<<"-> ";

        for(auto it:graph[s])
        {
            if(visited[it]==false)
            {
                DFS_util(graph,visited,it);
            }
        }
           

}



void DFS(vector<vector<int>>& graph,int s)
{
      vector<bool>visited(graph.size(),false);
      DFS_util(graph,visited,s);


}



void weightedGraph(vector<vector<int>>& graph,vector<vector<int>>& wg)
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
           if(wg[i][graph[i][j]]!=0)
           {
             cout<<i<<" <--> "<<graph[i][j]<<" : "<<wg[i][graph[i][j]]<<endl;
           }
        }
    }
}

int main()
{

    int V=5;

    vector<vector<int>>graph(V,vector<int>());
    vector<vector<int>>wg(V,vector<int>(V,0));
    addEdge(graph,0,4,wg,55);
    addEdge(graph,1,3,wg,44);
    addEdge(graph,0,2,wg,14);
    addEdge(graph,4,3,wg,67);
    addEdge(graph,2,3,wg,24);
    addEdge(graph,0,3,wg,687);

    int source=3;
    
    cout<<"BFS : \n";
    BFS(graph,source);

    cout<<"\nDFS\n";
    DFS(graph,source);



    cout<<"\nwighted graph\n";
    weightedGraph(graph,wg);




}