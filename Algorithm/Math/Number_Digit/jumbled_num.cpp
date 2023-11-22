#include<bits/stdc++.h>
using namespace std;


bool jumbled_num(int N)
{
      // * if N==0 
     if(N/10==0){
        return true;
     }



     while (N)
     {


            
         // ** if digit are checked
           if(N/10==0){
                return true;
             }       

         //* last digit
        int x=N%10;

        //* second last digit
        // ! most importat: how find last second digit,similarly we can get last thired or four digit by ((N/10)/10/10)%10
        int y=(N/10)%10;

        if(abs(x-y)>1)
        {
            return false;
        }


        //** less one digit;
        N=N/10;


     }

return true;
     
}


int main()
{
       int N=1234;

       int x=((N/10)/10)%10;
       cout<<x;

       
}