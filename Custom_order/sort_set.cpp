#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



int frq[10000]={0};




struct sortCri {
    bool operator()(int a, int b) const {
        // Customize the sorting order here
        if (frq[a] == frq[b]) return a > b;  // Sort values in descending order
        else return frq[a] < frq[b];         // Sort frequencies in ascending order
    }
};


int main() {
    vector<int> ans{2,3,4,1,2,3,4,5,2,45,74,4};
    
    
    for(int i=0;i<ans.size();i++) {
        frq[ans[i]]++;
    }

    set<int,sortCri> myset(ans.begin(), ans.end());


     //another app..
   //set<int, decltype([](int a, int b) { return fr[a] == fr[b] ? a > b : fr[a] < fr[b]; })> nums;

    for(auto it : myset) {
        cout << it << " ";
    }

    return 0;
}
