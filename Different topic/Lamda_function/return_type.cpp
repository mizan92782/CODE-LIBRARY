#include<bits/stdc++.h>
using namespace std;


/*
  we can decide specific return type

  ! structure:
   
   auot name = [capture cluse](perameter) -> return_type {
   
   return ;

   }



*/


int main()
{
  
   auto math=[](double x ,double y)->double{
   return x/y;
   };


   cout<<"Answer : "<<math(5,6);
   


return 0;
}