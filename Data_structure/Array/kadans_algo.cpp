#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[],int n)
{
     int max_ending_sum=0;
     int so_far_max=INT_MIN;

     for(int i=0;i<n;i++)
     {
        max_ending_sum=max_ending_sum+arr[i];

        if(so_far_max<max_ending_sum)
        {
            so_far_max=max_ending_sum;
        }

        if(max_ending_sum<0)
        {
            max_ending_sum=0;
        }
     }

    return so_far_max;
}

int maxSubArraySum_index(int arr[],int n,int& start,int& end)
{
     int max_ending_sum=0;
     int so_far_max=INT_MIN;

     int s=0;

     for(int i=0;i<n;i++)
     {
        max_ending_sum=max_ending_sum+arr[i];

        if(so_far_max<max_ending_sum)
        {
            so_far_max=max_ending_sum;
            start=s;
            end=i;
        }

        if(max_ending_sum<0)
        {
            max_ending_sum=0;
            s=i+1;
        }
     }

    return so_far_max;
}


int main()
{
    //https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
 
    // Function Call
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;


     cout<<endl;


    int start=0;
    int end=0;
   
    maxSubArraySum_index(a,n,start,end);
    cout<<"maximum sum subarray \n";
    for(int i=start;i<=end;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}