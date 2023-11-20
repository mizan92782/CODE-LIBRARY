#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999
 

void printSolution(int dist[][V]);
void floyedwarsheell(int graph[][V])
{
     int i,j,k;
     
     /*
     [i][j]  = [i][k] + [k][j];
      i-->j    i-->k   k-->j
      */


     for(k=0;k<V;k++)
     {
         for(i=0;i<V;i++)
         {
             for(j=0;j<V;j++)
             {
                  if((graph[i][j]> (graph[i][k]+graph[k][j])) && (graph[i][k]!= INF   &&  graph[k][j]!=INF))
                  {
                     graph[i][j]=graph[i][k]+graph[k][j];
                  }
             }
         }
     }




     printSolution(graph);



}









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


int main()
{

    //https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
   /* Let us create the following weighted graph
            10
    (0)------->(3)
     |        /|\
    5|         |
     |         | 1
    \|/        |
    (1)------->(2)
            3     */

     

      int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };



         floyedwarsheell(graph);
}