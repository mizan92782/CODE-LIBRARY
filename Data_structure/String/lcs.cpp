#include<bits/stdc++.h>
using namespace std;



// !find lcs length
int lcs(string s1,string s2,int m,int n)
{
     if(m==0 || n==0)
     {
        return 0;
     }

     if(s1[m-1]==s2[n-1])
     { 
       
         
        return 1+ lcs(s1,s2,m-1,n-1);
     }


      return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}



// ! **************dp*******
string str="";

int lcs_dp_tab(string s1,string s2)
{
     int m=s1.size();
     int n=s2.size();

     int dpTab[m+1][n+1];
     
     for(int i=0;i<=m;i++)
     {
         for(int j= 0;j<=n;j++)
         {
             

                if(i==0 || j==0)
                {
                    dpTab[i][j]=0;

                }else if (s1[i-1]==s2[j-1])
                {
                      
                      dpTab[i][j]=1+dpTab[i-1][j-1];
                      
                }else{

                    dpTab[i][j]=max(dpTab[i-1][j],dpTab[i][j-1]);
                }

                cout<<dpTab[i][j]<<" ";


         }

         cout<<endl;
     }


     return dpTab[m][n];
}




int main()
{
     string S1 = "ABCDGH";
    string S2 = "AEDFHR";


    int m = S1.size();
    int n = S2.size();


    cout<<lcs(S1,S2,m,n);
    cout<<endl;

    lcs_dp_tab(S1,S2);
    cout<<str<<endl;


}