// C++ program to print the number of subarrays such
// that all elements are greater than K
#include <bits/stdc++.h>
using namespace std;

// Function to count number of subarrays
int countSubarrays(int a[], int n, int x)
{
	int count = 0;

	int number = 0;

	// Iterate in the array
	for (int i = 0; i < n; i++) {

		// check if array element
		// greater than X or not
		if (a[i] > x) {
			count += 1;

            cout<<count<<endl;
            number=number+count;
		}
		else {

			
			count = 0;
		}
	}

	

	return number;
}

// Driver Code
int main()
{
	int a[] = { 3, 4, 5, 6, 7, 2, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 5;

	cout << countSubarrays(a, n, k);

	return 0;
}
