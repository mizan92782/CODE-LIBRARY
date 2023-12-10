#include<bits/stdc++.h>
using namespace std;


int ChinessReminder(int coprime[],int rem[],int k)
{

      //suppose  initial resutl=1;

      int result=1;


     while (true)
     {
          bool isTrue=true;

          for(int i=0;i<k;i++)
          {
            
               if(result % coprime[i]!=rem[i])
               {
                    // for curent result is not true
                    isTrue=false;
               }
          }


          if(isTrue==true)
          {
            //we get our result 
            break;
          }else{
             result++;
          }
     }


     return result;
     
}





int main()
{
    //https://www.geeksforgeeks.org/introduction-to-chinese-remainder-theorem/
    //https://www.geeksforgeeks.org/implementation-of-chinese-remainder-theorem-inverse-modulo-based-implementation/
    int coprime[]={3, 4, 5};
    int rem[]={2,3,1};


   int k=sizeof(rem)/sizeof(rem[0]);


   cout<<"Chiness reminder :  "<<ChinessReminder(coprime,rem,k);





    return 0;
}