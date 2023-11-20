#include<bits/stdc++.h>
using namespace std;

void element(int arr[],int n)
{
    int first=0,second =0,thired=0;

    for(int i=0;i<n;i++)
    {
      if(arr[i]>first)
      {
         thired=second;
        second=first;
        first=arr[i];
      }
    }


    cout<<first<<" "<<second<<" "<<thired;


}

int main()
{
   int arr[]={4,5,33,2,6,3,55,36};
   int n=4;
   int k=33;

   
  int x=(n + 1) * (n + 2) / 2;
  cout<<x<<endl;
  return 0;
}