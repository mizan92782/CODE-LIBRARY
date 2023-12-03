#include<bits/stdc++.h>
using namespace std;
#define MAX 500


 //! thia code for maximum  N=12
 int  factorial(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=fact* i;

    }

    return fact;
}





 //! thia code for maximum  N=19;
long long int  factorial19(long long int n)
{
     long long int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=fact* i;

    }

    return fact;
}





//! ******* important : factorial for number  grater than 19 *****

int multipication(int x,int res[],int res_size);
 //this function find factorial of large numbers and prints them
 void  factorial_large(int n)
 {

     int res[MAX];


      // intially result
      res[0]=1;

      // for stroinf index where reach our value in res
      int res_size=1;

      for(int i=2;i<=n;i++)
      {
           res_size=multipication(i,res,res_size);
      }

      cout<<" fatorial :  "<<n<<" : \n";
      for(int i=res_size-1;i>=0;i--)
      {
        cout<<res[i];
      }
      cout<<endl;
 }



int multipication(int x,int res[],int res_size)
{
          int   carry =0;

          for(int i=0;i<res_size;i++)
          { 
            // find value by x * currnt valur + caryy;
             int  prod= res[i]*x+carry;

             // update current value;
              res[i]=prod%10;

              // store carry

              carry = prod/10;


          }





         //! store last carry digit in res
          while(carry)
          {
             res[res_size]=carry%10;
             carry=carry/10;
             res_size++;
          }

   return res_size;
}

int main()
{
    factorial_large(100);
}