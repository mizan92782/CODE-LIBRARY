#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void printCoprimePairs(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (gcd(i, j) == 1) {
                cout << "(" << i << ", " << j << ") ";
            }
        }
    }
}

int main() {
    int n = 18;
    printCoprimePairs(n);
    return 0;
}
