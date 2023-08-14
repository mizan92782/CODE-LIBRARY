#include<bits/stdc++.h>
using namespace std;


int main()
{
     vector<int>vec{5,4,7,2,699,3,6,22};
     
     nth_element(vec.begin(),vec.begin()+4,vec.end(),greater<int>());

    
    for(auto it :vec)
    {
        cout<<it<<endl;
    }
}