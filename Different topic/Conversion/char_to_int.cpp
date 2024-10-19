#include<bits/stdc++.h>
using namespace std;



int main()
{
     char a='8';
     char b='D';
     char c='b';



     //ascii valu of variable
     cout<<int(a)<<"  "<<int(b)<<"  "<<int(c)<<endl;
     
     //subtract value of their initial character value
     cout<<int(0)<<"  "<<int('A')<<"  "<<int('a')<<endl;



      cout<<endl;

     // we subract 'O' or 48 to get a=1 in interger
     //we subtract 'A' to get 0 index interger for alphabet

     cout<<a-'0'<<"  or  "<<a-48<<"   or "<<(int)a-48<<endl;
     
     cout<<b-'A'<<"  or "<< b-65<<"  or  "<<(int)b-65<<endl;

     cout<<c-'a'<<"  or "<< c-97<<"  or  "<<(int)c-97<<endl;





     
}