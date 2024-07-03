//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int main()
{
      string str="456A";
      int num=static_cast<int>(str[0]);

       //asci value 
      cout<<num<<endl;

      // accurate value 
      cout<<num-48<<endl;



      num=static_cast<int>(str[3]);
      //asci value 
      cout<<num<<endl;


      //cast int to char

      char c=static_cast<char>(num);

      //  change to char
      cout<<c<<endl;
      //lets make it char 


      // lets make c is long long 

      long long x=static_cast<long long>(c);
      cout<<x<<endl;


      // lets make this ll x to double
      double y=static_cast<double>(x);
      cout<<y<<endl;

      //lets meke is string

      
      
}