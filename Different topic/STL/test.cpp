#include<bits/stdc++.h>
using namespace std;
int main()
{
	
    std::string str = "mizanr rahamn shabuj";
    std::string vl = "aeiou";

    size_t t=0;
    while ((t = str.find_first_not_of(vl,t))!= string::npos)
    {
       str[t]='*';
       t++;
    }
    

    std::cout << str << std::endl;
    
    

	

	return 0;
}
