#include<bits/stdc++.h>
using namespace std;


//normaly we cant push_front() in vector,but we can use 
//empale(begin(),x) to puhs_foront();

// we can use list to push_front();but its havent index,so
//ovoid this problem we can use vector && emplace();
void showpq(priority_queue<int,vector<int>, greater<int>> x)
{
    priority_queue<int,vector<int>, greater<int>> g;
    g=x;
    while (!g.empty()) {
        cout << ' ' << g.top();
        g.pop();
    }
    cout << '\n';
}


int main()
{
      
     vector<int>vec{7,44,85,5,77,33,75,11,55,6,3,99};
     priority_queue<int,vector<int>, greater<int>>pq(vec.begin(),vec.end());

         showpq(pq);
           cout<<endl;
     
         showpq(pq);
   





}