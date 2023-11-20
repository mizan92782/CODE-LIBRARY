
#include<bits/stdc++.h>
using namespace std;


  // return minimum cost edge node from  cut adjacent node;
  int mininode(int n,int keycity[],bool mstSet[])
  {
       int index;
       int mini=INT_MAX;
       
       for(int i=0;i<n;i++)
       {
          if(mstSet[i]==false && keycity[i]<mini)
          {
             mini=keycity[i];
             index=i;
          }
       }


    return index;
  }


void Find_Minimum_Cost(vector<vector<int>>city,int n)
{
      
       //store city connection list
       int parent[n];

       // store mst nodes adjacet nodes
       int keycity[n];


      // store connecting city
       bool mstSet[n];


        // Set all the key values to infinite and
       // none of the nodes is included in MST.
       for(int i=0;i<n;i++)
       {
         mstSet[i]=false;
         keycity[i]=INT_MAX;
       }



   // Start to find the MST from node 0.
  // Parent of node 0 is none so set -1.
  // key value or minimum cost to reach
  // 0th node from 0th node is 0.

      parent[0]=-1;
      keycity[0]=0;


      //  !Find the n nodes of MST.
      for(int node=0;node<n;node++)
      {
           // First find out the minimum node
          // among the nodes which are not yet
           // included in MST.
          int u= mininode(n,keycity,mstSet);

          mstSet[u]=true;

           // ** adding mst
             cout<<"minimum cost city :: adding mst : "<<u<<endl;

               // Update the values of neighbor
             // nodes of u which are not yet
              // included in MST.
          for(int v=0;v<n;v++)
          {
             if(mstSet[v]==false && city[u][v] && city[u][v]<keycity[v])
             {

                  /*
                  city[u][v]<keycity[v]
                   ata mane mst ta naoyaa hoyace arokom akte
                   noder sathe v connection thakelo ,thakleo u sathe weight kom,tai amra v k u sathe nibo
                  */
                   parent[v]=u;
                   keycity[v]= city[u][v];

                    cout<<"city  "<<u<<"connected to "<<v<<"  :  --> "<<city[u][v]<<endl;
             }
          }

            cout<<endl<<endl;
      }



      int cost=0;
      cout<<"print city : "<<endl;
      for(int i=1;i<n;i++)
      {
           cout<<parent[i]<<" ---> "<<i<<" ==== cost :  "<<city[i][parent[i]]<<endl;
           cost+=city[i][parent[i]];
      }


      cout<<"minimum cost to connect city : "<<cost<<endl<<endl;





}




int main()
{
       

        // city and there connecting cost
        // using prims mst approach;

       vector<vector<int>>city1={

                               {0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};


                    Find_Minimum_Cost(city1,city1.size());




                    cout<<endl<<endl;
                    cout<<"=========for city2========="<<endl;
                    vector<vector<int>> city2 = {
                               {0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},   
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2},  
                               {0, 0, 0, 2, 2, 0}};

                                Find_Minimum_Cost(city2,city2.size());
}


