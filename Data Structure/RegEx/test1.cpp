#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
     
     string str="this subject has a submarine as a subsequence";
     regex reg("\\b(sub)([^ ]*)");

     smatch sm;
     
     while (regex_search(str,sm,reg))
     {
         cout<<sm[0]<<endl;
          
         //match position suffix
         str=sm.suffix().str();
     }
     
    return 0;
}
