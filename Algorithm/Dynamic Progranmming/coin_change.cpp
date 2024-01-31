#include <bits/stdc++.h>
using namespace std;


// ! Recusivee way

int count_coins_rec(int coins[], int n, int sum)
{

    // not possible to get coin==sum
    if (sum < 0)
    {
        return 0;
    }

    // possible case:
    if (sum == 0)
    {
        return 1;
    }

    // if ther is no coin and we get not reach to sum==0
    // so thers is no solution exist
    if (n <= 0)
    {
        return 0;
    }

    return count_coins_rec(coins, n, sum - coins[n - 1]) + count_coins_rec(coins, n - 1, sum);
}





/*

! dp[i][j] denote the sumber of j sum in i coins
! i=1,2,3,..n
find all and add them
*/


int memorization_util(int coins[],int n,int sum,vector<vector<int>>& dp)
{
 
   //base case :
   if(sum==0)
   {
    dp[n][sum]=1;
   }




    // If number of coins is 0 or sum is less than 0 then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;


   // if it is subproblem
   if(dp[n][sum]!=-1)
   {
     return dp[n][sum];
   }



   return dp[n][sum]=memorization_util(coins,n,sum-coins[n-1],dp)+memorization_util(coins,n-1,sum,dp);

  
}

int  Memerization(int coins[],int n,int sum)
{

    // dp space 
    // 1.create 2d array for memorization
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    
    return memorization_util(coins,n,sum,dp);

}





/*
!Tabulization:
for 0 coin and if sum=0 so, dp[0][0]=1;
this is base case

*/


int Tabulization(int coins[],int n,int sum)
{


  vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));


      // **Represents the base case where the target sum is 0,
    // **and there is only one way to make change: by not
    // **selecting any coin
  
    dp[0][0] = 1;


   // for coins
    for(int i=1;i<=n;i++)
    {
       for(int j=0;j<=sum;j++)
       {
          // without current coins

          dp[i][j]=dp[i][j]+dp[i-1][j];

          if ((j - coins[i - 1]) >= 0) 
           {
 
                // Add the number of ways to make change
                // using the current coin
                dp[i][j] += dp[i][j - coins[i - 1]];
           }




        }
    
    }


      return dp[n][sum];
     
}












int main()
{
    int i, j;
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;

    cout<< count_coins_rec(coins, n, sum)<<endl;

    return 0;
}