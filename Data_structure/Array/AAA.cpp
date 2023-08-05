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

       vector<int>vac{4,4,6,2,2,62,5,2,3,2};

         vac.erase(unique(vac.begin(),vac.end()),vac.end());

       for(int i=0;i<vac.size();i++)
       {
        cout<<vac[i]<<" ";
       }
    return 0;
}