#include<bits/stdc++.h>
using namespace std;



int main()
{

     string str="dnfaddkufmdkf";

     unordered_map<char,int>mymap;
     int ch;
     int maxi=0;
     for(int i=0;i<str.size();i++)
     {
        mymap[str[i]]++;

        if(mymap[str[i]]>=maxi)
        {
                ch=i;
                maxi=mymap[str[i]];
        }
     }


     mymap.erase(str[ch]);

     for(auto it:mymap)
     {
        cout<<it.first<<" -> "<<it.second<<endl;
     }


}