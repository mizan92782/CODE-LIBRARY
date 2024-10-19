#include<bits/stdc++.h>
using namespace std;


//! recursive
int countWay(vector<int> coins,int n,int sum)
{     
      //if sum=0;then a way is find
      if(sum==0) return 1;

      //if sum<0 or n==0 : then no way find
      if(sum<0 || n==0) return 0;
             
             //included                           //excluded
      return countWay(coins,n,sum-coins[n-1])  + countWay(coins,n-1,sum);
}




//! memrization
int countway_memo(vector<int>coins,int n,int sum,vector<vector<int>> memo)
{ 
     if(sum==0) return memo[n][sum]=1;

     if(n==0 || sum<0) return 0;

     //! if it calculated previously
     if(memo[n][sum]!=-1) return memo[n][sum];


     return   memo[n][sum]=countway_memo(coins,n,sum-coins[n-1],memo)+countway_memo(coins,n-1,sum,memo);

}


int main()
{

 //https://www.geeksforgeeks.org/coin-change-dp-7/
  vector<int> coins={1,2,3};
  //given sum
  int sum=5;
  int n=coins.size();


  cout<<"count recursively : "<<countWay(coins,n,sum)<<endl;


  //! Memorization
   vector<vector<int>>memo(n+1,vector<int>(sum+1,-1));
    cout<<"count memorization : "<<countway_memo(coins,n,sum,memo)<<endl;


}