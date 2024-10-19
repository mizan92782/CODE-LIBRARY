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
        make_heap(vec.begin(),vec.end());


        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();


        /*
         ! removing greatest value,then firt value contain next greatest value
        */
        pop_heap(vec.begin(),vec.end());


        cout<<endl<<endl;
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();


          // head pop korle elemnt delete hoi na,
          // rather add to last 
          // so after second pop its come to first
          // so avoid previous ellent use vec.end()-i;
         pop_heap(vec.begin(),vec.end()-1);


        cout<<endl<<endl;
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();




        /*
         !adding new elment in hea;
          -> add in containger
          ->push container in heap;
        */

       vec.push_back(100);
       push_heap(vec.begin(),vec.end());

        cout<<endl<<endl;
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();



        /*
        ! sort the max heap in ascending order
        * there is a problem in troubleing

        */
         cout<<endl<<endl;
         cout<<"sorting : \n";
         sort_heap(vec.begin(),vec.end());
        
        for_each(vec.begin(),vec.end(),[](int x){ cout<<x<<" ";});
        cout<<"\ngreatest value : "<<vec.front();



        /*
          ! ***** is_heap(), boolean true is ti heap;
        */

        cout<<"is it heap ?  : "<< is_heap(vec.begin(),vec.end());




        /*
          ! is_heap_util() reutrn iteratoer of heap position from front();

        */
       cout<<endl<<endl;
       cout<<"headped value in container : \n";
       vector<int> v = { 40, 30, 25, 35, 15 };

       // ! by defalut its check max heap
       // ! for min heap we have to check  : is_heap_until(v.begin(),v.end(),minheap);
       auto it=is_heap_until(v.begin(),v.end());
       vector<int>::iterator i;
       for( i=v.begin();i!=it;i++)
       {
        cout<<*i<<" ";
       }



         








}