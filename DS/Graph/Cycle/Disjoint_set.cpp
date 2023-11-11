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


         // ! Cycle detection
         if(parent_x==parent_y)
         {    
            cout<<endl<<endl;
             cout<<x<<","<<y<<" parent is same,that means the exist in seme set,so they will create a cycle\n\n";
             return ;
         }



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



        cout<<"rank :  ";
        for(int i=0;i<rank.size();i++)
        {
            cout<<rank[i]<<" ";
        }

        cout<<endl;

         cout<<"parent: ";
        for(int i=0;i<rank.size();i++)
        {
            cout<<parent[i]<<" ";
        }

        cout<<"--> "<<x<<","<<y;

        cout<<endl;



         
    }

};


int main()
{

    /*

    https://cp-algorithms.com/data_structures/disjoint_set_union.html
    https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

    */

    int n = 8; // Number of elements
    DisjointSet dsu(n);

    dsu.union_set(0,1);
    dsu.union_set(2, 3);

    if (dsu.find_set(1) == dsu.find_set(3))
    {
        std::cout << "1,3-> they are in the same set.\n\n";
    }
    else
    {
        std::cout << " 1,3 -> are in different sets.\n\n";
    }



    dsu.union_set(4, 5);
    dsu.union_set(6, 7);
    dsu.union_set(1, 3);


    // after(1,3) --(0,1) union (2,3);
    if (dsu.find_set(0) == dsu.find_set(2))
    {
        std::cout << " 0, 2 -> are in the same set.\n\n";
    }
    else
    {
        std::cout << " 0,2-> are in different sets.\n\n";
    }



     // 4,6 not  yet union
    if (dsu.find_set(4) == dsu.find_set(6))
    {
        std::cout << " 4,5 ->are in the same set.\n\n";
    }
    else
    {
        std::cout << " 4,6 ->are in different sets.\n\n";
    }


    dsu.union_set(1, 4);
    dsu.union_set(0, 2);
    dsu.union_set(5, 7);
    dsu.union_set(4, 6);

    // Check if elements are in the same set
    if (dsu.find_set(1) == dsu.find_set(6))
    {
        std::cout << "1 and 4 are in the same set.\n";
    }
    else
    {
        std::cout << "1 and 4 are in different sets.\n";
    }

    return 0;
}