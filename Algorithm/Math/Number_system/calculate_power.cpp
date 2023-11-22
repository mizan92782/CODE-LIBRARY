#include<bits/stdc++.h>
using namespace std;


void Power(int n,int x)
{
        int m=x;

       int pow=1;
       while(m--)
       {
           pow=pow*n;
       }


       cout<<"power("<<n<<","<<x<<") = "<<pow<<endl;
}





int main(){

Power(2,4);
Power(3,3);
}

