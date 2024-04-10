#include<bits/stdc++.h>
using namespace std;




int main(int argc, const char** argv) {

       //! minmax() return a pair, where first is minimum
       // ! and second is max element
       cout<<"case : 1\n";
       pair<int,int>p;
       p=minmax(5,66);
       cout<<p.first<<" "<<p.second<<endl;


       /*
       
         * for container
       
       */


      cout<<endl<<endl;
      cout<<"minmax _element for container  withour sorring: -> \n";
      vector<int>vec={51,8,22,6,43,12,44};
      auto it=minmax_element(vec.begin(),vec.end());
      cout<<*it.first<<" "<<*it.second<<endl<<endl;





       /* 
       ! ***max elment ,min elment ,minmax alse can use is string*/
       string name="mizan";

       cout<<"max char : -> " <<*max_element(name.begin(),name.end())<<endl;
       cout<<"max char : -> " <<*min_element(name.begin(),name.end())<<endl;
       cout<<"max char : -> " <<minmax('x','a').first<<endl;



       




    return 0;
}