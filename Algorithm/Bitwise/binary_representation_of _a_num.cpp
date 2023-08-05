#include <bits/stdc++.h>
using namespace std;


string  Binary_representation_x_bit(int n)
{
      // when need 32 ,16,ony specific bit number 
      //O(1)
      string str="0";
      for(int i =1<<30;i>0;i=i>>1)
      {
           
           (n & i)  ? str=str+"1": str=str+'0';
      }

      return str;
}





void Binary_representation_recursive(int n){
      //when just need to prit bit;
      //log(n)

      if(n>1)
      {
            Binary_representation_recursive(n>>1);
      
      }

      cout<<n%2;

}





string Binary_representation_loop(int n)
{
      // using whileloop
      string str="";
      while (n)
      {
           str=char((n%2)+48)+str;
           n=n>>1;
      }
      
return str;
}





string Binary_representtion_bitset(int n)
{     
      //using bitset
      bitset<32>num(n);
      return num.to_string();
}










int main()
{
      cout<< Binary_representtion_bitset(24);
}












