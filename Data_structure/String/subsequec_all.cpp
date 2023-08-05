// C++ program to count number of distinct
// subsequences of a given string.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

// Returns count of distinct subsequences of str.
int countSub(string str)
{
	// Create an array to store index
	// of last
	vector<int> last(MAX_CHAR, -1);

	// Length of input string
	int n = str.length();

	// dp[i] is going to store count of distinct
	// subsequences of length i.
	int dp[n + 1];

	// Empty substring has only one subsequence
	dp[0] = 1;

	// Traverse through all lengths from 1 to n.
	for (int i = 1; i <= n; i++)
	{
		// Number of subsequences with substring
		// str[0..i-1]
		dp[i] = 2 * dp[i - 1];
		// If current character has appeared
		// before, then remove all subsequences
		// ending with previous occurrence.
		if (last[str[i - 1]] != -1)
		{
			dp[i] = dp[i] - dp[last[str[i - 1]]];
		}

		// Mark occurrence of current character
		last[str[i - 1]] = (i - 1);
	}

	return dp[n];
}

// Driver code
int main()
{        
	    string str="testsample";
	    int max=0;
         char c=' ';
         sort(str.begin(),str.end());
         
         char t=str[0];
         int count=1;

		 cout<<str<<endl;
         
         
         for(int i=1;i<str.size();i++)
         {
             if(str[i]==t)
             {  

				
                  count++;
                  t=str[i];
                  if(count>max)
                  {
                      max=count;
                      c=str[i];
					  
                  }
             }else
             {
                 count=1;
				 t=str[i];
             }
         }


		 cout<<c<<endl;

}
