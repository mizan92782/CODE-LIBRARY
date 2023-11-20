#include<bits/stdc++.h>
using namespace std;


void gcd(int a,int b)
{
    int gre=min(a,b);
    //gcd can not biggest than small number as if it can be small%gcd==0 

    while (gre>1)
    {
         if(a%gre==0 && b%gre==0)
         {
               break;
         }else{
            gre--;
         }
    }


    cout<<"gcd :  "<<gre<<endl;
    
}





// ! faster :Eucleuded algo

int gcd2(int a,int b)
{
      if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    // Base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd2(a - b, b);
    return gcd2(a, b - a);
}


int main()
{
    gcd(81,153); 
    cout<<gcd2(44,22)<<endl;
    cout<<__gcd(34,67);

}