#include<bits/stdc++.h>
using namespace std;


void SieveOfEraththeness(int n)
{

      vector<bool>prime(n+1,true);

      for(int p=2;p*p<=n;p++)
      {
         /*
            9= 3*3;s
            49 =7*7;
           every amon akti factor  k ace ,jakhene k*k=n hoi;
            tai k pojjonto galai hoi

         */


           if(prime[p])
           {
                   // multiply number gulokai,p divide korbe
                   //tai sequentially jouyer dorker nai,p ar p multipyt nibo
                  for(int i=p*p;i<=n;i=i+p)
                  {
                      //make unprime of i's multiply under n
                      prime[i]=false;
                  }
           }


      }





      //* print prime;

      cout<<" prime :  ";
      for(int i=0;i<=n;i++)
      {
        if(prime[i]) cout<<i<<" ";
      }

      cout<<endl;
}












int main()
{
     int n=20;
     SieveOfEraththeness(n);
}

