
#include<bits/stdc++.h>
using namespace std;

#define R 3
# define C 3



void PrintMatrix(int matrix[R][C],int r,int c)
{ 

      // if botoom right
      if(r==R-1 && c==C-1)
      {
      cout<<matrix[r][c];
      return ;
      }


      cout<<matrix[r][c]<<" ";
      if(c==C-1)
      {
       cout<<endl;
       PrintMatrix(matrix,r+1,0);
      }else{
      PrintMatrix(matrix,r,c+1);
      }



}



int main()
{
   int matrix[R][C]={
    {1,2,3},
    {4,5,6},
    {7,8,9}
   };

   
   PrintMatrix(matrix,0,0);





}