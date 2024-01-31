#include <iostream>
#include <vector>

//! approach 1  :n^2
void printSubsets(const std::vector<int>& set) {
    int n = set.size();
    for (int i = 0; i < (1 << n); ++i) {
        std::cout << "{ ";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {

                std::cout << set[j] << " ";
            }
        }
        std::cout << "}\n";
    }
}




//!   **************** ! appro : n2 :  

void generateSubsets(const std::vector<int>& set, std::vector<int>& current, int index) {
    if (index == set.size()) {
        std::cout << "{ ";
        for (int num : current) {
            std::cout << num << " ";
        }
        std::cout << "}\n";
        return;
    }

    // Exclude the current element
    generateSubsets(set, current, index + 1);

    // Include the current element
    current.push_back(set[index]);
    generateSubsets(set, current, index + 1);

    // Backtrack
    current.pop_back();
}

void printSubsets2(const std::vector<int>& set) {
    std::vector<int> current;
    generateSubsets(set, current, 0);
}




int main() {
    std::vector<int> mySet = {1, 2, 66};
    printSubsets2(mySet);

    return 0;
}