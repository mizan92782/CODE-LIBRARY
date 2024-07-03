#include<bits/stdc++.h>
using namespace std;


//global variable;
string name ="mizan";


int main()
{
    //https://www.geeksforgeeks.org/scope-resolution-operator-in-c/
    //same name
    string name="sizan";

    cout<<"local variable : "<<name<<endl;
     
    cout<<"global variabale acces by scope resulation : "<<::name<<endl;

    // change global var by scope reso...
    ::name="akash";
    cout<<"global variabale acces by scope resulation : "<<::name<<endl;
}