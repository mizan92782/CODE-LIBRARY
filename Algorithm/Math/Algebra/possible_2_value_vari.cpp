#include <iostream>

using namespace std;

int main() {

    int var[]={4,6};
    int targetValue = 20;

    // Iterate through possible values for x
    for (int x = 0; x <= targetValue; ++x) {
        // Solve for y
        int y = (targetValue - var[0] * x) / var[1];

        // Check if y is a non-negative integer
        if (var[1] * y == targetValue - var[0] * x && y >= 0) {
            // Print the solution
            cout << "Solution: x = " << x << ", y = " << y << endl;
        }
    }

    return 0;
}
