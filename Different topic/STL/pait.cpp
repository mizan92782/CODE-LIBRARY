#include<bits/stdc++.h>
using namespace std;



int main()
{
     pair<int,string>p1;
     pair<int,string>p2={2,"one"};
     p1=make_pair(3,"two");

     pair<int,string>p3;
     
     

     
    if(p1>p2)
    {
         cout<<"p1 is greter"<<endl;
    }else{
         cout<<"p2 is grater"<<endl;
    }


    swap(p1,p2);


    if(p1>p2)
    {
         cout<<"p1 is greter"<<endl;
    }else{
         cout<<"p2 is grater"<<endl;
    }



   





     
}