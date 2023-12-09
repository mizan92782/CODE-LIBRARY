

// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence
#include <algorithm>
#include <cstring> // for memset
#include <iostream>
#include <string>

using namespace std;

// palindromic subsequence in seq
int lps(char* seq, int i, int j)
{
 
    // Base Case 1: If there is
    // only 1 character
    if (i == j)
        return 1;
 
    // Base Case 2: If there are only 2
    // characters and both are same
    if (seq[i] == seq[j] && i + 1 == j)
        return 2;
 
    // If the first and last characters match
    if (seq[i] == seq[j])
        return lps(seq, i + 1, j - 1) + 2;
 
    // If the first and last characters
    // do not match
    return max(lps(seq, i, j - 1), lps(seq, i + 1, j));
}













int longestPalinSubseq(string S)
{
	string R = S;
	reverse(R.begin(), R.end());

	// dp[i][j] will store the length of the longest
	// palindromic subsequence for the substring
	// starting at index i and ending at index j
	int dp[S.length() + 1][R.length() + 1];

	// Initialize dp array with zeros
	memset(dp, 0, sizeof(dp));

	// Filling up DP table based on conditions discussed
	// in the above approach
	for (int i = 1; i <= S.length(); i++) {
		for (int j = 1; j <= R.length(); j++) {
			if (S[i - 1] == R[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	// At the end, DP table will contain the LPS
	// So just return the length of LPS
	return dp[S.length()][R.length()];
}

// Driver code
int main()
{

    //https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
	string s = "GEEKSFORGEEKS";
	cout << "The length of the LPS is "
		<< longestPalinSubseq(s) << endl;

	return 0;
}

// This code is contributed by akshitaguprzj3
