// *** find nth fabonacci number my matrix expnentiation:

#include<bits/stdc++.h>
using namespace std;
typedef  vector<vector<long long>> Matrix;


//* entere book thake matrix multipication bhalo kore dakhta hobe
 Matrix multipication(Matrix& A,Matrix& B)
 {
    Matrix C(2, std::vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
 }





long long fabonacci(int n)
{
         if(n==0) return 0;

        //! make base matrix (M)
        vector<vector<long long>> M ={{1,1},{1,0}};

        // ! make unit matirx for maltipication
        vector<vector<long long>>result={{1,0},{0,1}};


        // mulitple base of M mateix n-1 time,here use result or unit matrix for first matlification
        // then result will multipy with {0,1}

   for(int i=1;i<=n-1;i++)
   {
        result=multipication(result,M);
   }

 return result[0][1];   
}




int main()
{

    // nth facbonacci
    int n=8;
    cout<<fabonacci(n);

}


void theory()
{
         /*
         https://chat.openai.com/share/323a8f3a-268c-4714-b2f0-064b98424f78
         https://chat.openai.com/share/323a8f3a-268c-4714-b2f0-064b98424f78
         https://www.youtube.com/watch?v=R8Bu8Z0KOjk
        */
}