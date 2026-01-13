#include<bits/stdc++.h>
using namespace std;



//! ============= print all subarray======
void printsubarray(int arr[],int n,int start,int end)
{
     if(end==n)
     {
        return ;
     }

     if(start>end)
     {
        printsubarray(arr,n,0,end+1);
     }else{
         cout<<"[";
         for(int i=start;i<end;i++)
         {
            cout<<arr[i]<<",";
         }
         cout<<arr[end]<<" ]";
         cout<<endl;
         printsubarray(arr,n,start+1,end);
     }
}

 //serial maintain kore
 void printsubarray2(int arr[],int n)
 {
     for(int i=0;i<n;i++)
     {
         
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<",";
            }
            cout<<"\n";
        }
        
     }
 }

 
int main()
{
     int arr[]={1,2,3,4};
     int n=8;

     printsubarray2(arr,4);

       
}
     