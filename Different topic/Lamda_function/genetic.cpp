#include<bits/stdc++.h>
using namespace std;

/*
Lambdas can be made generic by using auto in the 
parameter list, allowing them to accept any type.


*/


int main()
{

  auto generic=[](auto x,auto y){

  return x+y;
  };


  cout<<"adding to numebr : "<<generic(4,5)<<endl;
  cout<<"adding doubel and int : "<<generic(4.4,44);

return 0;
}