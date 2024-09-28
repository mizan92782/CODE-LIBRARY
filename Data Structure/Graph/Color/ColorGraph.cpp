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




bool  colorGraph(vector<vector<int>>& graph,int n)
{

     queue<int>que;
     vector<int>visited(n,false);

     vector<int>color(n,-1);


    //add source
     que.push(0);
     visited[0]=true;
     color[0]=0;


     while (!que.empty())
     {
         int cn=que.front();
         que.pop();

         int nextColor=(color[cn]==0) ? 1 : 0;

        for(int x : graph[cn])
        {
                //check is it possible or not
                if(visited[x]==true  &&  color[x]==color[cn] )
                {
                
                cout<<"Color not possibl"<<endl;
                return false;
                }


                if(visited[x]==false)
                {
                    visited[x]=true;
                    que.push(x);
                    color[x]=nextColor;



                }
        }

    }



    cout<<"Color of node :   "<<endl;
    for(int i=0;i<n;i++)
    {
        
        cout<<"node : " <<i<<"  -------color : "<<color[i]<<endl;
    
    }

    return true;
     

}

int main()
{
    int n=5;
    vector<vector<int>>graph(n);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
   


   
    //bfs(graph);

    colorGraph(graph,n);

   

}