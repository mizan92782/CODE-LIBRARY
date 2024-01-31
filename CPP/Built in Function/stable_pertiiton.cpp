
#include<bits/stdc++.h>
using namespace std;



int main()
{

     //https://www.geeksforgeeks.org/stdstable_partition-in-c/
     
     int  arr[]={4,6,26,0,3,54,443,1};

     int n=sizeof(arr)/sizeof(arr[0]);


     stable_partition(arr,arr+n,[](int x){ return x<16;});

     for(int i=0;i<n;i++)
     {
       cout<<arr[i]<<" ";
     }


}