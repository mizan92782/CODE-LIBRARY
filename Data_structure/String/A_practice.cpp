#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string S = "aldshflasghdfasgfkhgasdfasdgvfyweofyewyrtyefgv";
    unordered_map<char, int> lastIndex; // Store the last occurrence index of each character
    int maxLength = 0;

    int left = 0; // Left pointer of the current substring

    for (int right = 0; right < S.size(); right++)
    {
        char currentChar = S[right];

        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= left)
        {
            left = lastIndex[currentChar] + 1; // Move the left pointer to the next position after the previous occurrence
        }

        lastIndex[currentChar] = right; // Update the last occurrence index

        maxLength = max(maxLength, right - left + 1); // Update the maximum length
    }

    cout << maxLength << endl;

    return 0;
}
