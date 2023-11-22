#include <iostream>
#include <vector>

using namespace std;

// Function to find solutions for the equation 4x + 5y + 6z = 200
void findSolutions() {
    const int targetValue = 200;

    for (int x = 0; x <= targetValue; ++x) {
        for (int y = 0; y <= targetValue; ++y) {
            for (int z = 0; z <= targetValue; ++z) {
                if (4 * x + 5 * y + 6 * z == targetValue) {
                    // Print the solution
                    cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
                }
            }
        }
    }
}

int main() {
    // Find and print solutions
    findSolutions();

    return 0;
}
