#include<bits/stdc++.h>
using namespace std;

 

 void addEdge(vector<vector<int>>& graph, int u,int v)
 {
    graph[u].push_back(v);
    graph[v].push_back(u);

 }



void HierHolzer_Eulerian_path_print(vector<vector<int>>& graph,int V)
{
      

   // * is a empty graph
     if(graph.size()==0)
     {  
         cout<<"Empty graph ; \n";
         return ;
     }



     // * adjacent node count for braking edge in future
     map<int,int>edge_count;
     for(int i=0;i<V;i++)
     {
       edge_count[i]=graph[i].size();
     }



    //stro El path
     vector<int>path;

     //store dfs node
     stack<int>nodes;



     // ! start at any vertex

        nodes.push(0);
        int curr_node=0;

       //dfs
      while (!nodes.empty())
      {     
            // if there is path on curr nod with other
            // we supposed this path with its end node ,
            // now we store this path nad break this path edge
            // 
            if(edge_count[curr_node])
            {
                // !stroe  current path
                nodes.push(curr_node);

                //store end value or current path other nod
                int next_node=graph[curr_node].back();


                // *** break edge
                  edge_count[curr_node]--;
                  graph[curr_node].pop_back();


                // move to next node;
                  curr_node=next_node;


            }else{
            
               path.push_back(curr_node);
               curr_node=nodes.top();
               nodes.pop();

                  
            }




            for (int i=path.size()-1; i>=0; i--)
             {
                   cout << path[i];
               if (i)
                   cout<<" -> ";
                   }
      }
      
     


 
 




}


int main()
{

     //* gaphp one
      vector<vector<int>>graph;
      int V=3;

      addEdge(graph,0,1);
      addEdge(graph,1,2);
      addEdge(graph,2,0);


      HierHolzer_Eulerian_path_print(graph,V);



     
}