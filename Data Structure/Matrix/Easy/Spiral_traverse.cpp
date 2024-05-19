#include<bits/stdc++.h>
using namespace std;

#define vvec vector<vector<int>> 



vector<int> SpiralTraverse(vvec matrix){


  //size
  int m=matrix.size();
  int n=matrix[0].size();


   //spiral container vector
   vector<int>ans;


   // if its empty
   if(m==0)
   {
   return ans;
   }



   //** Store seen index of matix
   vector<vector<bool>> seen(m,vector<bool>(n,false));
   
    
    //!! very very important topic...
    //! direction indicator

    int dr[]={0,1,0,-1};
    int dc[]={1,0,-1,0};


    //iniitial position
    int x=0;
    int y=0;

    //direciron indicator
    int di=0;


    for(int i=0;i<m*n;i++)
    {
         
         //store spiral traverse element
         ans.push_back(matrix[x][y]);
         //seen
         seen[x][y]=true;

         int newr=x+dr[di];
         int newc=y+dc[di];


        //** check its out of bound of seen before
        //basically its take decision that direction will change or not

        if((newr>=0 && newr<m) &&  (newc>=0  && newc<n) && seen[newr][newc]==false)
        {
            // direction not changinge
            
            x=x+dr[di];
            y=y+dc[di];
        }else{
           
           // as direction will change
           //so we will go next direction
           di=(di+1)%4;

           //update position after direction change
           x=x+dr[di];
           y=y+dc[di];
        
        }


     }

  







  return ans;
}



int main()
{


//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

                 vvec a{ { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 } };
 
       

        for(int x:SpiralTraverse(a))
        {
        cout<<x<<" ";
        
        }



        return 0;
}