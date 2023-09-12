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


     // * if its empty  or last 0 ,then next word can be 0 and 1,so recursively add 0 and 1

     if(str.empty() || str.back()=='0')
     {
         Generating(str+'0',k);
         Generating(str+'1',k);
     }else{

        // * if last word is 1 ,then next word can only 0
          Generating(str+'0',k);
     }
}


int main()
{
     int k=2;
     Generating("",k);
}