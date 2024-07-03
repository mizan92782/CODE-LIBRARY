#include<bits/stdc++.h>
using namespace std;


int main()
{
     bitset<16>one(45);

     //count() return set nuber
     cout<<one<<endl;

     cout<<"One has :  "<<one.count()<<endl;
     cout<<"zero has : "<<one.size()-one.count()<<endl;
}