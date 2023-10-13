
#include<bits/stdc++.h>
using namespace std;




// ! using dp****************************************
const int MAX_CHAR =256;


int Count_din_subsequence(string str)
{
     vector<int>last(MAX_CHAR,-1);
     int n=str.size();
     int mod=1000000007;


     int dp[n+1];
    
     // ! for empty string;
     dp[0]=1;
     for (int i=1;i<=n;i++)
     {
          dp[i]=(2*dp[i-1])%mod;
          // mod for avoid long value;
         
          // as ith disting char subsequenat multiple of previoue index

          if(last[str[i-1]]!=-1)
          {
            dp[i]=dp[i]-dp[last[str[i-1]]]+mod;
            // add mod to vaoid negetive overflow//its very important 
            //when use mod,bcz some value can be begetive
            // so adding mod ,with solve the negetive overflow problem
            dp[i]=dp[i]%mod;


           
          }
        

          //consider as if find
          last[str[i-1]]=(i-1);

          //** significant: we store (i-1) index ,suppost for
           //* abcb  ,for a,we   stor d[o],
           /*
              * for b ,we store a dp ,de[1];
               
           */
          //(i-1) storing index at last[] as a find charter 
     }


     return dp[n];

     
}







// !using maping********************************************

int Count_din_subsequence1(string str) {
    map<char, int> mymap;
    int count = 1; 
    
    int check;// Initialize count to 0, as an empty string is a valid subsequence

    for (int i = 0; i < str.size(); i++) {

        check=count;
        count = count * 2 ; 

     

        if (mymap.count(str[i])) {
            count -= mymap[str[i]]; 
        }

      

        mymap[str[i]] = check; // Update the count for the current character in the map
    }

    return count;
}





int main(int argc, char const *argv[])
{
    
     string str="baccav";

     cout<<Count_din_subsequence(str);
     cout<<endl<<endl<<endl;;
     cout<<Count_din_subsequence1(str);
    return 0;
}





