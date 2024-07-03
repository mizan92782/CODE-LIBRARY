// C++ program to print all permutations with
// duplicates allowed using next_permutation
#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string str
// using next_permutation
void permute(string str)
{
	// Sort the string in lexicographically
	// ascending order
	sort(str.begin(), str.end());

	// Keep printing next permutation while there
	// is next permutation
	do {
	cout << str << endl;
	} while (next_permutation(str.begin(), str.end()));
}

// Driver code
int main()
{


    //https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/
    
	string str = "CBA";
	permute(str);
	return 0;
}
