#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<32>one(7);
     cout<<one<<endl;

     
     //! **** make it string
     string str=one.to_string();
     cout<<str<<endl;


     //! *** make long integer
     long int x=one.to_ulong();
     cout<<x<<endl;


      //! *** make long long  integer
     long long y=one.to_ullong();
     cout<<y<<endl;


     

}