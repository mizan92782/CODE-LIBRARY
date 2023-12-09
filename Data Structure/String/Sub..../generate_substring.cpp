#include<bits/stdc++.h>
using namespace std;

void substring_index_order(string str)
{
     // ! define staring index to make substring (as index order)
     for(int i=0;i<str.size();i++)
     {

        //! define length ( for staring index  to its last),lenth icreasing starting index to str size
         for(int j=i;j<str.size();j++)
         {
             string substr="";

             //! making substring from staring to incresing length
            for(int k=i;k<=j;k++)
            {
                substr=substr+str[k];
            }

            cout<<substr<<endl;
         }
     }
}





void substring_lenght_order(string str)
{
     // ! define length (1 - str.size()) to make substring (as lenthg order)
     for(int len=1;len<=str.size();len++)
     {

        //! define index from start to end
         for(int i=0;i<=str.size()-len;i++)
         {
            
            // ! fixing length of substring
            /*
              * here i change index ,and for every indext len is constant
             */
            

            string substr="";

            int j=i;
            
             while(substr.size()!=len)
             {
                substr=substr+str[j];
                j++;
             }

            cout<<substr<<endl;
            
         }
     }
}





/*
  ! vvi
  ! generating stbstring from previous string , log(N^2);
  */



 void generating_substring(string str)
 {
    

       for(int i=0;i<str.size();i++){
         
         
              string substring ="";
          for(int j=i;j<str.size();j++)
          {
                substring=substring+str[j];
                 cout<<substring<<endl;
          }


         

       }
 }

int main()
{
      string str="abcd";
      substring_index_order(str);
      cout<<endl;
      cout<<"-------\n";
      substring_lenght_order(str);

      cout<<"genereting substring :  ------>  \n";
      generating_substring(str);
}