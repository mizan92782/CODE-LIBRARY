#include<bits/stdc++.h>
using namespace std;




int main()
{
    vector<int>vec{1,1,2,3,3,4,5};


   
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";


}