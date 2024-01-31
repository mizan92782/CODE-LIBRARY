#include<bits/stdc++.h>
using namespace std;



int main()
{
     bitset<32>one(7);
     cout<<one<<endl;

     //echeck all are set
     cout<<one.all()<<endl;
     one.set();
     cout<<one.all()<<endl;

}