#include<bits/stdc++.h>
using namespace std;

typedef long long dt;
typedef long long  ll;


dt BinaryExponentiation(dt a,dt b)
{
    if(b==0) return 1;

    dt result=BinaryExponentiation(a,b/2);

    if(b%2==0)
    {
        return result*result;
    }else{
        return a* result*result;
    }


    return result;
}




//! imporant:  another appraonc: this actuall approct of bianry exppnentiation
ll binaryExponentiation(ll base, ll exponent) {
    ll result = 1;

    while (exponent > 0) {
        // If the current exponent is odd, multiply result with base
        if (exponent % 2 == 1) {
            result *= base;
        }

        // Square the base and divide the exponent by 2
        base *= base;
        exponent /= 2;
    }

    return result;
}




int  main()
{
     cout<<BinaryExponentiation(2,12);
     cout<<endl;
     cout<<binaryExponentiation(2,12);
}