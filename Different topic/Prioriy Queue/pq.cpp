#include<bits/stdc++.h>
using namespace std;






int main()
{
 int arr[6] = { 44, 2, 4, 8, 6, 9 };
 int n=sizeof(arr)/sizeof(arr[0]);


// ** By default ,max heap;
 priority_queue<int>pq(arr,arr+n);



 cout<<"\n\n after push a random valu \n";
 pq.push(33);


 cout<<"priority queue:  ";
 while (!pq.empty())
 {
     cout<<pq.top()<<" ";
     pq.pop();

 }






    return 0;
}