#include<bits/stdc++.h>
using namespace std;



void Naiveapproach(int arr[],int n){
        
       vector<int> result;
 
  
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            result.push_back(sum);
        }
    }
 
    cout<<"sub array sum  : \n";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" , ";
    } 
    // return the Kth largest sum
    return ;

}

int main()
{
     // find the all subarray sum,in previous we learn
     //how to find sub array, now learning subarray sum,


     //from this code,also can learn all subarray sums sum
     // just all all element of result


     //https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

     int arr[]={1,2,3,4};
     int n=sizeof(arr)/sizeof(arr[0]);
     cout<<"dd";
    Naiveapproach(arr,n);

}