#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

     //  for store parent
    vector<int> parent;

    // for store rank or children size;
    vector<int> rank;

    public:
    DisjointSet(int edge)
    {
            parent.resize(edge,0);
            rank.resize(edge,0);

             // define parent itself parent;
            for(int i=0;i<edge;i++)
            {
                 parent[i]=i;
            }
    }



    int find_set(int element)
    {
           if(parent[element] == element)
           {
              // parent itself
             return element;
           }

           //! its vvi,for sychonizing parent in union_set at find parent_x/y,
           // *****  notice, (1,4);
          return parent[element]=find_set(parent[element]);
    }




    void union_set(int x,int y)
    {
         int parent_x=find_set(x);
         int parent_y=find_set(y);





         /*
         * if parent are not same,its means
         * they are not from same set;
         * so make them union
         */

          if (parent_x != parent_y)
        {
            if (rank[parent_x] < rank[parent_y])
            {
                // make union opreration by making same parent
                parent[parent_x] = parent_y;

                // ! ***its path comparision
                 parent[x]=parent_y;

                // rank size update
                rank[parent_y] = rank[parent_y] + rank[parent_x]+1;
            }
            else
            {

                parent[parent_y] = parent_x;

                //***  its path comparison
               parent[y]=parent_x;


                
                rank[parent_x] += rank[parent_y]+1;
                    
                
            }
        }

         
    }

};





// ********* graph

class Graph{
    vector<vector<int>>edgelist;
    int V;

    public:
    Graph(int v)
    {
         this->V=v;

    }


   // edge add kora hobe list, a ,sort korer jonno
   /// age weight diter hobe;
    void addEdge(int x,int y,int wgt)
    {
         edgelist.push_back({wgt,x,y});
    }




    // **** Kruskal algorithm

    void Kruskal_mst()
    {

        // sort according to wight
         sort(edgelist.begin(),edgelist.end());

         DisjointSet dsu(V);
          int mstCost=0;

         for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2];


           // parent differnt means not creting circle

            if(dsu.find_set(x)!=dsu.find_set(y))
            {
                  // making mst set
                 dsu.union_set(x,y);

                //adding cost
                 mstCost+=w;


                 cout<<x<<"----"<<y<<"  == "<<w<<endl; 
            }




         }


         cout<<"Minimum cost = "<<mstCost<<endl;



    }


};



int main()
{

Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 


    g.Kruskal_mst();
  
    
}