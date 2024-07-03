#include <iostream>
#include <algorithm>

void printPermutations(std::string str) {
    // Sort the string to handle duplicates
    std::sort(str.begin(), str.end());

    // Print the first permutation
    do {
        std::cout << str << std::endl;
    } while (std::next_permutation(str.begin(), str.end()));
}

int main() {
   
    std::cout << "Distinct permutations with duplicates:" << std::endl;
    printPermutations("ABCC");

    return 0;
}
