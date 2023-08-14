#include <iostream>
using namespace std;


string Maria()
{
         int n;
	      cin>>n;
	      string str;
	      cin>>str;
	      for(int i=0;i<n/2;i++)
	      {
	          if(str[i]!= str[(n/2)+i])
	          {
	              return "NO\n";
	          }
	      }
	      
	      
	      return "YES\n";
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	     cout<<Maria(); 
	}
	return 0;
}
