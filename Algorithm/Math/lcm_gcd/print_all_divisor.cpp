#include<bits/stdc++.h>
using namespace std;


// * Naive approach,order wise
void Naive_approach(int N){
    for (int i = 1; i <= N; i++) 
        if (N % i == 0) 
            cout <<" " << i; 
    

    cout<<endl;
}




//** optimize way ,order wise

void optimizeDivisor(int N)
{
     for(int i=1;i<=N/2;i++)
     {
          if(N%i==0)
          {
            cout<<i<<" ";
          }
     }


     cout<<N<<endl;
}




// *** pariwise Factor,important;

void pairwiseDovisor(int N)
{
      for(int i=1;i<=sqrt(N);i++)
      {
         if(N%i==0)
         {
             //  ! suppse x=100, so if (2 * 5),if 2 is factor also x/2=50 also a factor
             if(N/i!=i)
             {
                 cout<<i<<" "<<N/i<<" ";
             }else{
                // ! if i and N/i both are same like (10 * 10) print only one
                cout<<i<<" ";
             }
         }
      }


      cout<<endl;
}






// !!! vv1
void pairwiseDovisor_orderwise(int N)
{
       vector<int>order;


       // find half orderwise factor;
      for(int i=1;i<=sqrt(N);i++)
      {
         if(N%i==0)
         {
            order.push_back(i);
         }
      }


        // ** adding ther quardant

       int n=order.size();
       for(int i=n-1;i>=0;i--)
       {    
            //(10,10) ,if both same ,not need to add
           if(N/order[i]==order[i]) continue;

           order.push_back(N/order[i]);


       }


       cout<<"order wise by using pairwise approach";
       for(int i=0;i<order.size();i++)
       {
               cout<<order[i]<<" ";
       }

       cout<<endl;






     
}




int main()
{

       // https://www.geeksforgeeks.org/find-all-factors-of-a-natural-number/
      int N=100;
      cout<<" its pairwise : ";
      pairwiseDovisor(N);

      cout<<"its order wise: ";
      optimizeDivisor(N);

      pairwiseDovisor_orderwise(N);

      
}