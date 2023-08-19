#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Initializing vector with array values
    int arr[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
 
    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";
    
    //find element and position by find function
    vect.erase(find(vect.begin(),vect.end(),10));
    cout << "\nVector after erasing element:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";



    cout<<endl<<endl;

    //delete by element

    for(int i=0;i<vect.size();i++)
    { 
        if(vect[i]==42)
        {
            vect.erase(vect.begin()+i);
        }
         
    }



    cout << "\nVector after erasing element at poition:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
    cout<<endl<<endl;


 
    vect.erase(unique(vect.begin(), vect.end()),
               vect.end());
    cout << "\nVector after removing duplicates:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    return 0;
}
