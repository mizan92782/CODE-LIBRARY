#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<32>one(7);
    
     cout<<one<<endl;
     //set() use for set all 1
     // and reset use for set all 0


     cout<<one.set()<<endl;
     cout<<one.reset()<<endl;
     one.set();
     cout<<"reset specifing index : "<<one.reset(4);

}