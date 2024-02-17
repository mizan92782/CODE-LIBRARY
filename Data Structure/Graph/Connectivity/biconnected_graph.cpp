#include<bits/stdc++.h>
using namespace std;

int V=5;
vector<vector<int>>graph(V,vector<int>());

void addedge(int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}


void dfs(int disc[],int low[],bool visited[],int ap[],int time ,int parent,int u)
{     
  
      int children=0;

         visited[u]=true;
         
         disc[u]=low[u]=++time;

         for(int v:graph[u])
         {
                //if unvisited
                if(visited[v]==false)
                {
                     children++;
                     dfs(disc,low,visited,ap,time,u,v);

                     //update low[u];

                     low[u]=min(low[u],low[v]);
                  

                     //chceck after bracktacking is it ac?
                     // if discovery time v(child) > parect dsc 
                     //so ther is no backed edge of subtree node rooted u
                     // fot this lowest time not updte ramain largest
                     if(parent!=-1 && low[v]>disc[u])
                     {
                        ap[u]=true;
                     }

                }else if (v != parent){

                  // reach to visited first 
                  //then will check low[v]
                  low[u]=min(low[u],disc[v]);

                }
         }



         // * case: 01
         //for root node
         //if children >1 ist ar
         if(parent==-1 && children>1)
         {
             ap[u]=true;
         }


        



}






void isBiconnected()
{
     
     int disc[V]={0};
     int low[V];
     bool visited[V]={false};
     int  AP[V]={0};

     
     int time=0;

     int countcomponent=0;

     for(int i=0;i<V;i++)
     {
          if(visited[i]==false)
          { 
             int parent=-1;
            
            countcomponent++;
            dfs(disc,low,visited,AP,parent,time,i);
          }
     }


     if(countcomponent>1)
     {
        cout<<"This graph is not connected graph : component : "<<countcomponent<<endl;
     }


     int x=count(AP,AP+V,1);
     
     if(x==0)
     {
        cout<<"graph is biconnected\n";
        return;
     }


     cout<<"Articulation points are :  ";
     for(int i=0;i<V;i++)
     {
        if(AP[i]==1) cout<<i<<" ";
     }

     cout<<endl;





     
}


int main()
{
    addedge(0,1);
    addedge(0,2);
    addedge(0,3);

    addedge(1,2);
    addedge(1,3);
    
  
    addedge(2,3);
    addedge(4,3);




    isBiconnected();



     
}