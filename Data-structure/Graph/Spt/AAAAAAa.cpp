
#include<bits/stdc++.h>
using namespace  std;
#define V 9




int minimumdist(int dist[V],bool spt[V])
{
      int index;

      int mini=INT_MAX;

      for(int i=0;i<V;i++)
      {

            if(dist[i]<mini && spt[i]==false)
            {
                mini=dist[i];
                index=i;
                
            }
      }


      return index;
}






void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}







void dijkstraws(int graph[V][V])
{

    bool spt[V];
    int dist[V];
    int parent[V];

    

    for(int i=0;i<V;i++)
    {
         spt[i]=false;
         dist[i]= INT_MAX;
         parent[i]=-1;
    }




    
    dist[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int u=minimumdist(dist,spt);

        spt[u]=true;

        
        
            
        
        for(int v=0;v<V;v++)
        {
             if(graph[u][v] !=0 && spt[v]==false  && dist[u]+graph[u][v]<dist[v])
                 {
                    dist[v]=dist[u]+graph[u][v];

                    parent[v]=u;
                 }
        }
    }




     cout<<endl<<endl;

     cotu<<"parent  is : :  ";

     for(int i=0;i<V;i++)
     {
         cout<<i<<"   "<<parent[i]
     }


    printSolution(dist);
}









int main()
{


    int graph[V][V] =
                     { 
                        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11,0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0,0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0,0 },
                        { 0, 0, 4, 14, 10, 0, 2,0,0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0,7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                    }; 


                    dijkstraws(graph);
}