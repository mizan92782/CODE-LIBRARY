#include<bits/stdc++.h>
using namespace std;


#define V 5


void printMst(int parent[V],int graph[V][V])
{
      cout<<"edge  :   wight"<<endl;
      int minimum_cost=0;
      for(int i=1;i<V;i++)
      {
         cout<<parent[i]<<" - "<<i<<"  --> "<<graph[i][parent[i]]<<endl;
          minimum_cost=minimum_cost+graph[i][parent[i]];
      }


      cout<<"minimum_cost : "<<minimum_cost<<endl;
}



int minKey(int key[V],int mstSet[V])
{
     int mini=INT_MAX;
     int index;

     for(int i=0;i<V;i++)
     {
         if(mstSet[i]==false && key[i]<mini)
         {
            mini=key[i];
            index=i;
         }
     }


  return index;
}



void PrimeMst(int graph[V][V])
{
        // *storer parent as mst is tree
        int parent[V];

        // *store mst
        int mstSet[V];

        // **store key,which give lowest weight edge in cut
        // * key node use for store adjacet node of mstset node;
        int key[V];



        for(int i=0;i<V;i++)
        {
             key[i]=INT_MAX;
             mstSet[i]=false;

        }
        
      

       // !inital node

        parent[0]=-1;
        key[0]=0;



        for(int node=0;node<V;node++)
        {

             int u=minKey(key,mstSet);

             //adding in mstSet
             mstSet[u]=true;

             // ** adding mst
             cout<<"minimum key :: adding mst : "<<u<<endl;


             for(int v=0;v<V;v++)
             {
                  if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
                  {
                      key[v]=graph[u][v];
                      parent[v]=u;

                      cout<<"key : "<<v<<" --> "<<graph[u][v]<<endl;
                  }
             }

             cout<<endl<<endl;


        }












 printMst(parent,graph);


}




int main()
{

   //https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

     int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 1, 9, 0 } };
  




  PrimeMst(graph);

  return 0;
}