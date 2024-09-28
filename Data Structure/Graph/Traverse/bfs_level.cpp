#include<bits/stdc++.h>
using namespace std;





void addEdge(vector<vector<int>>& graph,int u,int v)
{
  graph[u].push_back(v);
  graph[v].push_back(u);
}




void bfs(vector<vector<int>>& graph)
{
      cout<<"Node :  Level"<<endl;



      queue<int>que;
     vector<int>level(graph.size(),-1);
      
      level[0]=0;
      que.push(0);

      while (!que.empty())
      {
            int cn=que.front();
            que.pop();

            //print nodes with level
            cout<<cn<<"    :  "<<level[cn]<<endl;


            for(int x : graph[cn])
            {
                if(level[x]==-1)
                { 
                    level[x]=level[cn]+1;
                    que.push(x);
                }
            }


      }
      
}

int main()
{
    int n=8;
    vector<vector<int>>graph(n);

    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,0,6);

    addEdge(graph,3,4);
    addEdge(graph,3,7);



    addEdge(graph,7,5);
    addEdge(graph,7,2);


   
    bfs(graph);


   

}