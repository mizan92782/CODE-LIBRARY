#include<bits/stdc++.h>
using namespace std;

struct  Price
{
     int apple;
     int banana;
     int orange;
     int potato;
     Price(int x, int y,int z,int zz)
     {
        this->apple=x;
        this->banana=y;
        this->orange=z;
        this->potato=zz;
     }


     void fun()
     {
         cout<<apple<<" : "<<banana<<" : "<<orange<<" : "<<potato<<endl;
     }
     

     
};





//! ****** Comperative programming

// sort depend of same element
bool Comperative1(Price x, Price y)
{
      
      return   x.orange > y.orange;
}


// sort depend of different element
bool Comperative2(Price x, Price y)
{
      
      return   x.orange > y.banana;
}



//! sort depend of  multiple condition
bool Comperative3(Price x, Price y)
{
      
      return   (x.orange > y.banana)  && (x.orange>y.apple);
}



//! sort depend of  arithmatic conditon
bool Comperative4(Price x, Price y)
{
      
      return   (x.banana+x.potato) > y.orange;
}






int main()
{

    /* 
      *when we have to work with multiple data set,then struct in best than map
      *map can store 2 value and store uniquely, but struc is rock ,,ooooya oooyah          

    */
   
    Price Fruit[]={{4,7,22,55},{5,22,6,2},{5,1,77,32},{1,5,2,99}};

    int size=sizeof(Fruit)/sizeof(Fruit[0]);

   

   cout<<"Initial value :  \n";
    for(int i =0;i<size;i++)
    {
            Fruit[i].fun();
    }


    cout<<endl<<endl;


    cout<<"sort depent of orange price  (orange > banane) in descending;  \n";
    sort(Fruit,Fruit+size,Comperative1);

    for(int i =0;i<size;i++)
    {
            Fruit[i].fun();
    }




    cout<<endl<<endl;


    cout<<"sort depent of differnt elment  price  in descending;  \n";
    sort(Fruit,Fruit+size,Comperative2);

    for(int i =0;i<size;i++)
    {
            Fruit[i].fun();
    }



    cout<<endl<<endl;


    cout<<"sort depent multiple condition; (orange > apple and banana) \n";
    sort(Fruit,Fruit+size,Comperative3);

    for(int i =0;i<size;i++)
    {
            Fruit[i].fun();
    }



     cout<<endl<<endl;


    cout<<"sort depend of arithmatic conditio ; (potato+banana > orange) \n";
    sort(Fruit,Fruit+size,Comperative4);

    for(int i =0;i<size;i++)
    {
            Fruit[i].fun();
    }

    
    
}