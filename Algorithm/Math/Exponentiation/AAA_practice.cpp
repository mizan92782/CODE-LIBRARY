
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;


Matrix multiplyMatrix(Matrix a,Matrix b)
{
      int rows_a= a.size();
      int clm_a=a[0].size();
      int clm_b=b[0].size();


      // mutliply result matrix
      
       Matrix result(rows_a, vector<long long>(clm_b, 0));

      for(int i=0;i<rows_a;i++)
      {
         
         for(int j=0;j<clm_b;j++)
         {

             for(int k=0;k<clm_a;k++)
             {
                result[i][j]=result[i][j]+ a[i][k]* b[k][j];
             }
         }
          
      }


    return result;
}


Matrix matrixExponentiation(Matrix& base,int exp)
{
      int size=base.size();


      if(exp==0)
      {
          Matrix identify(size,vector<long long>(size,0));
          for(int i=0;i<size;i++)
          {
             for(int j=0;j<size;j++)
             {
                 identify[i][i]=1;
             }
          }


          return identify;

      }


       if(exp%2==0)
       {
          Matrix resultMatrix =matrixExponentiation(base, exp / 2);
          return multiplyMatrix(resultMatrix,resultMatrix);
       }else{
             

            Matrix resultMatrix =matrixExponentiation(base, exp -1);
          return multiplyMatrix(base,resultMatrix);
       }
      
}








int main()
{
    Matrix base ={{1,1},{1,0}};
    int exp=5;

    Matrix result=matrixExponentiation(base,exp);


    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
}