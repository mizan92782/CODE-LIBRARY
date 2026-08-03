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


bool HasTripletSum(vector<int>& vec,int target){
    int n= vec.size();

    if (n<3){
        return false;
    }


    
   

    //consider first value from first loop
    for(int i=0;i<n-2;i++){
        // map for find second value
        unordered_map<int, int> second_value_store;

        //thired value from loop 2
        for(int j=i+1;i<n;j++ ){

            int second = target-vec[i]-vec[j];
            
            // if second value exist in betwee first and second vlaue
            if (second_value_store[second])
            {
                cout << vec[i] << " " << second << " "<<vec[j] << endl;
                return true;
            }
            

            // add thired value in map to become second value
            second_value_store[vec[j]]++;
        }
        

    }


    return false;

}




//! ***Approach 2 : Sort and two pointer--------------------
bool HasTripleSum_SortTwoPointer(vector<int>vec,int target){

    int n = vec.size();

    if(n<3){
        return false;
    }


    // sort full array
    sort(vec.begin(),vec.end());

    for(int i=0;i<n-2;i++){

        int first = vec[i];
        int rem= target-first;

        int j=i+1;
        int k=n-1;
        
        while(j<k){

            if(vec[j]+vec[k]==rem){
                cout<<first<<"kjkjkjk "<<vec[j]<<" "<<vec[k]<<endl;
                return true;
            }
            if(vec[j]+vec[k]<rem){
                j++;
            }else{
                k--;
            }
        }

    }

    return false;
}



int main(){

    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 13;

      if (HasTripleSum_SortTwoPointer(arr, target)){
          cout << "true" << endl;
      }else{
          cout << "false" << endl;
      }
}
      