#include<bits/stdc++.h>
using namespace std;

int* returnArray(int n)
{
    static int arr[4];
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }

 return arr;
}

int main()
{

      string str="abf";
      for(int i=0;i<str.size();i++)
      {
        str[i]=str[i]+1;
      }

      cout<<str<<endl;
    return 0;
}