#include<bits/stdc++.h>
using namespace std;


//  return the pointer just equal or next greate value than the value x
// need to sorted
//https://www.geeksforgeeks.org/lower_bound-in-cpp/


int main()
{
     int arr[]={4,6,2,11,55,66,222,66,44};
     int n=sizeof(arr)/sizeof(arr[0]);


    sort(arr,arr+n);

   auto it =lower_bound(arr,arr+n,10);

   cout<<"equal or next greater value ";
   cout<<it-arr<<endl;

}