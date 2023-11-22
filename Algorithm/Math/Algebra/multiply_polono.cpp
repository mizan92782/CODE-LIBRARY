
#include<bits/stdc++.h>
using namespace std;


 vector<int>polyMultiply(int Arr1[], int Arr2[], int M, int N)
    {
            // code here

            //! product size will be M+N-1;
            // 1 less first element hacent  co-efficient
             int x=M+N-1;
             
             vector<int>vec(x,0);
             
             for(int i=0;i<M;i++)
             {
                  for(int j=0;j<N;j++)
                  {
                      
                        vec[i+j]=vec[i+j]+(Arr1[i]*Arr2[j]);
                  }
             }
             
             
             return vec;
            
            
    }


int main()

{

    // https://www.geeksforgeeks.org/multiply-two-polynomials-2/

}