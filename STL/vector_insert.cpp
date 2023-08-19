#include<bits/stdc++.h>
using namespace std;


//normally use for inser a value in a index
//which we can perform by vec[i]
// ***but one inportant use is insert a vector/range of data
//* in a vector at any positin
//



int main()
{
      
      vector<int>vec{5,7,3,2,5};
      vector<int>one{66,77,88,89};


      vec.insert(vec.begin()+2,one.begin(),one.end());


      for(auto it:vec){
            cout<<it<<" ";
      }


    

      


}