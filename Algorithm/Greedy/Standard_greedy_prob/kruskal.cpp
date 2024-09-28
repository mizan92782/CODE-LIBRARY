#include<bits/stdc++.h>
using namespace std;



struct  edge{
   
    int u,v,wgt;
};





void makeEdge(vector<edge>& Edges,int u,int v,int wgt){
  Edges.push_back({u,v,wgt});
}


//sort edges
bool comp(edge x, edge y){
return x.wgt<y.wgt;
}



//find set/parent
int find_set(vector<int>& parent,int x)
{         
       if(parent[x]==x)
       {
       return x;
       }

       return parent[x]=find_set(parent,parent[x]);
}



// make_unior

void make_union(vector<int>& parent,int x,int y)
{
        int px=find_set(parent,x);
        int py=find_set(parent,y);

        if(px!=py)
        {        
        
         /*
                 
                 suppose:


                 0        5
                /|\      /|\
               1 2 3    4 5 6


               x=3, y=4

               as they are not in same set,make parent of xs (0) parent is ys parent(5)
               ! so,it called path comparison
               
                    5
                   /|\ \
                  0 4 5 6
                 /|\
                1 2 3
        */





                 //easy make them union
                 parent[px]=py;
        }

           

}


int main()
{
           //edge number
          
           vector<edge>Edges;

           makeEdge(Edges,0,1,2);
           makeEdge(Edges,0,2,8);
           makeEdge(Edges,1,2,1);
           makeEdge(Edges,1,4,3);
           makeEdge(Edges,2,3,5);
           makeEdge(Edges,2,5,3);
           makeEdge(Edges,3,5,3);
           makeEdge(Edges,4,5,4);


           //sort edges
           sort(Edges.begin(),Edges.end(),comp);


           for(int i=0;i<Edges.size();i++)
           {
             cout<<Edges[i].u<<" "<<Edges[i].v<<" "<<Edges[i].wgt<<endl;
           }




           //! make parent vector
           int n=Edges.size();

           vector<int>parent(n);
           for(int i=0;i<n;i++)
           {
             parent[i]=i;
           }




           vector<edge>MST;


           for(int i=0;i<n;i++)
           {        

                 
                    if(find_set(parent,Edges[i].u) != find_set(parent,Edges[i].v))
                    {      
                             
                             MST.push_back(Edges[i]);
                             make_union(parent,Edges[i].u,Edges[i].v);
                    }
           }





           cout<<"Shortest path : \n";
           for(int i=0;i<MST.size();i++)
           {
                  cout<<MST[i].u<<" -- "<<MST[i].v<<" :  "<<MST[i].wgt<<endl;
           }





            



           



           

         



           



}