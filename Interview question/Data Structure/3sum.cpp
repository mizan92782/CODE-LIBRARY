/*
url : https://www.geeksforgeeks.org/dsa/find-a-triplet-that-sum-to-a-given-value/

*/


#include<bits/stdc++.h>
using namespace std;


//! 1** Hashset or Hashmap approach=====================
/*
 1. considr 1st value for firrt loop
 2. thired valude forn second loop
 3. second value serach from fisrt and thired valude by set or map
*/


bool HasTripletSum(vector<int>& vec,int targer){
    int n= vec.size();

    if (n<3){
        return false;
    }


    
   

    //consider first value from first loop
    for(int i=0;i<n-2;i++){
        // map for find second value
        unordered_map<int, int> second_value_store;

        //thired value from loop 2
        for(int j=i+1;i<n;i++ ){

            int second = targer-vec[i]-vec[j];
            
            // if second value exist in betwee first and second vlaue
            if (second_value_store[second])
            {
                 cout<<"indexs : "<<i<<" - "<<second_value_store[second]<<" - "<<vec[j]<<endl;
                 return true;
            }
        }
        

    }


    return false;

}






int main(){

    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 13;

  
    if (HasTripletSum(arr, target))
        cout << "true";
    else
        cout << "false dfdfas dfdfds dfdf";
}