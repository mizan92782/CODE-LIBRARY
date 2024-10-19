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



unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}


int main(){


       cout<<"Catalan recursion : "<<CatalanNumber_rec(4);
}