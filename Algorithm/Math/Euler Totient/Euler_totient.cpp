#include<bits/stdc++.h>
using namespace std;


int EulerTotiend(int n)
{
    // n of low et= n*[(p-1)/p *....]


    int result=n;
      
      int p=2;  
       while(n>1){

         if(n%p==0)
         {  

              //https://chat.openai.com/share/86a95d00-70e3-4e4c-ac71-f6b8ea3877f7
              //! see  for : condition
              result = result * (p - 1) / p;
              while(n%p==0)
              {
                 n=n/p;
              }

             
         }

         // as we need unique factor
         p++;

    }
     

    return result;
}







int main()
{

   cout<<EulerTotiend(18);

    return 0;
}