#include <bits/stdc++.h>
using namespace std;

void addEdge(int par, int chi, vector<vector<int>> &chield, int arr[])
{
    chield[par].push_back(chi);
    arr[chi] = par;
}

void print_parentNode(int arr[], int N)
{

    cout << " parent node of nodes : \n";

    for (int i = 1; i < N; i++)
    {
        if (arr[i] == -1)
        {
            cout << 1 << " -> "
                 << "no parent node" << endl;
        }
        else
        {

            cout << i << " -> " << arr[i] << endl;
        }
    }
}

// find specific parent
void find_parent(int node, int arr[], int N)
{
    if (arr[node] == -1)
    {
        cout << "No parent exist\n";
    }
    else
    {
        cout << node << " parent is " << arr[node] << endl;
    }
}

// print tree chield

void print_chield(vector<vector<int>> &chield)
{
    cout << " Node chields: \n";
    for (int i = 1; i < chield.size(); i++)
    {
        cout << i << " nodes chield: ";
        for (int j = 0; j < chield[i].size(); j++)
        {
            cout << chield[i][j] << " ";
        }

        cout << endl;
    }
}




// specific node chield;
void find_chield(int node, vector<vector<int>> &chield)
{
    if (chield[node].size() == 0)
    {
        cout << node << " -> this node havent any chield\n";
    }
    else
    {
        cout<<node<<" nodes chields-> ";
        for (int j = 0; j < chield[node].size(); j++)
        {
            cout << chield[node][j] << " ";
        }
        cout<<endl;
    }
}




//print leaf node:

void leaf_node(vector<vector<int>>& chield)
{
    cout<<"leaf node: \n";
    for(int i=1;i<chield.size();i++)
    {
        if(chield[i].size()==0)
        {
            cout<<i<<" ";
        }
    }
}



//traverse the tree
void Traverse_tree(vector<vector<int>>& chield)
{


    cout<<"Traversing tree ( BFS):\n ";
    queue<int>que;
    que.push(1);

    cout<<1<<endl;

    while(!que.empty())
    {
        int x;
        x=que.front();
       
        que.pop();

         if(chield[x].size()==0)
         {
            continue;
         }
        for(int i=0;i<chield[x].size();i++)
        {
            cout<<chield[x][i]<<" ";
            que.push(chield[x][i]);
        }
        cout<<endl;

         

    }
}

int main()
{
    int N = 7;
    // for storing child
    vector<vector<int>> chield(N + 1, vector<int>());
    // for stroring tree
    int arr[N + 1];

    fill(arr, arr + N, -1);

    addEdge(1, 2, chield, arr);
    addEdge(1, 3, chield, arr);
    addEdge(1, 4, chield, arr);
    addEdge(2, 5, chield, arr);
    addEdge(2, 6, chield, arr);
    addEdge(4, 7, chield, arr);

    print_parentNode(arr, N + 1);
     cout<<endl<<endl;


    find_parent(3, arr, N + 1);
    find_parent(6, arr, N + 1);
    find_parent(7, arr, N + 1);

     cout<<endl<<endl;
    print_chield(chield);
    cout<<endl<<endl;

    find_chield(1,chield);
    find_chield(2,chield);
    find_chield(7,chield);
       cout<<endl<<endl;
       leaf_node(chield);

    cout<<endl<<endl;
    Traverse_tree(chield);
}