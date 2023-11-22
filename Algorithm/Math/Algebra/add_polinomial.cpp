#include<bits/stdc++.h>
using namespace std;


void printPolinomial(int arr[],int n)
{
     for(int i=0;i<n;i++)
     {
        if(i==0)
        {
            cout<<arr[i];
        }else{
            cout<<arr[i]<<"x^"<<i;
        }


        if(i!=n-1)
        {
            cout<<"+";
        }


     }

     cout<<endl;
}




int* addPolinomial(int A[],int B[],int m,int n)
{
        int maxValue=max(m,n);

        int* sum = new int[maxValue];
       

        for(int i=0;i<m;i++){
             sum[i]=0;
             sum[i]=A[i];
        }


         for(int i=0;i<n;i++){
             
             sum[i]=sum[i]+B[i];
        }




           
        


return sum;

}

int main()
{


    // https://www.geeksforgeeks.org/memset-in-cpp/


    
    int A[] = { 5, 0, 10, 6 };
    int B[] = { 1, 2, 4 };


    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);


    cout<<"First polinomial :  ";
    printPolinomial(A,m);

    cout<<"Second polinomial :  ";
    printPolinomial(B,n);



    int* sum=addPolinomial(A,B,m,n);


    cout<<"Sum of polinomial :  ";

     printPolinomial(sum,max(m,n));
}