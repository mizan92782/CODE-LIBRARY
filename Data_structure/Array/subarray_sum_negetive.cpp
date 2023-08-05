#include<bits/stdc++.h>
using namespace std;

int Naive_approach(int arr[],int n,int sum)
{
   //(n^2)
       

       for(int i=0;i<n;i++)
       {

        int current=0;
         for(int j=i;j<n;j++)
         {
             current= current+arr[j];
             if(current==sum){
                 cout<<"sum found in index : "<<i<<" to "<<j<<endl;
                 return current;
             }
         }
       }

    return -1;
}




// Function to print subarray with sum as given sum
void subArraySum_hash(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// Maintains sum of elements so far
	int curr_sum = 0;

	for (int i = 0; i < n; i++) {
		// add current element to curr_sum
		curr_sum = curr_sum + arr[i];

        cout<<curr_sum<<endl;

		// if curr_sum is equal to target sum
		// we found a subarray starting from index 0
		// and ending at index i
		if (curr_sum == sum) {
			cout << "Sum found between indexes " << 0
				<< " to " << i << endl;
			return;
		}

		// If curr_sum - sum already exists in map
		// we have found a subarray with target sum
		if (map.find(curr_sum - sum) != map.end()) {
            
			cout << "Sum found between indexes "
				<< map[curr_sum - sum] + 1 << " to " << i
				<< endl;
			return;
		}

		map[curr_sum] = i;
	}

	// If we reach here, then no subarray exists
	cout << "No subarray with given sum exists";
}




void Hashing_map(int arr[],int n)
{
            map<int,int>map;
}


int main()
{
	//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
     int arr[]={1,3,-2,-4,8,2,-2,4,7};
     int n =sizeof(arr)/sizeof(arr[0]);
     subArraySum_hash(arr,n,11);

     return 0;
}