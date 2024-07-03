#include<bits/stdc++.h>
using namespace std;


//   !  nlogn

void lexNumbers_sort(int n)
{
    vector<string> s;
 

     // convert to string
    for (int i = 1; i <= n; i++) {
        s.push_back(to_string(i));
    }
 

    // sort them
    sort(s.begin(), s.end());


    //! get lexicographically order
    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(stoi(s[i]));
 
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}














// ! DFS : o(N);

void DFS(int n,int current)
{
    


     if(current>n)
     {
        return ;
     }

    cout<<current<<" ";


// ! sub dfs call for every subtree 0-9 ************
  for(int i=0;i<=9;i++)
  {
    DFS(n,current*10+i);
  }




}




void LexNumberDFS(int n)
{
      //!  call dfs for 1 to 9
      for(int i=1;i<=9;i++)
      {
          DFS(n,i);
      }     

      cout<<"\n";  
}


int main()
{


      int N=20;

      lexNumbers_sort(N);
      cout<<endl;
      LexNumberDFS(N);


    return 0;
}
