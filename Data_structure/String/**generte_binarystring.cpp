#include<bits/stdc++.h>
using namespace std;

void Generating(string str,int k)
{
    // str size == k
     if(str.size()==k)
     {
        cout<<str<<endl;
        return;
     }


    

     if(str.empty() || str.back()=='0')
     {
         Generating(str+'0',k);
         Generating(str+'1',k);
     }else{

      
          Generating(str+'1',k);
          Generating(str+'0',k);
     }
}


int main()
{
     int k=3;
     Generating("",k);
}