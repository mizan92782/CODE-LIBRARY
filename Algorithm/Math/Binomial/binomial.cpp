#include<bits/stdc++.h>
using namespace std;




/// O(n*max(k,n-k)) 
// *doinf reapeatd task
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}






// * O(n*r);
// * dynamin,bottom upapproach,but take more space

int binomialCoefficient(int n,int r)
{
     //case 1 : 
     if(r>n) return 0;


     int  bin[n+1][r+1];


  
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=min(i,r);j++)
         {

               //case 2 :
               if (j == 0 || j == i)
               {
                  bin[i][j]=1;
               }else{


               //case 3 :  
               bin[i][j]=bin[i-1][j]+bin[i-1][j-1];
                 //with obj + without obj
               }
         }
     }

     return  bin[n][r];


}



//no extra space
int binomialCoefficient(int n, int k) {
    if (k > n) {
        return 0; // Invalid input
    }

    if (k == 0 || k == n) {
        return 1;
    }

    // Initialize result
    int result = 1;

    // C(n, k) = C(n, n-k)
    if (k > n - k) {
        k = n - k;
    }

    // Calculate C(n, k) using the formula
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
















int main()
{
     int n=5,r=2;

     cout<<"binomial ,dynamic :  "<<binomialCoefficient(n,r)<<endl;



}