#include<bits/stdc++.h>
using namespace std;

void subsetPrint(int n)
{
     cout<<n<<"  containg element of  subset : ";

     int x=1;
     while (n)
    {
        // if nth bit is 1,the its set contain this element
        if(n&1==1)
        {
            cout<<x<<" ";
        }
        x++;
        n=n>>1;
    }

    cout<<endl;
}





// ! **** bitmasking...............


void bitmasking(vector<int>vec)
{
   //** set set bit for or operation to find bit value;
   int x=1;

   int bit=0;
   for(int i=0;i<vec.size();i++)
   {
          bit=bit | (x<<vec[i]-1);
   }



   cout<<"bitmasking of set is : "<<bit<<endl;
}


int main()
{
    


  // ! print subset from bitmasking
   subsetPrint(22);
   subsetPrint(32);
   subsetPrint(27);
   subsetPrint(15);


   
   //* make bitmasking and pring number;
  //mking decimal nmber from set
  
   vector<int>vec={2,3,5};
    //10110=22
   bitmasking(vec);


   vec={4,7,2};
   //1001010=74
   bitmasking(vec);


   cout<<endl<<endl;
   cout<<"print all subset from 1 to 10 number : "<<endl<<endl<<endl;

   //making 10 bits number
   int x=1;
   for(int i=1;i<=10;i++)
   {
    x=x<<1;
    
   }

   //print all subset for 10
   for(int i=1;i<x;i++)
   {
    subsetPrint(i);
   }





  

  
}
