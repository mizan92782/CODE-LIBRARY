#include<bits/stdc++.h>
using namespace std;

// function to check if three sider form a triangle or not
bool checkValidity(int a, int b, int c)
{
    // check condition
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else
        return true;
}


//area of a triangle
double area_of_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0);
}


bool is_point_inside_triangel(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y)
{
    double  A=area_of_triangle(x1,y1,x2,y2,x3,y3);
    double A1= area_of_triangle(x,y,x2,y2,x3,y3);
    double A2 = area_of_triangle(x1,y1,x,y,x3,y3);
    double A3=area_of_triangle(x1,y1,x2,y2,x,y);


     cout<<A1<<endl<<A2<<endl<<A3<<endl<<A<<endl;
   
   return (A1+A2+A3)==A;

}




int main()
{
    cout<< is_point_inside_triangel(0, 0, 20, 0, 10, 30, 10, 15)   ; 
}