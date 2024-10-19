
#include<bits/stdc++.h>
using namespace std;


int main(){

      int arr[]={5,8,2,4,7,4,7,4,7,3,7};
      int n=sizeof(arr)/sizeof(arr[0]);

      multimap<int,int>mst; 

      for(int i=0;i<n;i++)
      {
          mst.insert({arr[i],i});
      }




      cout<<"Printindf mulitset  :  \n";
      for (auto it=mst.begin();it != mst.end();it++)
      {
        cout<<it->first<<"   "<<it->second<<endl;
      }
      
}