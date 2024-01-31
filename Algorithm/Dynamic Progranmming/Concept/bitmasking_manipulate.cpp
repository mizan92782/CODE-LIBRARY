#include<bits/stdc++.h>
using namespace std;


//!bitmasking;
int  Bitmasking(vector<int>set)
{
    
    //initial bit;
    int x=1;

    int bitmask=0;

    for(int i=0;i<set.size();i++)
    {
        bitmask=bitmask | (1<<set[i]-1);
    }


    return bitmask;
}




void add_element(int& bit,int x)
{
        cout<<"add element : "<< x<<"  in set\n";
        bit=bit | (1<< x-1);
}



void printValue(vector<int>& set)
{
    cout<<"elemnet of set :  ";
    for(int i=0;i<set.size();i++)
    {
        cout<<set[i]<<" ";
    }


    cout<<endl;
}



void unmasking(vector<int>&set,int bit)
{
      set.clear();
      int x=1;
      while (bit)
      {
        
        if(bit & 1)
        {
            set.push_back(x);
        }

        x++;
        bit=bit>>1;
      }




      
}


int main()
{
     /*
        this topic is very important for cp..
        https://www.youtube.com/watch?v=7FmL-WpTTJ4&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=2
     */


    //set
    vector<int>set{5,6,3,2};
                  
                  /*
                  110110   2+3+16+32=54;
                  */ 


    printValue(set);

    int bit=Bitmasking(set);
    cout<<"bitmasking  : "<<bit<<endl;

    //addelement;
    add_element(bit,4);
    unmasking(set,bit);
   
    printValue(set);


    
}

