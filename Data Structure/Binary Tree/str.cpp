#include<bits/stdc++.h>
using namespace std;

 string reorganizeString(string s) {
        

        int n=s.size();
        if(n%2==1) n++;

       
        map<char,int>mymap;
        for(int i=0;i<s.size();i++)
        {
             mymap[s[i]]++;
             if(mymap[s[i]]>n/2)
             {
                 return "";
             }
        }

       
        string str="";
        char ch='-';
        while(str.size()!=s.size())
        {
           int x=0;
            for(auto it=mymap.rbegin();it!=mymap.rend();it++)
            {
               if(it->second>0)
               {
                   char cc=it->first;
                   cout<<cc<<endl;
                   ch=it->first;
                   str=str+it->first;
                   mymap[it->first]--;
                   x++;
                   
               }
               
            }

           
           cout<<"ii";
           
        }


     

        return str;



    }

// driver code
int main()
{
    cout<<"start: ";
   cout<< reorganizeString("vovlvbadhdv") ;
	
	return 0;
}
