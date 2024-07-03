#include<bits/stdc++.h>
using namespace std;

int kadans(int arr[],int n)
{
     //store maxsum
     int maxsum_so_far=INT_MIN;
     //current sum
     int cur_sum=0;

     //stor startin and ending index
     int start=0,end=0,s=0;

     for(int i=0;i<n;i++)
     {
         //sum
         cur_sum=cur_sum+arr[i];

         //store max sum
         if(cur_sum>maxsum_so_far)
         {
            maxsum_so_far=cur_sum;
            end=i;
         }




         /*
          if curent sum is negetive

          if we find positive in next index
          then we dont add negetive cure sum

          or if we find negetive in nex index
          it will minimum sum

          so we avoid previous negetive sum
         */

          if(cur_sum<0)
          {
            cur_sum=0;
            start=i+1;
          }

     }

     for(int i=start;i<=end;i++)
     {
        cout<<arr[i]<<" ";
     }

     cout<<endl;


     return maxsum_so_far;
}


//********** DP
void maxSubArraySum(int a[], int size)
{
    vector<int> dp(size, 0);
    dp[0] = a[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main()
{
    //https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
     int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);

    cout<<"kadans : "<<kadans(a,n)<<endl;
    maxSubArraySum(a,n);
}