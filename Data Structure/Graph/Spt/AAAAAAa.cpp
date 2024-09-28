
#include<bits/stdc++.h>
using namespace  std;
#define V 9


int minimum_node(vector<bool>& visited,vector<int>& spt)
{
         int index=-1;
         int maxV=INT_MAX;


         for(int i=0;i<V;i++)
         {
              if(visited[i]==false && spt[i]<maxV)
              {
               maxV=spt[i];
               index=i;
              }
         }


         return index;
}





void dijkstraw(int graph[V][V],int src)
{

       
       vector<int>spt(V,INT_MAX);
       vector<bool>visited(V,false);


       //add source
       spt[src]=0;
       



      
       for(int i=0;i<V-1;i++)
       {

            int u=minimum_node(visited,spt);
            //maske cuurent minimum node visited
            visited[u]=true;

        


            for(int v=0;v<V;v++)
             {
                   if(visited[v]==false && graph[u][v]!=0 &&  spt[v]>spt[u]+graph[u][v] )
                   {
                         spt[v]=spt[u]+graph[u][v];
                   }
            }
       }




       cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << spt[i] << endl;


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








    dijkstraw(graph,0);



return 0;
}