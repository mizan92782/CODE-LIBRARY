#include<bits/stdc++.h>
using namespace std;





void KMP(string txt,string pat,vector<int>& lps)
{
     int n=txt.size();
     int m=pat.size();


     int i=0;// for text
     int j=0;// for pat


     while ((n-i)>=(m-j))
     {
           if(txt[i]==pat[j]){
             i++;
             j++;
           }

           // if match full patten
           if(j==m){
             cout<<"found full patten at index : "<<i-j;
             j=lps[j-1];
           }else if(i<n &&  pat[j]!=txt[i])
           {
                if(j!=0)
                {
                    j=lps[j-1];
                }else{
                    i++;
                }
           }
     }
    


}


void making_lps(vector<int>& lps,string txt,string pat)
{
   


    int len=0;
    int i=1;



    while (i<pat.size())
    {
          if(pat[i]==pat[len])
          {
             len++;
             lps[i]=len;
             i++;
          }else{

             if(len!=0)
             {
                len=lps[len-1];
                //aaacaaaa
                //supposse we make lps[7]=0,then its wrong
                //because from 5-7(aaa),its also a suffix of aaa,
                //so,we just match with third word
             }else{
                i++;
             }

              
          }
    }
    



}


int main()
{

    // !https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    // !https://www.javatpoint.com/daa-knuth-morris-pratt-algorithm
     string txt= "ABABDABACDABABCABAB";
     string pat = "ABABCABAB";

     vector<int>lps(pat.size(),0);
     making_lps(lps,txt,pat);

    KMP(txt,pat,lps);
}