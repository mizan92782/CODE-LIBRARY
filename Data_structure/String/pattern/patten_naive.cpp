#include<bits/stdc++.h>
using namespace std;

void pattern_naiva(string text,string pat)
{
     int m=text.size();
     int n= pat.size();


     for(int i=0;i<=m-n;i++)
     {
         int j;
         for(j=0;j<n;j++)
         {
             if(text[i+j]!=pat[j])
             {
                break;
             }
         }

       
       
         if(j==n)
         {
            cout<<"pattern found in index: "<<i<<endl;
         }
     }



     cout<<"endl";
}


int main(){

     string text= "AABAACAADAABAAABAA";
     string pat = "AABA";
     pattern_naiva(text,pat);
}