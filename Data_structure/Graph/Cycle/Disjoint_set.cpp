#include<bits/stdc++.h>
using namespace std;


 class DisjointSet{

       //  for store parent
        vector<int> parent;

        //for store rank or children size;
        vector<int>rank;


        public:
        DisjointSet(int size)
        {
             parent.resize(size,0);
             rank.resize(size,0);


             //define parent itself parent;
             for(int i=0;i<size;i++)
             {
                parent[i]=i;
             }
           
        }




        int find_set(int element)
        {
             if(parent[element] == element)
             {     
                    // ** itself parent;
                    return element;
             }

             // finding parent of chiled to parent path
             // by path comparession
            return parent[element]=find_set(parent[element]);
        }



        void union_set(int x,int y)
        {
             // find parents of x,y;
             int parent_x =find_set(x);
             int parent_y=find_set(y);

             /*
               * if parent are not same,its means
               * they are not from same set;
               * so make them union 
              */


             if(parent_x != parent_y)
             {
                  if(rank[parent_x]<rank[parent_y])
                  {
                     // make union opreration my making same parent
                      parent[parent_x]=parent_y;


                      //rank size update  
                      rank[parent_y]=rank[parent_y]+rank[parent_x];
                  }else{

                     parent[parent_y]=parent_x;  
                      rank[parent_x]=rank[parent_x]+rank[parent_y];

                  }
             }
        }
 };









 int main()
 {


    /*

    https://cp-algorithms.com/data_structures/disjoint_set_union.html
    https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
    
    */

    int n = 5; // Number of elements
    DisjointSet dsu(n);

    dsu.union_set(0, 1);
    dsu.union_set(2, 3);
    dsu.union_set(0, 4);

    // Check if elements are in the same set
    if (dsu.find_set(1) == dsu.find_set(4)) {
        std::cout << "1 and 4 are in the same set.\n";
    } else {
        std::cout << "1 and 4 are in different sets.\n";
    }

    return 0;

 }