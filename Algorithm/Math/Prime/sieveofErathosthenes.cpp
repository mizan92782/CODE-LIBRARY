#include<bits/stdc++.h>
using namespace std;


void sieveaOfErathostes(int n)
{
    bool prime[n+1];
     memset(prime, true, sizeof(prime)); 


    for(int p=2;p*p<=n;p++)
    {
         if(prime[p]==true)
         {
               
               for(int m=p*p;m<=n;m=m+p)
               {
                prime[m]=false;
               }
         }
    }



    cout<<"sieve of erathosis : ";
    for (int p = 2; p <= n; p++) 
        if (prime[p]) 
            cout << p << " ";
}




int  main()
{
     int n=50;
     sieveaOfErathostes(50);
}