#include<bits/stdc++.h>
using namespace std;

struct  Student
{
    public:
    string name;
    int id;
    int age;


   
    // such we can create nested sturct
    struct Father
    {
        public:
        string name;
        int age;
        string profssion;
    };


    //* !!father struce variable
    Father father;
    
};


Student::Father setfather()
{
    return { "milon",55,"tea staller;"};
}


// ! this way we can return a struct value like vecto;
Student setStudent()
{

  return {"mizanur ",33,185};
}


int main()
{

       Student mizan =setStudent();
       mizan.father=setfather();

       cout<<mizan.name<<" "<<mizan.id<<" "<<mizan.age<<endl;
       cout<<mizan.father.name<<endl;
}