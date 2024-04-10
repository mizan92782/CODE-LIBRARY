#include<bits/stdc++.h>
using namespace  std;

vector<vector<int>>graph;

int V=0;






// ! Check is connected grpah *******;

void dfs(int u,vector<bool>& visited)
{      
         visited[u]=true;

         for(int v: graph[u])
         {
             if(!visited[v])
             {
                dfs(v,visited);
             }
         }

}



bool isConnectedGraph()
{
    

     vector<bool>visited(V,false);

     int count=0;

     for(int i=0;i<V;i++)
     {   
         //single node
         if(graph[i].size()==0)
         {
            continue;
         }

         if(!visited[i])
         {
            cout<<i<<endl;
             count++;

              if(count>1)
              {
                return false;
              }
             dfs(i,visited);
         }
     }


     return true;
}








//! Count odd degree*******
int CountOddDegere()
{
     int count=0;
     for(int i=0;i<graph.size();i++)
     {
         if(graph[i].size()%2==1)
         {
            count++;
         }
     }



     return count;
     
}






//! Check Eulerian
void PrintEulerianPath()
{
     int odd_degree=CountOddDegere();
     cout<<odd_degree<<endl;

     //! 1. Check is it Eulerian
     // ** discconnect + odd_degree > 2;
     if(isConnectedGraph()==false || odd_degree>2) 
     {
         cout<< "This is not Eulerian path or circle\n";
         return ;
     }




     // ! 2.find the starting node for eulerian path or cycle
     int startnode=0;
     /*
       if its is cycle,any node can be startingnode
       if its path odd node can be starging node
     */


     for(int i=0;i<V;i++)
     {
        if(graph[i].size()%2==1)
        {
            startnode=i;
            break;
        }
     }



    stack<int>stk;
    vector<int>path;

    stk.push(startnode);

    
    /*
      0 --- 1-----2
      |           |
      ------------
    
    */

    while (!stk.empty())
    {
        int u=stk.top();

        if(!graph[u].empty())
        {
            int v=graph[u].back();
            stk.push(v);

            //! break edge among u-v
            
            graph[u].pop_back();
            graph[v].erase(find(graph[v].begin(),graph[v].end(),u));
        }else{

             //! ther is no edge :just bractrack
             stk.pop();
             
             path.push_back(u);
        }
    }



    


    if(odd_degree==0)
    {
        cout<<"Eulerian cycle :  \n ";
    }else{
        
        cout<<"Eulerian path : \n";
    }


    //! **** print path
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];

        
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    
    

}





int main()
{
     

    //https://www.geeksforgeeks.org/eulerian-path-and-circuit/

     /*
     graph.push_back({1,2,3}); // 0 connect with 1, 2
     graph.push_back({0, 2}); // 1 connect with 0, 2
     graph.push_back({0, 1}); // 0 connect with 1,2
     graph.push_back({0,4}); // 0 connect with 1,2
     graph.push_back({3}); // 0 connect with 1,2

     */

     graph.push_back({1,2});
     graph.push_back({0,2});
     graph.push_back({0,1});


     PrintEulerianPath();

     



    

    return 0;

}
