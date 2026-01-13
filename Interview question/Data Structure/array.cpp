
#include<bits/stdc++.h>
using namespace std;

//! ============ all subarray sum ======
// * vector<int> arr = {1, 4, 5, 3, 2};

//*prefix sum approch
int subarraySum(vector<int> &arr) {
    
    int n = arr.size();
    int  result = 0, temp = 0;

    // Pick starting point
    for (int i = 0; i < n; i++) {
      
        // Pick ending point
        temp = 0;
        for (int j = i; j < n; j++) {
          
            // sum subarray between current
            // starting and ending points
            temp += arr[j];
            result += temp;
        }
    }
    return result;
}

//* index contribution approach
int subarraySum(vector<int>&arr) {
    
     int n=arr.size();
      int result = 0;

    // computing sum of subarray using formula
    for (int i = 0; i < n; i++)
        result += (arr[i] * (i + 1) * (n - i));

    // return all subarray sum
   
}

//! ======== max subararay sum ========
// * Kadane's algorithm approach
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
void maxSubArraySumDp(int a[], int size)
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
//! =========== find unique one =======
//everynumeber apper twici or even except one which is appear one or odd ,find it
// * xor approach
int findUnique(vector<int>& arr) {
    int n = arr.size();
    
    int res = 0;
    
    // Find XOR of all elements
    for (int i = 0; i < n; i++) {
        res = res ^ arr[i];
    }
    
    return res;
}



//! =========== find missing number ==========
//find which num is not exist between formula
//* nth number sum approach
int missingNum(vector<int> &arr) {
    int n = arr.size() + 1;
  
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum
    long long expSum = (n *1LL* (n + 1)) / 2;  

    // Return the missing number
    return expSum - sum;
}



//! ================ minimum swap to sort array =============
//* approch: hasing by index,sort temporary : it ara and temp index not same ,then swap them
int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}


int main(){

}