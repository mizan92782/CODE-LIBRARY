#include<bits/stdc++.h>
using namespace std;


// use for pertioning elemnt under condttion
//return pivot ptr

int main()
{
     int arr[]={4,6,2,11,55,77,24,66,44,1,4,7,3};

     int n=sizeof(arr)/sizeof(arr[0]);

    auto t=partition(arr,arr+n, [](int x)
    {
        return x%2==0;
         
    });

    
    cout<<"pivot or peritont poin : "<<t-arr<<endl;



    for(auto it:arr)
    {
        cout<<it<<" ";
    }

 cout<<endl;

// chekong is the already petioning
is_partitioned(arr,arr+n, [](int x)
    {
        return x%2==0;
         
    })? cout<<"yes\n" :cout<<"no\n";

   
}