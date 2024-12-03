#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 5, 6, 8, 9};

    // Checking if vector v is sorted or not
    if (is_sorted(v.begin(), v.end()))
        cout << "Sorted";
    else
        cout << "Not Sorted";
    return 0;
}