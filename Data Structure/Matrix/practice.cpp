#include<bits/stdc++.h>
using namespace std;



int main()
{
     int arr[]={4,-2,-5,5,65,-66,4,2,9,-3};
     int n=sizeof(arr)/sizeof(arr[0]);

     int j=-1;
     for(int i=0;i<n;i++)
     {
        if(arr[i]<0)
        { j++;
            swap(arr[i],arr[j]);
        }
     }


      for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }




}