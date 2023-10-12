#include<bits/stdc++.h>
using namespace std;

// ! by gerating all substring and check it palindrominc and store longest string

bool ispalindromic(string str)
{
     int s=0;
     int  e=str.size()-1;

     while (s<=e)
     {
        if(str[e]!=str[s])
        {
            return false;

        }

        s++;
        e--;
     }


     return true;
     
}


string  longestPalindromicSubstring(string str)
{
      string  lps="";
     

     for(int i=0;i<str.size();i++)
     {  
        string generateStr="";
        for(int j=i;j<str.size();j++)
        {
            generateStr=generateStr+str[j];

            if(ispalindromic(generateStr) && generateStr.size()>lps.size())
            {
                lps=generateStr;
            }
        }
     }


     return lps;

}


int main()
{

    //https://www.geeksforgeeks.org/longest-palindromic-substring/
     string str ="forgeeksskeegfor";

     cout<<"lps by generationg substring : " <<longestPalindromicSubstring(str);
}