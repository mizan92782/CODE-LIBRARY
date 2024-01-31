#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<32>one(string("00001011011"));
     cout<<one<<endl;

     //! index opertor assing 0-size from right side
     //! index opertor can change value;
     
     one[2]=1;
     cout<<one<<endl;

}