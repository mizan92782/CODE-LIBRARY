#include<bits/stdc++.h>
using namespace std;


int main()
{

    vector<int>vec{4,5,6,78,355,66,66,3};

    auto it=vec.begin();

    //! advance() forward container to a certaing position
    advance(it,5);
    
    // distacce() give distance
    cout<<distance(vec.begin(),it)<<endl;

    
}