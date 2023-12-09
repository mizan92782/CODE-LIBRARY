#include<bits/stdc++.h>
using namespace std;
// (n)
int  CatalanNumber(int n)
{
      if(n<=1) return 1;
      
      //! for formula


      int result=0;

      for(int i=0;i<n;i++)
      {
            result+=CatalanNumber(i) * CatalanNumber(n-i-1);
           
            
      }


      return result;
}





//* previous code perform repeat work,so we use dynamic

//(n2)
int Catalan_dynamic(int n)
{
      int catalan[n+1];

      
      //base case;
      catalan[0]=catalan[1]=1;

      for(int i=2;i<=n;i++)
      {
          catalan[i]=0;
         // *nth catalan number is the summation of o to n catalan number multification
        for(int  j=0;j<i;j++)
        {
                // here n=i;
               catalan[i]+=catalan[j]*catalan[i-j-1];
        }


      }


      return catalan[n];

}


int main()
{

      //https://www.geeksforgeeks.org/program-nth-catalan-number/
    //n th catalna number 
    int n=5;

    cout<<"Reaucsive approach : "<<CatalanNumber(n)<<endl;
    cout<<"Dynamic approach : "<<Catalan_dynamic(n)<<endl;

}