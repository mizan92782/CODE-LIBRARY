#include<bits/stdc++.h>
using namespace std;


// work on sorted arr
//https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/


int main()
{
     int arr[5]={4,6,2,11,55};


    sort(arr,arr+5);
    if(binary_search(arr,arr+5,6))
    {
        cout<<"found\n";
    }else{
         
         cout<<"not fount\n";
    }
}