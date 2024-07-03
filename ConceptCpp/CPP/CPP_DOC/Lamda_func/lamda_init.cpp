#include<bits/stdc++.h>
using namespace std;


//! print value by lamda
void printValue(vector<int>vec)
{
     for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
     cout<<endl;
}




int main()
{
     vector<int>vec{5,611,2,4,3,5,6,99,23,32,66,687};

     //print by lapda
     printValue(vec);

     //sort(vec.begin(),vec.end(),greater<int>());
     //! this sort only ascending or descecndiog
     //we can sort undr condition by lamda

     sort(vec.begin(),vec.end(),[](const int& x,const int& y)->bool
     {
          return x%2==0 && x>y;
     });


     printValue(vec);


     //unique undercondition
     auto p = unique(vec.begin(), vec.end(), [](int a, int b)
    {
        return a > b;
    });

    printValue(vec);



}