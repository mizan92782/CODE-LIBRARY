#include<bits/stdc++.h>
using namespace std;



int main()
{
     
    



    int arr[]={6,4,7,43,75,75};

    int n=6;

    map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }



    for(auto it=mp.rbegin();it!=mp.rend();it++)
    {
         cout<<it->first<<"  "<<it->second<<endl;
    }

    
     




     
}