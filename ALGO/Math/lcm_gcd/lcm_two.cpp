#include<bits/stdc++.h>
using namespace std;

void lmc1(int a,int b)
{
       int a_inc=a;
       int b_inc=b;

       while(a!=b)
       {
           (a>b) ?  b=b+b_inc : a=a+a_inc;
       }


       cout<<" lcm1 : "<<a; 


}


int lcm_gcd(int a,int b)
{
    return (a*b)/__gcd(a,b);
}



int lcm_loop(int a,int b)
{
      int gret=max(a,b);
      int mini=min(a,b);

      for(int i=gret;;i+=gret)
      {
        if(i%mini==0)
        {
            return i;
        }
      }
}


int main()
{

   //https://www.geeksforgeeks.org/least-common-multiple/

   lmc1(3,59);
   cout<<endl<<" lcm : "<<(lcm_gcd(3,59));
   cout<<endl<<" lcm : "<<(lcm_loop(3,59));

}