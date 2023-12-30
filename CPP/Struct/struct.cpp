#include<bits/stdc++.h>
using namespace std;

struct  Price
{
     int apple;
     int banana;
     Price(int x, int y)
     {
        this->apple=x;
        this->banana=y;
     }


     void fun()
     {
         cout<<apple<<" "<<banana<<endl;
     }
     


     
};








int main()
{

    Price  p(4,5);
    Price  p1(4,544);
    p.fun();
    p.fun();

    
}