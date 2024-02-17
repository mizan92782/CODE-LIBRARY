
void addedge(vector<vector<int>> & graph,int u,int v)
{
     graph[u].push_back(v);
     graph[v].push_back(u);
}

