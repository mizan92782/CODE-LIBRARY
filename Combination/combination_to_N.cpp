#include<bits/stdc++.h>
using namespace std;



void make_combination_util(vector<vector<int>>& combinaiton,vector<int>& temp,int left,int N ,int K)
{      

       // ** if k=0 or fill the K length (using k-1)
       if(K==0)
       {
         combinaiton.push_back(temp);
       }


       for(int  i=left;i<=N;i++)
       {
            // * recursively adding elemtto list upto K leght
            temp.push_back(i);


            // ! i+1 means ,it check for every number, k-1 for K lenght
            make_combination_util(combinaiton,temp,i+1,N,K-1);

            // !! most importat:by poping we make diffrent combination
            temp.pop_back();


       }
}




vector<vector<int>> make_combination(int N,int K)
{
     vector<vector<int>>combination;
     vector<int>temp;

     make_combination_util(combination,temp,1,N,K);

    return combination;
}







int main()
{
    
    int  N=5;
    int  K=3;



    vector<vector<int> > ans = make_combination(N,K);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }

}