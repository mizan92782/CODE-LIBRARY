#include<bits/stdc++.h>
using namespace std;







int main()
{

    //https://www.geeksforgeeks.org/map-erase-function-in-c-stl/
      map<int,int>map1,map2;


      map1.insert({2,5});
      map1.insert({4,6});
      map1.insert({1,9});
      map1.insert({5,55});
      map1.insert({33,99});
      map1.insert({2,54});
      map1.insert({12,54});
      map1.insert({24,54});
      map1.insert({72,54});
      map1.insert({32,54});


      //erser by key;delter 5
      map1.erase(5);


      ///eraser by position? detete 12

      auto x1=map1.find(24);
      auto x2=map1.find(32);
      map1.erase(x1,x2);


      // erase by range:
       auto x=map1.find(11);
       auto x=map1.find(12);


      


    
}
