#include<bits/stdc++.h>
using namespace std;

// 2^n
int countPartition(int n,int k)
{
      if(n==0 || k==0 || k>n )
      {
         return 0;
      }

      if(k==1 || k==n)
      {
         return 1;
      }


      return k*countPartition(n-1,k)+countPartition(n-1,k-1);
}



// omptimizze dp approach: n*k

 int countpar_tab(int n,int k)
 {
   //https://chat.openai.com/share/5b2278ae-c31b-4a5f-a1dc-c6b181cb48a5
    
    int dp[n+1][k+1];
    // make elemenent 0 in table
    memset(dp,0,sizeof(dp));



    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {

         //! if  ther is only one way to partion
         if(j==1 || i==j)
         {
            dp[i][j]=1;
         }else{

         


          // if n elemnt is including k subset of n-1 elemtn+ if n elemnt is is subset ind have k-1 subset
         dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];

         }

      }
    }



return dp[n][k];

 }






// copy past approach: n*k


int connt_partion_cpy(int n,int k)
{

}


int main()
{
   //https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

   /*
      nuber of way to partition a set into k subset;
      suppose a set hast n=5 element
      if we can coutn number of sub set for k=1,2,3,4,5 subset
      then this is bell number and after add we can find nth bellnumber
   */ 


    

    int n=5;
    int k=2;


   cout<<"subset of a set by k pertiton : "<<countPartition(n,k)<<endl;
   cout<<"subset of a set by k pertiton : "<<countpar_tab(n,k)<<endl;


   cout<<endl;

   cout<<"bell number is the  sum of  a n element set for k=1-n subset\n";


   int sum=0;
   for(int i=1;i<=n;i++)
   {
      sum+= countPartition(n,i);

      cout<<i<<" pertition korle subset hobe :  "<<countPartition(n,i)<<endl;
   }

   cout<<n<<" nth bell number : : "<<sum;



     


}




