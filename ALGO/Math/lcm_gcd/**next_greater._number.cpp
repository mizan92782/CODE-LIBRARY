

#include<bits/stdc++.h>
using namespace std;


vector<int> nextPermutation(int N, vector<int> arr){
       
        if (std::next_permutation(arr.begin(), arr.end())) {
        // If the next permutation exists, print it
        //printVector(arr);
    } else {
        // If no next permutation exists, rearrange to the lowest order
        std::sort(arr.begin(), arr.end());
       // printVector(arr);
    }
        
       return arr;
    }





int main()
{

//https://www.geeksforgeeks.org/find-next-greater-number-set-digits/


}