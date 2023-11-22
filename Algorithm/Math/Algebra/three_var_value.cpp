#include <iostream>
#include <tuple>

using namespace std;

// Extended Euclidean Algorithm for three variables
tuple<int, int, int> extendedGCD(int a, int b, int c) {
    if (a == 0)
        return make_tuple(b, 0, 1);

    int gcd, x1, y1;
    tie(gcd, x1, y1) = extendedGCD(b % a, a, c);

    int x = y1 - (b / a) * x1;
    int y = x1;

    return make_tuple(gcd, x, y);
}

// Function to find a particular solution to the linear Diophantine equation ax + by + cz = d
bool findSolution(int a, int b, int c, int d, int& x, int& y, int& z) {
    int gcd, x0, y0;
    tie(gcd, x0, y0) = extendedGCD(a, b, c);

    // Check if d is divisible by gcd(a, b, c)
    if (d % gcd != 0) {
        return false; // No solution exists
    }

    // Find a particular solution (x, y, z)
    x = x0 * (d / gcd);
    y = y0 * (d / gcd);
    z = (d - a * x - b * y) / c;

    return true;
}

int main() {
    int a = 2, b = 3, c = 5, d = 10;

    int x, y, z;
    if (findSolution(a, b, c, d, x, y, z)) {
        cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
