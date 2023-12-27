//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int arr[],int n)
    {
       int mod=1e9+7;
       
       sort(arr,arr+n);
       
       long long  sum=0;
       
       for(int i=1;i<n;i++)
       {
            if(arr[i]>0)
            {
                //! static casting
                //https://chat.openai.com/share/e6b24be9-844c-4f2a-9235-2606cd4d23d5
                sum=sum%mod + static_cast<long long> (arr[i]) * i;
            }
       }
       
       
       return sum%mod;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends