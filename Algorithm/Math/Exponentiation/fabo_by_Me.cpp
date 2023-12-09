// this code follow actually matrix exponential process
#include <iostream>
#include <vector>

using namespace std;

// Define a 2x2 matrix class
class Matrix {
public:
    long long a, b, c, d;

    Matrix(long long a, long long b, long long c, long long d) : a(a), b(b), c(c), d(d) {}

    Matrix operator*(const Matrix& other) const {
        return Matrix(
            a * other.a + b * other.c, a * other.b + b * other.d,
            c * other.a + d * other.c, c * other.b + d * other.d
        );
    }
};

// Function to compute matrix exponentiation
Matrix matrix_pow(Matrix base, long long exponent) {
    Matrix result(1, 0, 0, 1); // Identity matrix

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exponent /= 2;
    }

    return result;
}

// Function to calculate the n-th Fibonacci number using matrix exponentiation
long long fibonacci(long long n) {
    if (n == 0) return 0;

    Matrix base(1, 1, 1, 0);
    Matrix result = matrix_pow(base, n - 1);

    return result.a; // The result.a contains the Fibonacci number F(n)
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "F(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
