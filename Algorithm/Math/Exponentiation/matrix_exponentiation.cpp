#include <iostream>
#include <vector>

using namespace std;

// Define a matrix type for convenience
typedef vector<vector<long long>> Matrix;

// ! must be learn : Function to multiply two matrices
Matrix multiply(const Matrix& A, const Matrix& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();

    /*
    ! first matirx clm==second matrix row the multiply possible 
    * new multiplt row will be qual of first matrix, colum will be equal of second matrix clm
    */

    Matrix result(rows_A, vector<long long>(cols_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to raise a matrix to the power of n using matrix exponentiation
Matrix matrixExponentiation(const Matrix& base, int n) {
    int size = base.size();

    if (n == 0) {
        // Return identity matrix for any matrix raised to the power of 0
        Matrix identity(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            identity[i][i] = 1;
        }
        return identity;
    }

    if (n % 2 == 0) {
        // If n is even, compute (base^(n/2))^2
        Matrix half_power = matrixExponentiation(base, n / 2);
        return multiply(half_power, half_power);
    } else {
        // If n is odd, compute base * base^(n-1)
        Matrix half_power = matrixExponentiation(base, n - 1);
        return multiply(base, half_power);
    }
}

int main() {
    // Example: Compute the power of a 2x2 matrix
    //https://www.youtube.com/watch?v=R8Bu8Z0KOjk
    Matrix base = {{1, 1}, {1, 0}};
    int exponent = 5;

    Matrix result = matrixExponentiation(base, exponent);

    // Output the result
    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
