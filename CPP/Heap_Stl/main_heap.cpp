#include<bits/stdc++.h>
using namespace std;


// ! ******comperatro funciton for min head
bool minheap(int x,int y) { return x>y;}

int main()
{
        vector<int>vec{5,6,33,77,1,12,61};

        /*
        ! making container head,its not make container sort
        ! but always first value keep greaest value;
        */
        make_heap(vec.begin(),vec.end(),minheap);


        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();


        /*
         ! removing greatest value,then firt value contain next greatest value
        */
        pop_heap(vec.begin(),vec.end(),minheap);


        cout<<endl<<endl;
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();



        /*
         !adding new elment in hea;
          -> add in containger
          ->push container in heap;
        */

       vec.push_back(2);
       push_heap(vec.begin(),vec.end());

        cout<<endl<<endl;
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();



           /*
        ! sort the max heap in ascending order
          * heve a troble in sorting heap;
        */
          cout<<endl<<endl;
          cout<<"sorting : \n";
         sort_heap(vec.begin(),vec.end(),minheap);
        
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
       








}