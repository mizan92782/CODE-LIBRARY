#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
     
     string str="subject";
     regex reg("(sub)(.*)");

     cout<<regex_match(str,reg)<<endl;
     //for range
     //cout<<regex_match(str.begin(),ste.begin()+4,reg)<<endl;
    
     // ! find match string
     smatch s;
     regex_match(str,s,reg);
     cout<<s[0]<<endl;
   
    
    return 0;
}
