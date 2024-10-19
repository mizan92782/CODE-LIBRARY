// C++ program to demonstrate working of count()
// and find()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Initializing vector with array values
	int arr[] = {10, 200, 5, 23 ,42, 200, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	cout << "Occurrences of 20 in vector : ";

	// Counts the occurrences of 20 from 1st to
	// last element
	cout << count(vect.begin(), vect.end(), 20);

	// find() returns iterator to last address if
	// element not present
	//if not need to know position

	find(vect.begin(), vect.end(),20) != vect.end()?
						cout << "\nElement found\n":
					cout << "\nElement not found\n";

    


    
	// if need to know position
	
    int pos=find(vect.begin(), vect.end(),20)-vect.begin();

	if(pos==n)
	{
		cout<<"not found\n";
	}else{
		 cout<<"position : "<<pos<<endl;
	}

	return 0;
}
