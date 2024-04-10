#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
     
    std::string str = "mizanmd9278_2@gmail.com";
    std::regex reg("[A-Za-z0-9]+@gmail.com$");

    
    cout<<regex_search(str,reg)<<endl;
    cout<<regex_match(str,reg);
   
     
    
    return 0;
}
