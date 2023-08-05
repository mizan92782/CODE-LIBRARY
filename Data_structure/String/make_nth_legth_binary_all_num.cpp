// C++ program to count all distinct
// binary strings with two consecutive 1's
#include <iostream>
using namespace std;

// Gives count of n length binary
// strings with consecutive 1's
void countStrings(int n,int ind,string str)
{
	if(ind==n){
		int count=0;
	       cout<<str<<endl;
		return;
	}
	
	countStrings(n,ind+1,str+"0");
	countStrings(n,ind+1,str+"1");
}

// Driver code
int main()
{
	countStrings(5,0,"") ;
	return 0;
}
