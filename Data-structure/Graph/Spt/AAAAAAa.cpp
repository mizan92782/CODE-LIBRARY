#include<bits/stdc++.h>
using namespace  std;

#define V 4
#define INF 99999
 






void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}





void floyedwarsheell(int graph[V][V])
{


     /*
     [i][j]  = [i][k] + [k][j];
      i-->j    i-->k   k-->j

      sorce =i;
      destination = j;
      via node is : k;
      */
     




     //for via node;

     for(int k=0;k<V;k++)
     {
         
          // for source node in every via

          for(int i=0;i<V;i++)
          {

              // for  destinatio  node ,for every seuce to all node
              for(int  j=0;j<V;j++)
              {
                   
                   if(graph[i][j]> (graph[i][k]+graph[k][j]))
                   {
                                  graph[i][j]=graph[i][k]+graph[k][j];     
                   }
              }
          }


          cout<<"In D: "<<k<<endl;
          printSolution(graph);

         
          cout<<endl<<endl;
     }
}







int main()
{


    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };



 floyedwarsheell(graph);


}