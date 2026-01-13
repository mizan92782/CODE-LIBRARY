//https://www.geeksforgeeks.org/2sum/

#include<bits/stdc++.h>
using namespace std;


//! ========== two sum ======
//! using hashing O(n) time and O(n) space
bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    // Iterate through each element in the vector
    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}