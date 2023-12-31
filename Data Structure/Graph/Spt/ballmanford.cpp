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







void BellmanFord(struct Graph* graph,int src){

            int V=graph->ver;
            int E=graph->edg;

              int dest[V];
            
              //making all node shortest path infinte
             for(int i=0;i<V;i++)
             {
                 dest[i]=INT_MAX;
             }



             //making source 0;
             dest[src]=0;




              // Step 2: Relax all edges |V| - 1 times.as V vertex of spt can hav only V-1 edge
             // in every iterate we will one spt path such in V-1 time we ger V-2=E spt path
             
             for(int i=1;i<=V-1;i++)
             {
                  // for every node relaxition relax all edges
                  

                 // edges are ...
                 for(int j=0;j<E;j++)
                 {
                      /*
                        * dijkstraw works on vertex:its relaxation the vertex wise
                        * ballmanford works based on edges:its relaxaton the vertex 
                        !its relaxation all edges N(vertex) time;
                       */
                     int s=graph->edge[j].src;
                     int d=graph->edge[j].dest;
                     int w=graph->edge[j].weight;

                     // ** Relaxation
                     if( dest[s] !=INT_MAX && dest[s]+w<dest[d])
                     {
                        dest[d]=dest[s]+w;
                     }
                 }




                 cout<<"shortest path : "<<i<<"   iteration :  "<<endl;
               
                    for(int i=0;i<V;i++)
                    {
                        cout<<i<<"  ->> "<<dest[i]<<endl;
                    }
                
             }



            cout<<" Shortest path by bellmanford :  \n";
            for(int i=0;i<V;i++)
            {
                cout<<i<<"  ->> "<<dest[i]<<endl;
            }




  return ;
}








int main()
{
    //https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
     Graph* graph = createGraph(4,6);

     SetGraphValue(graph,0,0,1,3);
     SetGraphValue(graph,1,0,2,-4);
     SetGraphValue(graph,2,0,3,-2);
     SetGraphValue(graph,3,3,2,2);
     SetGraphValue(graph,4,2,1,-13);
     SetGraphValue(graph,5,1,2,8);


       
   BellmanFord(graph,0);


   


}
