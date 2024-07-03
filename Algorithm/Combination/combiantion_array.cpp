#include<bits/stdc++.h>
using namespace std;



void make_combination_util(vector<vector<int>>& combinaiton,vector<int>& temp,int arr[],int left,int N ,int K)
{      

       // ** if k=0 or fill the K length (using k-1)
       if(K==0)
       {
         combinaiton.push_back(temp);
         return;
       }


       for(int  i=left;i<N;i++)
       {
            // * recursively adding elemtto list upto K leght
            temp.push_back(arr[i]);


            // ! i+1 means ,it check for every number, k-1 for K lenght
            make_combination_util(combinaiton,temp,arr,i+1,N,K-1);

            // !! most importat:by poping we make diffrent combination
            temp.pop_back();


       }
}




vector<vector<int>> make_combination(int arr[],int N,int K)
{
     vector<vector<int>>combination;
     vector<int>temp;

      // 0 for index 1
     make_combination_util(combination,temp,arr,0,N,K);

    return combination;
}







int main()
{
    
    int arr[] = {1, 2, 1, 3, 1};
    int N=sizeof(arr)/sizeof(arr[0]);
    int  K=3;



    vector<vector<int> > ans = make_combination(arr,N,K);


    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }


    double x=555535.3634524;
    cout<<endl;

    cout<<setprecision()<<x;

}