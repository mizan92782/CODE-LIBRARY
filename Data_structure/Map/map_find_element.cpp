#include<bits/stdc++.h>
using namespace std;







int main()
{

    //https://www.geeksforgeeks.org/map-erase-function-in-c-stl/
      map<int,int>map1,map2;


      map1.insert({2,51});
      map1.insert({4,6});
      map1.insert({1,9});
      map1.insert({5,55});
      map1.insert({33,99});
      map1.insert({2,5});
      map1.insert({12,54});
      map1.insert({24,54});
      map1.insert({72,54});
      map1.insert({32,54});


      if(map1.count(3))
      {
        cout<<"exitst\n";
      }else{
         
         cout<<"not exist\n";
      }



      for(auto it:map1)
      {
        cout<<it.first<<" "<<it.second<<endl;
      }



      //or
      if(map1.find(12)!=map1.end()){
      //if the element is found before the end of the map
      cout<<"found : Value : "<<map1[12];
      //if the element is present then you can access it using the index
    }


      
       cout<<endl;
      /// use of find element
      for (auto itr = map1.find(12); itr != map1.end(); itr++) {
        
        cout << itr->first << '\t' << itr->second << '\n';
    }


    
}
