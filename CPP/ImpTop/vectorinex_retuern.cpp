#include<bits/stdc++.h>
using namespace std;

// this fucntion return a vector
vector<int> func(int n)
{
     vector<int>vec;
     for(int i=0;i<n;i++)
     {
         vec.push_back(i);
     }

    return vec;
}


int main()
{


     //! ****** how we can print function index

     cout<<func(10)[3]<<endl; 
}