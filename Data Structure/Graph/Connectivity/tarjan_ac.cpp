#include<bits/stdc++.h>
using namespace std;

 const int V=4;
 
 vector<int>ap(V,false); // store ap
 vector<int>disc(V,0); //store discovery time;
 vector<int>low(V);  //store low discovery time
 vector<int>graph[V];
 vector<bool>visited(V,false);



void addedge(vector<int>graph[],int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}


void dfsAP(int u,int parent,int time)
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
                     dfsAP(v,u,time);

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


 
 
 void AP()
 {
     int time=0;
     for(int i=0;i<V;i++)
     {
           if(visited[i]==false)
           {
            dfsAP(i,-1,time);
           }
     }


     cout<<"Articulation point :   ";
     for(int i=0;i<V;i++)
     {
        if(ap[i]==true)
        {
            cout<<i<<" ";
        }
     }

     cout<<endl;
          
 }





 
 int main(int argc, const char** argv) {


//https://www.blackbox.ai/share/a8e3ef58-017b-4f3f-9821-7b8618fdcd4d
  
        
        addedge(graph,0,1);
        addedge(graph,0,2);
       
       
       
      

           /*

             0
            /|\
           1 | 4
          /  | |\
         2   | | \
          \  | 5  \
           \ |     6
            3       \
                     7    
                     
            
           
           */

        AP();

       
 
    return 0;
}