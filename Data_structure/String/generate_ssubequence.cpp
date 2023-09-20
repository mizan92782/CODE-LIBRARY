// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist character of
	// Input string
	printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence(input.substr(1), output);
}


// !withour changing input string

void printSubsequence1(int i,string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (i==input.size()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist character of
	// Input string
	printSubsequence1(i+1,input, output + input[i]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence1(i+1,input, output);
}









// Driver code
int main()
{
	// output is set to null before passing in as a
	// parameter
	string output = "";
	string input = "abcd";

	printSubsequence1(0,input, output);

	return 0;
}
