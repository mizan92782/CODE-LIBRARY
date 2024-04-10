#include<bits/stdc++.h>
using namespace std;

int equal_sum(int arr[],int n)
{
     int leftsum=0;
     for(int i=0;i<n;i++) 
     {
         leftsum+=arr[i];
     }


     int rightsum=0;

     for(int j=n-1;j>=0;j--)
     {
         rightsum+=arr[j];
         leftsum-=arr[j];

         if(leftsum==rightsum)
         {
            return j;
         }
     }

     

     // if impossible

     return -1;
     
}


void partiion(int arr[],int n)
{
     int k=equal_sum(arr,n);

     if(k==-1)
     {
        cout<<"impossible\n";
     }
     
     cout<<"Equal sum: "<<endl;
     for(int i=0;i<k;i++)
     {
        cout<<arr[i]<<" ";
     }

     cout<<endl;
     for(int i=k;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }
}




int main(int argc, const char** argv) {
    https://www.geeksforgeeks.org/split-array-two-equal-sum-subarrays/
    int arr[] = {1 , 2 , 3 , 4 , 5 , 5 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    partiion(arr,n);
}