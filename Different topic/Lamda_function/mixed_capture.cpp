#include <iostream>

/*
     caprue can also capture multiple variabele
     --> both refrecent and varaable
*/

int main() {
    int x = 5, y = 10;
    auto mixed_capture = [&x, y] { 
        std::cout << "x by reference: " << x << ", y by value: " << y << std::endl; 
    };
    x = 20;  // Change in x affects the lambda
    mixed_capture();
    return 0;
}
