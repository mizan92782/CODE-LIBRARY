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
         cout<<"apple : "<<apple<<"\nBanana : "<<banana<<endl<<endl;
     }
     


     
};








int main()
{

    Price  arr[]={{1,3},{5,6},{44,66}};

    arr[1].fun();
    
}