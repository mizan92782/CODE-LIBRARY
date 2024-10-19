#include <iostream>

int main() {
    int intValue = 42;
    
    // Convert int to long long using explicit casting
    long long longLongValue = static_cast<long long>(intValue);

    // Print the values
    std::cout << "Original int value: " << intValue << std::endl;
    std::cout << "Converted long long value: " << longLongValue << std::endl;

    return 0;
}
