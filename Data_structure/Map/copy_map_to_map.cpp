#include<bits/stdc++.h>
using namespace std;







int main()
{
      map<int,int>map1,map2;


      map1.insert({2,5});
      map1.insert({4,6});
      map1.insert({1,9});
      map1.insert({5,55});
      map1.insert({33,99});
      map1.insert({2,54});


           //copy map1 to map2;
      map2.insert(map1.begin(),map1.end());

      //or  map2=map1



         cout<<"resutlt : \n";
      for(auto it:map2)
      {
        cout<<it.first<<"  "<<it.second<<endl;
      }



    
}
