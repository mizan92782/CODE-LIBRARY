
#include<bits/stdc++.h>
using namespace std;
#define endline "\n-------------------------------------------------------------------\n\n";


//https://www.geeksforgeeks.org/strings-library-in-cpp-stl/
//https://cplusplus.com/reference/string/string/


int main()
{

   //! produce same character any length
   string same(6,'h');
   cout<<same;
   cout<<endline;


   //! string streaming
   //https://www.geeksforgeeks.org/stringstream-c-applications/
   string stream="this is string streming";
   stringstream obj(stream);
   
   string temp;
   while (obj>>temp)
   {
     cout<<temp<<endl;
   }


   cout<<endline;





   //! iterator in string
   //return a pointer

   string str="iterator";

   auto it=str.begin();
   cout<<*it<<endl;
   *it='c';
   cout<<*it<<endl;


   //citerator or constant iterator cannot cahange value;
   auto cit=str.cbegin();
   // *cit='h';





   //! copy string
   std::string str = "mizanur rahman";
    char s[4];  // Need space for 3 characters + null-terminator
    str.copy(s, 3, 0);  // Copy 3 characters starting from index 0
    s[3] = '\0';  // Null-terminate the string
    std::cout << "Copied substring: " << s << std::endl;







    //! string find operation : https://www.geeksforgeeks.org/string-find-in-cpp/
    
       ** find() : search a character,return pointer
       ** str.find() : search first sub string ,return index
       ** str.rfind() : serach last  substring ,return index
       ** str.find_first_of(s) : find index, wherer index match any character of  s;
       ** str.find_last_of(s) :  find last matching character from s;
       ** str.find_first_not_of(s) : find not match  character  form first;
       ** str.find_last_not_of(s) : find  not match char form last

       **  example :  
       {
                std::string str = "mizanr rahamn shabuj";
                std::string vl = "aeiou";

                size_t t=0;
                while ((t = str.find_first_of(vl,t))!= string::npos)
                {
                str[t]='*';
                t++;
                }
    

                std::cout << str << std::endl;
                
       }




  

   
}