#include<bits/stdc++.h>
using namespace std;

 int subarray_sum(int arr[],int n,int sum)
 {
     //nested loop approach(n^2);
      for(int i=0;i<n;i++)
      {
        if(sum==arr[i])
        {
           cout<<"sum found at indext from : "<<i<<" to ";
           return arr[i];
        }else{

           int current=arr[i];
           for(int j=i+1;j<n;j++)
           {
               current=current+arr[j];
               if(current==sum)
               {
                   cout<< "index : "<<i<<" to "<<j<<endl;
                   return current;
               }
           }
        }
      }

      cout<<"not subarray sum found\n";
      return -1;
 }


  

  int  subarray_sum_slidingWindow(int arr[],int n,int sum)

  {

     //complexity: (n);

     
                   int current=arr[0];
                   int start=0,i;

                   for(i=0;i<n;i++)
                   {
                       while (current>sum &&  start<i-1)
                       {
                         current=current-arr[start];
                         start++;
                       }



                       if(sum==current)
                       {
                         cout<<"sum fount in index : "<<start<<" to "<<i<<endl;
                         return current;
                       }

                       
                       current=current+arr[i];
                   }
    
    return -1;
  }


int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subarray_sum_slidingWindow(arr,n,7);
}