#include<bits/stdc++.h>
using namespace std;


int dp[1000];
map<int,int>Dp;

//! memoritzetion
int fibonacci(int n)
{

    cout<<"calling -->> \n";


     if(n<=1)
     {
        return n;
     }


      // retrieve data
      // if fib(n) has already been computed
    // we do not do further recursive calls
    // and hence reduce the number of repeated
    // work



     if(dp[n]!=0)
     {
        return dp[n];
     }

     //store data in dp
      // store the computed value of fib(n)
        // in an array term at index n to
        // so that it does not needs to be
        // precomputed again
     dp[n]=fibonacci(n-1)+fibonacci(n-2);



    return dp[n];
}






// using map
 int fibonacci2(int n)
 {
     if(Dp.find(n) != Dp.end())
     {
        return dp[n];
     }

    int result;
     if(n<=1)
     {
        result=n;
     }else{
          result=fibonacci2(n-1)+fibonacci2(n-2);
     }


    

     // stor in map
     Dp[n]=result;

     return result;
    

 }





 // ! tabulation 
 int fibonacci3(int n)
{
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        std::vector<int> table(n + 1, 0);
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= n; i++) {
            table[i] = table[i - 1] + table[i - 2];
        }
        return table[n];
    }
}

int main()
{

    //https://www.geeksforgeeks.org/tabulation-vs-memoization/
     cout<<fibonacci(5)<<endl;
     // calling less in 6 ,get info from fab(5)
     cout<<fibonacci(6)<<endl;
     cout<<fibonacci2(7)<<endl;


      puts("Tabulaion : \n");
      




     //tabulatoin
     cout<<fibonacci3(6)<<endl;

     
}