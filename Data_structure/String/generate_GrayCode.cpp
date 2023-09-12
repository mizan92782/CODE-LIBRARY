// C++ program to generate n-bit Gray codes
#include<bits/stdc++.h>
using namespace std;

// This function generates all n bit Gray codes and prints the
// generated codes
void generateGrayarr(int n)
{
	// base case
	if (n <= 0)
		return;

	// 'arr' will store all generated codes
	vector<string> arr;

	// start with one-bit pattern
	arr.push_back("0");
	arr.push_back("1");

	// Every iteration of this loop generates 2*i codes from previously
	// generated i codes.
	int i, j;
	for (i = 2; i < (1<<n); i = i<<1)
	{
		// Enter the previously generated codes again in arr[] in reverse
		// order. Nor arr[] has double number of codes.
		for (j = i-1 ; j >= 0 ; j--)
			arr.push_back(arr[j]);

		// append 0 to the first half
		for (j = 0 ; j < i ; j++)
			arr[j] = "0" + arr[j];

		// append 1 to the second half
		for (j = i ; j < 2*i ; j++)
			arr[j] = "1" + arr[j];
	}

	// print contents of arr[]
	for (i = 0 ; i < arr.size() ; i++ )
		cout << arr[i] << endl;
}


// !! make from decimal num=n;
void GreyCode(int n)
{
     // power of 2
    for (int i = 0; i < (1 << n); i++)
    {
        // Generating the decimal
        // values of gray code then using
        // bitset to convert them to binary form
        int val = (i ^ (i >> 1));
         
        // Using bitset
        bitset<32> r(val);
         
        // Converting to string
        string s = r.to_string();
        cout << s.substr(32 - n) << " ";
    }
}

// Driver program to test above function
int main()
{


    //https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
	generateGrayarr(3);
    cout<<endl;
    GreyCode(3);
	return 0;
}
