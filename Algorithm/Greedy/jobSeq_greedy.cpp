#include<bits/stdc++.h>
using namespace std;


struct  Job
{
     char id;
     int dead;
     int profit;
};



bool profitComperator(Job x, Job y)
{
     return x.profit > y.profit;
}




void printJobSchedulling(Job arr[],int n)
{

    // step 1:  sort job according to profin in descending order
     sort(arr,arr+n,profitComperator);


     //** create job slot;
     vector<bool>slot(n,false);
     vector<bool>result(n);


      // iterater for all the job
     for(int i=0;i<n;i++)
     {
          // ** find the free slot for the job
          //! ***** Node that ,we start from the last possible slot,as 
          //! we can get more plexibity for other job and as we get most profit job first
          // ! so get maximum profit


           // 1 sec : time from 0 - 1 ,if it react to 1,its dead
          for(int  j=min(n,arr[i].dead)-1;j>=0;j--)
          {

               //** check if slot is available to accept this job
               if(slot[i]==false)
               {
                    //accept job
                    result[j]=i;


                    slot[j]=true;
                    break;
               }
          }

     }





      int sum=0;

      cout<<"accepted job : ";
      for(int i=0;i<n;i++)
      {
         if(slot[i])
         {
             sum=sum+arr[i].profit;
             cout<<arr[i].id<<" ";
         }
      }


      cout<<"\nmaximum profit :  "<<sum;

}



int main()
{
     
  //https://www.geeksforgeeks.org/job-sequencing-problem-using-disjoint-set/
  //https://www.geeksforgeeks.org/job-sequencing-problem/

     // ***  job
     Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

    int n=sizeof(arr)/sizeof(arr[0]);


    printJobSchedulling(arr,n);

   
   
}