#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<32>one;


     //set() use for set a bit o or 1

     //set all 1
     cout<<one<<"\nset all 1-> "<<one.set()<<endl;
     cout<<"set 2 bit 0 --> "<<one.set(2,0)<<endl;
     cout<<"set 2 bit 1 again --> "<<one.set(2)<<endl;
   

}