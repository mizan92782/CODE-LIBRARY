#include<bits/stdc++.h>
using namespace std;
#define V 5

int minkey(int key[V],bool mstSet[V])
{
     int mini=INT_MAX;
     int index;



      //key[i] represent the minimum weight from i-prent to i node
      //and parent [i] store the i-parent
    
     for(int i=0;i<V;i++)
     {
          if(mstSet[i]==false && key[i]<mini)
          {
          mini=key[i];
          index=i;
          }
    }

    //we find the minimum weight node

    // this return us minimumm cost node
    //and by this func,we findout minimum cost node among all adjacent node of mst node
    //not imporst that,who is parent,as we tore key[i]=weigh
    //we can find minimun weight node i,then update its adjacect key value and parent
    return index;
}


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


void PrimeMST(int graph[V][V])
{
        //for making mst tree
        int parent[V];

        //to store mst edge
        bool mstSet[V];

        // track next step adjacet node or not include mst
        //find minimum node
        ///it store the i-parent node to i node weight
        int key[V];



        for(int i=0;i<V;i++)
        {
         key[V]=INT_MAX;
         mstSet[i]=false;
        }



        //initial
        key[0]=0;
        parent[0]=-1;
        


        for(int i=0;i<V;i++)
        {
              int u=minkey(key,mstSet);


              //! add in mst
              mstSet[u]=true;


              // u--> v
              //adjacent node connected  to minimum node
              for(int v=0;i<v;i++)
              {
                     if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
                     {
                              //key[v] : represtn the widght of u->v
                              //from here we easily find that,v node parent thake v node a connected er weight graph[u][v]
                              //but parent  k kibabe mone rakhbo,so we need parent update
                              key[v]=graph[u][v];
                              parent[v]=u;
                     }
              
              }




        }



        



 printMst(parent,graph);


}

int main()
{
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };


    PrimeMST(graph);

}