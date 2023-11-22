#include <iostream>

using namespace std;

int main() {
    int var[]={2,4,7};
    int targetValue = 28;



    // Iterate through possible values for x
    for (int x = 1; x <= targetValue; ++x) {
        // Iterate through possible values for y
        for (int y = 1; y <= targetValue; ++y) {
            // Solve for z
            int z = (targetValue - var[0] * x - var[1] * y) / var[2];

            // Check if z is a positive integer
            if (z >= 0) {
                // Check if the equation holds
                if (((var[0] * x )+ (var[1] * y )+ (var[2] * z)) == targetValue) {
                    // Print the solution
                    cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
                }
            }
        }
    }

    return 0;
}
