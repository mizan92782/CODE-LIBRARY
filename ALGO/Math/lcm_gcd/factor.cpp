#include<bits/stdc++.h>
using namespace std;

void all_factor(int a)
{
     int factor=2;
    

     // ! this code return all factor,as we in every step we incresing factor
     // ! every step will give diffs factor
     cout<<" all factor:  ";
     while (a/factor>1)
     {
          if(a%factor==0)
          { 
             a=a/factor;
            cout<<factor<<" ";
          }

          factor++;
     }
     
}




void prime_factor(int a)
{
     int factor=2;

     // ** this will return prime factor
     // ** bcz, in every step we dont change factor untill it divide
     //**  as this approach : 2 divide till it divides by 2,
     //** 3 will divide till it divides by 3
     // ** so only prime number will can divide;
     cout<<" all prime factor factor:  ";
     while (a/factor>1)
     {
          if(a%factor==0)
          { 
             a=a/factor;
            cout<<factor<<" ";
          }else
          {
             factor++;
          }

          
     }


}




void gratest_prime_factor(int a)
{
     int factor=2;

     // ** this will return prime factor
     // ** bcz, in every step we dont change factor untill it divide
     //**  as this approach : 2 divide till it divides by 2,
     //** 3 will divide till it divides by 3
     // ** so only prime number will can divide;
     cout<<" all prime factor factor:  ";
     while (a/factor>1)
     {
          if(a%factor==0)
          { 
             a=a/factor;
            
          }else
          {
             factor++;
          }

          
     }


     cout<<"greatest prime factor is : "<<factor<<endl;


}



int main()
{
     int  a=1600;

     all_factor(a);
     cout<<endl;
     prime_factor(a);
     cout<<endl;
     gratest_prime_factor(a);
}