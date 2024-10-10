
#include<bits/stdc++.h>
using namespace std;


 void printSubSet(int n)
 {
     cout<<n<<" : subset :  -->  : ";
     
     //initial subset number
     int x=1;

     while (n)
     {
         //if nth bit is 1,then this contain this element
         if(n&1)
         { 
            cout<<x<<" ";
         }

         //check for next number
         x++;

         n=n>>1;
     }


     cout<<endl;
     
 }



 int  Bitmaking_subset(vector<int> vec)
 {
      //for set vec[i] bit 1 by x<<vec[i]-1;
     /*
        x=1;
        vce[i]=5;
        x<<vec[i]-1;
        result: 10000
     */
     int x=1;

     
     //count result;
     int bit=0;

     for(int i=0;i<vec.size();i++)
     {
        //  or(|) operation increase length of bitleng and sum of set element
        bit=bit|(x<<vec[i]-1);
     }


     cout<<"bitmusking : "<<bit<<endl;



     return bit;


 }





 void Check_set(vector<int>one,vector<int>two)
 {
       int bitone=Bitmaking_subset(one);
       int bittwo=Bitmaking_subset(two);

       if(bitone==bittwo)
       { 
           cout<<"Contain same set"<<endl;
           
       }else{
          
          cout<<"Dont Contain same set\n";
       }
       

}



void intersetion(vector<int>one,vector<int>two)
{
       int xone=Bitmaking_subset(one);
       int xtwo=Bitmaking_subset(two);

       
       cout<<"intersection element : [";

       int x=1;

       while (xone &&  xtwo)
       {
           if(xone&1 && xtwo&1)
           {
               cout<<x<<",";
           }

           x++;
           xone=xone>>1;
           xtwo=xtwo>>1;

       }

       cout<<" ]"<<endl<<endl;
       
}










void unionset(vector<int>one,vector<int>two)
{
       int xone=Bitmaking_subset(one);
       int xtwo=Bitmaking_subset(two);

       
       cout<<"Union of sets element : [";

       int x=1;

       while (xone ||  xtwo)
       {
           if(xone&1 || xtwo&1)
           {
               cout<<x<<",";
           }

           x++;
           xone=xone>>1;
           xtwo=xtwo>>1;

       }

       cout<<" ]"<<endl<<endl;
       
}










void Differentset(vector<int>one,vector<int>two)
{
       int xone=Bitmaking_subset(one);
       int xtwo=Bitmaking_subset(two);

       
       cout<<"Doffernt of sets element : [";

       int x=1;

       while (xone ||  xtwo)
       {
           if(((xone & 1) == 1 && (xtwo & 1) == 0) || ((xone & 1) == 0 && (xtwo & 1) == 1))
           {
               cout<<x<<",";
           }

           x++;
           xone=xone>>1;
           xtwo=xtwo>>1;

       }

       cout<<" ]"<<endl<<endl;
       
}




int main()
{


  //!print set elemnt
  printSubSet(10);
  printSubSet(32);
  printSubSet(33);



  //! make set element bitmasking
  vector<int>vec={2,3,5};
    //10110=22
   Bitmaking_subset(vec);


   vec={4,7,2};
   //1001010=74
   Bitmaking_subset(vec);



   


   //!check two set have same element
   cout<<endl<<endl;
   Check_set({2,3,5},{6,5,6});



    cout<<endl<<endl;
   Check_set({2,3,5},{5,3,2});



   //!intersection
    intersetion({5,3,4,7,3},{2,5,3,6,7});


    //!unionset
    unionset({5,3,4,7,3,11},{2,5,3,6,7});


    Differentset({5,3,4,7,3},{2,5,3,6,7});





}