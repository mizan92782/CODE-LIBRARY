#include<bits/stdc++.h>
using namespace std;

void subString(string str)
{
     // (n^3)
    int l= str.size();

    for(int  len =1;len<=l;len++)   //ai loop current substiring koto length er
    // hobe seta niddaron kore.
    {
         for(int i=0;i<=str.size()-len;i++) // ai loop er (str.size()-len) bujai  specific lenght hisabe nile ,maximum koto toku 
         //pojjonto naoya jabe,
         //exam: abcd - len=2 hole ,ab,bc,cd --c pojjonto lopp jabe and as len=2 tai 2 lenght er substring createa hobe
         {
              int j=i+len-1;
              // carefully dakhele bujbo ,i and j alwaysa same if ignore len-1;
              // ultimately len thik kore koto length er string print hobe
              //i sudu starting index and j ending index thik kore
              //so every iteration first lopp er joono len 1 increse korbe
              // second loop er jonno  i increase 1 
              // ababe length(len) and place(i) change kore substrin print kore

              for(int k=i;k<=j;k++)
              {
               cout<<str[i];
              }
              cout<<endl;
         }
              
    }
     
}




void substr_using_substr(string str)
{
     for(int i=0;i<str.size();i++)
     {
          for(int  len =1;len<=str.size()-i;len++)
          {
                 cout<<str.substr(i,len)<<endl;
          }
          
     }
}


void generet_sub_from_past_string(string str)
{
     for(int i=0;i<str.size();i++)
     {
         string s="";
        for(int j=i;j<str.size();j++){
            
             s=s+str[j];
             cout<<s<<endl;
             
        } 
     }
}

int main()
{
     string str="abcd";
     substr_using_substr(str);

}