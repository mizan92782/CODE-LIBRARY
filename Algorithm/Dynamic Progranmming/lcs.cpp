#include<bits/stdc++.h>
using namespace std;


// Returns length of LCS for X[0..m-1], Y[0..n-1]
//Time Complexity: O(2m*n)
int lcs_rec(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs_rec(X, Y, m - 1, n - 1);
    else
        return max(lcs_rec(X, Y, m, n - 1),
                   lcs_rec(X, Y, m - 1, n));
}
 




//! Memorization (m*n)

int lcs_mem(int m,int n,string x,string y,vector<vector<int>>& dp)
{
    //https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
    https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
    // base case;
      if(m==x.size() || n==y.size())
      {
        return 0;
      }



      // if thsi supproblem solve at past

      if(dp[m][n]!=-1)
      {
        return dp[m][n];
      }


      // if its not solve pase and its match
      if(x[m]==y[n])
      {
        dp[m][n]=1+lcs_mem(m+1,n+1,x,y,dp);
      }


      return dp[m][n]=max(lcs_mem(m+1,n,x,y,dp),lcs_mem(m,n+1,x,y,dp));

      
      
 
}






// Driver code
int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();
 
    cout << "Length of LCS is " << lcs_rec(S1, S2, m, n);


    //memorization
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout << "Length of LCS is " << lcs_mem(0,0,S1,S2,dp);


 
    return 0;
}