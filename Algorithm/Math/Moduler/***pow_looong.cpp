#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;



//binary expinentiation
lli power(lli x,lli n,lli mod)
{
        // x^0=1;

        if(n==0)  return 1;


        lli temp=power(x,n/2,mod);

        if(n%2==0)
        {
            /*  
            ! if n is even then proper: x^n= (x^(n/2))^2;
            */


           return (temp*temp)% mod;
        }else
        {
            /*
            ! if n is odd ,property : x^n = x* (x^(n/2))^2;
            */


           return (x*temp*temp)% mod;
        }
}



int main() {


    /*
      ! *** always use this code  by changing datatype
      !using bulit in  pow () ,some time may accure problem for its datatype
      *  * * double pow(double base, double exponent);
      ! so better option for power use defing power()
    */



    long long int result = power(2,7,9);
    cout<<result;

    return 0;
}
