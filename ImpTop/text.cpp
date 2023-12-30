#include <bits/stdc++.h>
using namespace std;

int main() {


  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      int arr[n];
      
      int index=0;
      int maxi=INT_MIN;
      
      for(int i=0;i<n;i++) 
      {
          cin>>arr[i];
          
          if(arr[i]>maxi)
          {
              maxi=max(maxi,arr[i]);
              index=i;
          }
          
      }
      
      
       cout<<"\n--"<<endl;
       cout<<n-index-1<<endl;
     
     
  }

}
