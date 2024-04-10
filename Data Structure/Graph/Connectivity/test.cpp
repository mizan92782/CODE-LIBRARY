#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>graph(26);



int main(int argc, const char** argv) {

    string  arr[] = {"for", "geek", "rig", "kaf"};
       int n=4;
      map<char,char>mymap;
      
       char c=arr[0][0];
       
       char d=arr[0][arr[0].size()-1];
       mymap[c]=d;

       for(int i=1;i<n;i++)
       {
          char x=arr[i][0];
          char y=arr[i][arr[i].size()-1];

          if(d!=x)
          {
           mymap[d]=x;
          }

          if(x!=y)
          {
           mymap[x]=y;
          }

          d=y;
       }

      int num=10;
      char find=d;
     while(mymap[d])
     {
           if(find==mymap[d])
           {
              cout<<"same : "<<d<<" "<<mymap[d]<<endl;
              break;
           }
           
           cout<<d<<" --> "<<mymap[d]<<endl;
          d=mymap[d];
         
        
     }




    return 0;
}