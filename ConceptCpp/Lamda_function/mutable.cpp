#include <bits/stdc++.h>
using namespace std;

/*
  By default, lambdas that capture variables by value 
  are not allowed to modify them inside the lambda.
  You   can make the lambda 
  mutable by using the mutable keyword.

*/

int main() {
   
     int x=30;

    auto number=[x]()mutable{
          
          cout<<"number : "<<x<<endl;

          
    };

    /*

      using referece can allow changed a variabale value
      but it also changed is outside

      
      auto number=[&x]()mutable{
          x=88;
          cout<<"number : "<<x<<endl;

          
    };

    
    */


    number();
    cout<<"number out of lamda : "<<x<<endl;


    return 0;
}
