#include<bits/stdc++.h>
using namespace std;



int mod(string str ,int a)
{
     int value=0;

     for(int i=0;i<str.size();i++)
     {
         value =( value*10 + str[i]-'0') % a;
     }

     return  value;
}



int main()
{
        string num ="12316767678678";
        cout<<mod(num,10);
}