#include<bits/stdc++.h>
using namespace std;


/*

     !   ***lamda fuantion can capture all variable by value***

     !struture :

           auot name =[=](peramer){
           }
*/



int main()
{
       string name=" Mizan";
       int age=25;
       double property =49549.04;


       auto info=[=](){
         
          cout<<"Name : "<<name<<endl;
          cout<<"age : "<<age<<endl;
          cout<<"Property : "<<property<<endl;
        
       };



       info();
}