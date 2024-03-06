#include<bits/stdc++.h>
using namespace std;


int main()
{

    // *https://www.geeksforgeeks.org/stdnth_element-in-cpp/
     vector<int>vec{5,4,7,2,699,3,6,22};
     
     nth_element(vec.begin(),vec.begin()+2,vec.end());

    
    for(auto it :vec)
    {
        cout<<it<<endl;
    }
}