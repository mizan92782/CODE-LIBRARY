#include<bits/stdc++.h>
using namespace std;


void DFS(string str,int length)
{
     if(str.size()>length)
     {
        return ;
     }


     cout<<str<<" ";

     for(int i=0;i<length;i++)
     {
         str=str+char('A'+i);

         DFS(str,length);




          // ! this line is to much important
          // ! for backtraking other child  
          //! Backtrack to explore other possibilities           

          str.pop_back(); 
        
     }


     
}




// ! funtion for print lexicogaphically order string

void Lexi_char(int length)
{
     for(int i=0;i<length;i++)
     {
         string c="";
         c=c+char('A'+i);

         DFS(c,length);
         cout<<endl;
     }
}



int main()
{
     int length=5;

    Lexi_char(3);
}