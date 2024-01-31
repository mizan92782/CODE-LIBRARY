#include<bits/stdc++.h>
using namespace std;


int main()
{

    //*** inserter in very imp:
    //** inserter insert a container in in they positin of other container

    vector<int>vec{4,5,6,78,355,66};
    vector<int>inst{0,0,0,0,0};

    // ** insert inst in 3 position of vec
    auto it=vec.begin()+2;
    //we can isert amount of inst value by creating ptr of position
    copy(inst.begin(),inst.end(),inserter(vec,it));





    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }

   

    
}