#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<16>one(27);
     cout<<one<<endl;

    //**** test return positin value  (0 or 1 checking)
    // ! *** by this funciton we can find random a bit value of a integer value

     
     for(size_t i=0;i<one.size();i++)
     {
         cout<<one.test(i)<<" ";
     }

}