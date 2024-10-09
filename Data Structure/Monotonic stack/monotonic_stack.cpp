#include<bits/stdc++.h>
using namespace std;


void NextSmallerNumber(vector<int>arr)
{        
         int n=arr.size();
         vector<int>result(n,-1);
         stack<int>st;


         for(int i=0;i<n;i++)
         {
               while (!st.empty() && arr[st.top()]>arr[i])
               {
                    result[st.top()]=arr[i];
                    st.pop(); 
               }

             
                 st.push(i);
               
               
               
         }


         
        cout<<"Next Smaller Number : ";
        for(int x:result) cout<<x<<" ";
}







void NextGreaterNumber(vector<int>arr)
{        
         int n=arr.size();
         vector<int>result(n,-1);
         stack<int>st;


         for(int i=0;i<n;i++)
         {
               while (!st.empty() && arr[st.top()]<arr[i])
               {
                    result[st.top()]=arr[i];
                    st.pop();
               }

               st.push(i);
               
         }


         
        cout<<"Next Greater Number : ";
        for(int x:result) cout<<x<<" ";
}





int main()
{ 
       vector<int>arr={4,5,1,15,29,5,22,44,2};
       NextSmallerNumber(arr);
       cout<<endl;
       NextGreaterNumber(arr);
       
}