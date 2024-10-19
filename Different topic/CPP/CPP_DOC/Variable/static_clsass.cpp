#include<bits/stdc++.h>
using namespace std;


class Student{
    public:
    ///  static not will copy for object,its related will class;change only class
    static string versity;

    //const will copy for object but,cant change by object or classs,
    const string local="chittagong";

    //instance copy for all object and can chage
    int x=5;
    
  
    Student()
    {   
       

        cout<<this->versity<<endl;
        this->x=55;
    }

};

//changing static variable
string Student::versity="apple";

int main()
{

    Student miz;
    cout<<miz.local<<endl;
    cout<<miz.versity<<endl;
    cout<<miz.x<<endl;

    cout<<"change x value : ";
     miz.x=55;   // mutable
     cout<<miz.x<<endl;

     //miz.local="fjdj";   not mutable by objects or calss
     


    // same for all boject,will not be different property of objects
    cout<<miz.versity<<endl;


    //accesing by class;
    cout<<Student::versity<<endl;

    //cout<<Student::local<<endl;  cant not acceast by class ;
    
   
    

}