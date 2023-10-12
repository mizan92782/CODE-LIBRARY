#include<bits/stdc++.h>
using namespace std;

struct Edge
{
     int src,dest,weight;
};


struct Graph{
     
     int  ver;
     int  edg;

     struct Edge* edge; 
};

Graph* createGraph(int v,int e)
{
     Graph* graph = new Graph;
     graph->ver=v;
     graph->edg=e;

     graph->edge=  new Edge[graph->edg];

    return graph;
      
}



 void SetGraphValue(Graph* graph,int i,int s,int d,int w)
 {
      graph->edge[i].src=s;
      graph->edge[i].dest=d;
      graph->edge[i].weight=w;

 }







bool isNegCycleBellmanFord(struct Graph* graph,int src,int dest[]){

            int V=graph->ver;
            int E=graph->edg;

             
            
              //making all node shortest path infinte
             for(int i=0;i<V;i++)
             {
                 dest[i]=INT_MAX;
             }



             //making source 0;
             dest[src]=0;


             for(int i=1;i<=V-1;i++)
             {
                 for(int j=0;j<E;j++)
                 {

                     int s=graph->edge[j].src;
                     int d=graph->edge[j].dest;
                     int w=graph->edge[j].weight;

                     // ** Relaxation
                     if( dest[s] !=INT_MAX && dest[s]+w<dest[d])
                     {
                        dest[d]=dest[s]+w;
                     }
                 }
             }




        
         
            

              //* Cheking its contain negative cycel
             //* if contains negative cycle its wiil relaxation again afte V-1 time relaxation

             for(int i=1;i<=V-1;i++)
             {
                 for(int j=0;j<E;j++)
                 {

                     int s=graph->edge[j].src;
                     int d=graph->edge[j].dest;
                     int w=graph->edge[j].weight;
                    
                     // ** if Ralaxation accur again its contain negative cyclc
                     if( dest[s] !=INT_MAX && dest[s]+w<dest[d])
                     {
                        return true;
                     }
                 }
             }




  return false;
}






bool isNegCycleDisconnected(Graph* graph){

          int V=graph->ver;
          int E=graph->edg;

           // ** store shortest path
          int dest[V];


         // ** Tracking viisted node in disconnected graph
          int visited[V];
          for(int i=0;i<V;i++)
          {
             visited[i]=false;
          }



          for(int i=0;i<V;i++)
          {
              if(visited[i]==false)
              {
                  // ** if cycle found current vertex;
                 if(isNegCycleBellmanFord(graph,i,dest))
                 {
                    return true;
                 }
              }


              for(int j=0;j<V;j++)
              {
                  //  **if visite vertex ,its value will change 
                 if(dest[j]!=INT_MAX)
                 {
                     visited[j]=true;
                 }
              }
          }


   return false;
}



int main()
{
     Graph* graph = createGraph(4,6);

     SetGraphValue(graph,0,0,1,3);
     SetGraphValue(graph,1,0,2,-4);
     SetGraphValue(graph,2,0,3,-2);
     SetGraphValue(graph,3,3,2,2);
     SetGraphValue(graph,4,2,1,-13);
     SetGraphValue(graph,5,1,2,8);


       

      if(isNegCycleDisconnected(graph))
      {
        cout<<"yes";
      }else
      {
        cout<<"NO";
      }


   


}