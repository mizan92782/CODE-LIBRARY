#include <iostream>
#include <string>
#include <algorithm>

std::string customSortString(std::string order, std::string s) {
    // Custom comparison function
    auto compare = [&order](char a, char b) {
        return order.find(a) < order.find(b);
    };

    // Sorting s based on the order in 'order'
    std::sort(s.begin(), s.end(), compare);

    return s;
}

int main() {

   //! match string s with order of order,its for single occurance of char in s
   //if char occurace multiple time,need another code
    std::string order = "cba";
    std::string s = "abcde";

    std::cout << customSortString(order, s) << std::endl;

    return 0;
}
