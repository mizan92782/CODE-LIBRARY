#include <bits/stdc++.h>
using namespace std;

void gray_code(int n)
{
      vector<string>vec;
      vec.push_back("0");
      vec.push_back("1");

      while (vec[0].size()<n)
      {
             int i=vec.size()-1;
              int k=i;
             for(i;i>=0;i--)
             {
                  vec.push_back(vec[i]);
             }

              i=k;
            // we need initaial vec size  before adding reverse value;

             for(int j=0;j<=i;j++)
             {
                  vec[j]="0"+vec[j];
             }

             
             for(int j=i+1;j<vec.size();j++)
             {
                  vec[j]="1"+vec[j];
             }
      }



      cout<<"Gray code :  ";
      for(int i=0;i<vec.size();i++)
      {
            cout<<vec[i]<<" ";
      }
      
}


int main()
{
       gray_code(3);
}