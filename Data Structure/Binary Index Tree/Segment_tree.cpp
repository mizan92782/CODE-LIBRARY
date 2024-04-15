#include <bits/stdc++.h>
using namespace std;
vector<int> arr, ST,Lazy;

void buildST(int node, int L, int R)
{

   // leaf node where L==R
   if (L == R)
   {
      ST[node] = arr[L];
   }
   else
   {

      // mid elemennt
      int mid = (L + R) / 2;

      // recursively built bst

      buildST(2 * node, L, mid);
      buildST(2 * node + 1, mid + 1, R);

      //! store sum of chield nodes;
      // here child node in 2*node and 2*node+1 index in array

      ST[node] = ST[2 * node] + ST[2 * node + 1];



   }
}



int Query(int node,int tl,int tr,int l,int r)

{

   //! if query out or range
   if(l> tr or  r<tl) return 0;


   //! node contain range
   if(l<=tl and tr<=r)
   {   
     
      // "this portion show how value are counted 
      //! because revery range exittly will found once
      //so if we find a range between l to r ,it will be a part of our desired range
      cout<<tl<<" to "<< tr<<"---> sum : "<<ST[node]<<endl;

      return ST[node];
   };



   //divide node

   int tm=(tl+tr)/2;


   return Query(2* node,tl,tm,l,r)+Query(2*node+1,tm+1,tr,l,r);


}






/*
An "update" in the context of a segment tree typically refers to modifying the value of an element 
in the underlying array and then updating the segment tree to reflect this change. When an element 
in the array is updated, the corresponding node(s) in the segment tree are also updated to maintain
the correct information.
*/



void update(int node, int L,int R,int idx,int val)
{
   /*
    its importact update criteria can be differ 
    as needso code,its can update for appent,or subract,replace etc
   */


   // *if its leaf node
   if(L==R)
   {
         arr[idx]+=val;
         ST[node]+=val;
   }else{
   
   
      int mid=(L+R)/2;

      //if indx in left side

      if(idx>= L && idx<=mid)
      {
        update(2 * node,L,mid,idx,val);
      }else
      {
       update(2 * node+1,mid+1,R,idx,val);
      }


      //!  Store the information in parents
        ST[node] = ST[2 * node] + ST[2 * node + 1];
   
   
   
   }

}





//! *****Lazy proprgation
 
 void updateLazy(int node,int L,int R)
 {
    //if lazy value exist for this node;
    if(Lazy[node]!=0)
    {   
        // * 1.update value for segment value for parent
        ST[node]=ST[node]+(R-L+1)*Lazy[node];

       // * 2.update lazy for chield
        if(L!=R)
        {
          Lazy[2*node]+=Lazy[node];
          Lazy[2*node+1]+=Lazy[node];
        }


        //* 3.Reset lazy for parent node
        Lazy[node]=0;
    }
 }





 void RangeUpdate(int node,int L,int R,int l,int r,int val)
 { 
       //initial update for current node
       updateLazy(node,L,R);


       if (l > R || r < L) return; 
       // If current segment is completely outside the range to be updated
      

      //! if curent segement im completely in range;
      if(l<=L && r>=R)
      {
          Lazy[node]+=val;
          updateLazy(node,L,R);
          return;

      }

      
      //! if node in this segment is not in range
      int mid=(L+R)/2;
      RangeUpdate(2*node,L,mid,l,r,val);
      RangeUpdate(2*node,mid+1,R,l,r,val);

      // udae value;
      ST[node]=ST[2*node]+ST[2*node+1];
      

 
 }   


int main()
{
   /*
     shafayat blog : http://www.shafaetsplanet.com/?p=1557
      https://www.geeksforgeeks.org/introduction-to-segment-trees-data-structure-and-algorithm-tutorials/

   */

   arr = {0, 1, 3, 5, -2, 3};
   int n = arr.size();

   // adjust size according to requirment;
   ST.resize(4 * n);
   Lazy.reserve(4 * n);




   // * Build segment tree
   buildST(1, 0, n - 1);

   //query
   cout << "Sum of values in range 0-4 are: \n\n"
         << Query(1, 0, n - 1, 0, 4) << "\n";





    update(1, 0, n - 1, 1, 100);
    cout << "Value at index 1 increased by 100\n";
    cout << "sum of value in range 1-3 are: "
         << Query(1, 0, n - 1, 1, 3) << "\n";
  





  

   return 0;
}