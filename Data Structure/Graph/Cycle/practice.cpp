#include<bits/stdc++.h>
using namespace std;


int find_parent(vector<int>& parent,int u)
{
     if(parent[u]==u)
     {
        return u;
     }

     
     return parent[u]=find_parent(parent,parent[u]);
}



void make_set(vector<int>& parent,int u,int v)
{

    // find parent
     int p1=find_parent(parent,u);
     int p2=find_parent(parent,v);

     // check is have same parent
     if(p1==p2)
     {
         cout<<" u --> v : are in one set/same parent \n";
         return;
     }

     
    
     //make v parent is parent of u;
     // path comparison
     parent[p2]=p1;
   
}





int main(int argc, char const *argv[])
{
     int v=8;
     vector<int>parent(v);
     for(int i=0;i<v;i++)
     {
        parent[i]=i;
     }


     make_set(parent,1,3);  // 3 parent 1
     make_set(parent,3,6); // 6 parent 3->1
     make_set(parent,5,6); 
     /*
          6 parnet is 1;
          so make 5 parent of 1;
          but curently its not update the parene 5 also for
          1 child 3,6,
          for this we have run find_parent();
     */

      
      cout<<parent[3]<<endl;

     cout<<"parent of : 3 -->"<<find_parent(parent,3)<<endl;

   

     

    return 0;
}
