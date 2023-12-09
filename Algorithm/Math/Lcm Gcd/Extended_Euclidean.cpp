#include<bits/stdc++.h>
using namespace std;


int Extended_Euclidean(int a,int b,int& x,int& y)
{
      
      //  ** base case,a==0 then co-efficient =0;
      if(x==0)
      {
         x=0;
         y=1;

         return b;
      }



      int x1,y1;

      int gcd=Extended_Euclidean(b%a,a,x1,y1);

      // ! most important part

       x=y1-(b/a) * x1;
       y=x1;


    return gcd;
}


int  main()
{

    int x,y;

    Extended_Euclidean(12,56,x,y);
    cout<<"co-efficenet :  "<<x<<" "<<y<<endl;

return 0;    
}