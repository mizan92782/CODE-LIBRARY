#include<bits/stdc++.h>
using namespace std;


/*
 
 lamda fucntion can capture value by capture cluse when it call
 that means if value changed ,doest affect,it will previous value the vlaue automitacally

 !but it capture by reference  it will changed varible  value

*/



int main()
{
 
    int x=4;

    auto capture=[x](){
       
       cout<<"value of x  without reference : "<<x<<endl;
 
    };



    auto capture_ref=[&x](){
       
       cout<<"value of x with reference : "<<x<<endl;

    };




    capture();
    capture_ref();



    //! know changing the x value

    x=22;


   //* not chanaged capture value
    capture();

    //* changed value
    capture_ref();


return 0;
}