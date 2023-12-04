#include<bits/stdc++.h>
using namespace std;


int Fabonacci(int n)
{
    if(n==0) return 0;

     int a=0;
     int b=1;

     for(int i=2;i<=n;i++)
     {
          //output
          int c=a+b;
           a=b;
           b=c;


     }


     return b;

}




//*********** dyanmic approah
int fib(int n)
    {
 
        // Declare an array to store
        // Fibonacci numbers.
        // 1 extra to handle
        // case, n = 0
        int f[n + 2];
        int i;
 
        // 0th and 1st number of the
        // series are 0 and 1
        f[0] = 0;
        f[1] = 1;
 
        for (i = 2; i <= n; i++) {
 
            // Add the previous 2 numbers
            // in the series and store it
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }




int main()
{


//https://www.geeksforgeeks.org/program-for-nth-fibonacci-numb
    cout<<Fabonacci(9);
}