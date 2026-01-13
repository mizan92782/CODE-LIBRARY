#include<bits/stdc++.h>
using namespace std;

//! ------- declearn graph
#define V 4
vector<vector<int>> graph(V, vector<int>(V, 0));
 
 
//! ------------ make  connected  edge
void addEdge(int i,int j){
  graph[i][j]=1;
  graph[j][i]=1;
}


//!-------------- print edge
void printGraph(){
   
   for(int i=0;i<V;i++)
   { 
     for(int j=0;j<V;j++){
         cout<<graph[i][j]<<" ";
     }
      cout<<endl;
   }

  
}

 

int main(){

// adjacent matrix : https://www.geeksforgeeks.org/adjacency-matrix/
  
  addEdge(0,3);
  addEdge(1,2);
  addEdge(2,3);
  printGraph();


}
