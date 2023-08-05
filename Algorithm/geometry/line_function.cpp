#include<bits/stdc++.h>
using namespace std;

float distance_of_two_point(float x1,float y1,float x2,float y2)
{
         float a=(x2-x1);
         float b=(y2-y1);
         a=pow(a,2);
         b=pow(b,2);

         return sqrt(a+b);
}





void  mid_point(float x1,float y1,float x2,float y2)
{
         cout<<(x1+x2)/2 << " , "<<(y1+y2)/2<<endl;
}






float slope(float x1, float y1, float x2, float y2)
{
    if (x2 - x1 != 0)
        return (y2 - y1) / (x2 - x1);
    return INT_MAX;
}








int main()
{
    cout<<abs(-3);
}