#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& num)
 {
        
        cout<<"kk";
        int n=num.size();
        int m=n;
       
        if(num.size()==1) return 0;

         
         int t=0;


        int i=0;
        while(n)
        {
            int x=num[i];
            int maxE=0;
            int maxI=0;

            for(int j=i+1;j<=x;j++)
            {
                 if((j+num[j])>maxE)
                 {
                      maxE=(j+num[j]);
                      maxI=j;
                 }
            }

            n=m-maxI+num[maxI];
            i=maxI;
            t++;

            if(n==1)
            {
                  break;
            }

            cout<<"jump "<<t<<endl;

           
        }

        return t;
     }



int main()
{

     vector<int>vee{2,1,1,1,2,1};
     cout<< " dddddd "<<jump(vee);


}