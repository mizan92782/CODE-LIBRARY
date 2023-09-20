
#include<bits/stdc++.h>
using namespace std;

int count(int i,int j,string s,string t)
{
     if(j==t.size())
     {
        // if sequence match  to t,increasing value of t indecate that sequenct matching 
        return 1;
     }

     if(i==s.size())
     {
         return 0;
     }

    if(s[i]==t[j])
    {
        return count(i+1,j+1,s,t)  +  count(i+1,j,s,t);
                                
             // supoose first         //supose first charter
            //charter of s and t     // s and t batch,but second character not match
           //match ,so go forwad     // so only forwad S** and recustily check
            //for match
    }

    return count(i+1,j,s,t);
}




int main(){
     
     //https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
     string  s="geeksforgeeks";
     string t="ge";

     cout<<count(0,0,s,t);
}