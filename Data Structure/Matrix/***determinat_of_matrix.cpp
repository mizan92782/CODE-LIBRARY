#include<bits/stdc++.h>
using namespace  std;








#include <iostream>
using namespace std;
 
// Dimension of input square matrix
#define N 4


// Function for displaying the matrix 
void display(int mat[N][N], 
             int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
            cout << "  " <<  mat[i][j];
        cout << "\n";
    }
}


 
// Function to get cofactor of 
// mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getSubmatrix(int mat[N][N], 
                 int temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of 
    // the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++) 
        {
            // Copying into temporary matrix 
            // only those element which are 
            // not in given row and column
            if (row != p && col != q) 
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row 
                // index and reset col index
                if (j == n - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding 
   determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[N][N], int n)
{

     display(mat,n,n);
     cout<<endl;
    // Initialize result
    int D = 0; 
 
    //  Base case : if matrix contains 
    // single element
    if (n == 1)
        return mat[0][0];
 
    // To store cofactors
    int temp[N][N]; 
 
    // To store sign multiplier
    int sign = 1; 
 
    // Iterate for each element of 
    // first row
    for (int f = 0; f < n; f++) 
    {
         cout<<"\n--------------------------------------------"<<endl;
        // Getting Cofactor of mat[0][f]
        //! her use f as colum,bcs always first row=0,and colum will remove ,clm 0 to n-1
        getSubmatrix(mat, temp, 0, f, n);
        //curent mat[x][y] is co-factor
        D += sign * mat[0][f] * 
             determinantOfMatrix(temp, n - 1);

            
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
 

 

int main()
{


    /*

    https://www.geeksforgeeks.org/determinant-of-a-matrix/
    https://www.geeksforgeeks.org/cpp-program-for-determinant-of-a-matrix/
    */



       int mat[N][N] = {{1, 0, 2, -1},
                     {3, 0, 0, 5},
                     {2, 1, 4, -3},
                     {1, 0, 5, 0}};
 
    // Function call
    cout << "Determinant of the matrix is : " << 
             determinantOfMatrix(mat, N);


          
             

           
}