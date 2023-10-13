#include<bits/stdc++.h>
using namespace std;


bool div_three(string str)
{
     int sum=0;
     for(int i=0;i<str.size();i++)
     {
        sum=sum+ (str[i]-'0');
     }
     return sum%3==0;
}


int main()
{

      cout<<div_three("123456758933312");
    return 0;
}