// C program to demonstrate the
// use of an array within a structure
#include<bits/stdc++.h>
using namespace std;


struct candidate {
	int roll_no;
	char grade;

	// Array within the structure
	int  marks[4];
};

// Function to displays the content of
// the structure variables
void display(struct candidate arr[],int n)
{
     int k=4;

	cout<<"Roll --- "<<"Grade --- "<< " { number : } \n";
	for (int i = 0; i < n; i++) {
		
        cout<<arr[i].roll_no<<"          "<<arr[i].grade<<"       ";
        for(int j=0;j<k;j++)
        {
          cout<<arr[i].marks[j]<<"   ";
        }
        cout<<endl;
	} 
}



// Driver Code
int main()
{
	// Initialize a structure
	struct candidate A[] = {
        {1, 'A', {98, 77, 89, 78}},
        {2, 'B', {55, 67, 82, 88}},
        {3, 'C', {59, 83, 78, 23}},
    };

	// Function to display structure
    int n= sizeof(A)/sizeof(A[0]);
	display(A,n);


	return 0;
}
