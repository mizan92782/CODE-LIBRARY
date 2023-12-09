#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll Basic_Euclidean(ll a,ll b)
{
     if(a==0) return b;
    return Basic_Euclidean(b%a,a);
}



int main()
{
     cout<<Basic_Euclidean(556,32); 
}