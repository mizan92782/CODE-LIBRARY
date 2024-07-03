#include <iostream>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate combinations (n choose k)
unsigned long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Invalid input
    }

    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n = 5;
    int k = 2;

    std::cout << "Combinations of " << n << " choose " << k << ": " << combinations(n, k) << std::endl;

    return 0;
}
