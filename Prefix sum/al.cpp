
#include<bits/stdc++.h>
using namespace std;

std::string customSortString(const std::string& order, std::string s) {
    // Map to store the frequency of characters in s
    std::unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Custom comparison function
    auto compare = [&order](char a, char b) {
        return order.find(a) < order.find(b);
    };

    // Sorting s based on the order in 'order', considering frequency
    std::sort(s.begin(), s.end(), [&](char a, char b) {
        if (order.find(a) != std::string::npos && order.find(b) != std::string::npos) {
            if (order.find(a) == order.find(b))
                return freq[a] < freq[b];
            return order.find(a) < order.find(b);
        }
        return order.find(a) != std::string::npos;
    });

    return s;
}



int main() {
    std::string order = "dcba";
    std::string s = "abbccddd";

    std::cout << customSortString(order, s) << std::endl;

    return 0;
}

































