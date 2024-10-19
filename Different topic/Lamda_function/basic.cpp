#include<bits/stdc++.h>
using namespace std;




int main()
{



  /* 
       stu: auto lamda_name=[capture cluse](perameter){
             
              body

          return ;
       }
  */


  auto hellow=[](int x)
  {
          cout<<"this is basic lambda : "<<x<<endl;
        return x;
  };


  for(int i=0;i<5;i++)
  {
    cout<< hellow(i)<<endl;
  }


return 0;
}