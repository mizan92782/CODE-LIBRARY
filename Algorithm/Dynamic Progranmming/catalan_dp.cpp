#include<bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=CMaZ69P1bAc
//https://www.geeksforgeeks.org/program-nth-catalan-number/



int CatalanNumber_rec(int n)
{
      if(n<=1) return 1;


      int catalan=0;

      for(int i=0;i<n;i++)
      {
           catalan +=CatalanNumber_rec(i)*CatalanNumber_rec(n-i-1);
      }


      return catalan;


}


int main(){


       cout<<"Catalan recursion : "<<CatalanNumber_rec(4);
}