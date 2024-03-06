#include<bits/stdc++.h>
using namespace std;

int V=5;
vector<vector<int>>graph(V,vector<int>());
vector<int>disc(V,-1);
vector<int>low(V,-1);
vector<bool>visited(V,false);

void addEdge(int u,int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void BridgeDFs(int parent,int u) {
    static int currentTime = 0;
    visited[u]=true;
    disc[u]=low[u]=++currentTime;

    for(int v: graph[u]) {

        /*
          a-->b-->c-->a
          voidin cycle
          ata low increse korbe
          but bidirectionla hoyei at back edge hobe na
          jai path cut kore na keno disconnect hobe na
        */
        if(v == parent)
            continue;

        if(visited[v]==false) {
            BridgeDFs(u,v);
            low[u]=min(low[u],low[v]);
            

            //this line is very important:
            if(low[v]>disc[u]) {
                cout<<u<<" "<<v<<endl;
            }
        } else {
            low[u]=min(low[u],disc[v]);
        }
    }
}

void Bridge() {
    int parent = -1;
    for(int i=0;i<V;i++) {
        if(visited[i]==false) {
            BridgeDFs(parent,i);
        }
    }
}

int main() {
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    Bridge();
    return 0;
}
