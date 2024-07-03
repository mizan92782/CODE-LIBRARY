#include<bits/stdc++.h>
using namespace std;


//normaly we cant push_front() in vector,but we can use 
//empale(begin(),x) to puhs_foront();

// we can use list to push_front();but its havent index,so
//ovoid this problem we can use vector && emplace();



int main()
{
      
      vector<int>vec{5,7,3,755,335,22,5};

      for(auto it:vec)
      {
        cout<<it<<" ";
      }

      cout<<endl;

      // emplace push.front();
      vec.emplace(vec.begin(),111);


        for(auto it:vec)
      {
        cout<<it<<" ";
      }

      cout<<endl;



       // push at any positino
      vec.emplace(vec.begin()+4,44444);

        for(auto it:vec)
      {
        cout<<it<<" ";
      }

      cout<<endl;


}