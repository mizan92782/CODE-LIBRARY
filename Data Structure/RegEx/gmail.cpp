#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
     
    std::string str = "01891671904";
    std::regex reg("^018\\d{8}$");

    
    cout<<regex_search(str,reg)<<endl;
    cout<<regex_match(str,reg);
   
     
    
    return 0;
}
