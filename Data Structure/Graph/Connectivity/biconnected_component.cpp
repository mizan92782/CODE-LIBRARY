#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1005; // Maximum number of vertices

int V; // Number of vertices
int low[MAX], disc[MAX];
bool visited[MAX];
vector<int> adj[MAX];
stack<pair<int, int>> st; // Stack to store edges

void findBiconnectedUtil(int u, int parent) {
    static int time = 0; // Time-stamp for visited nodes
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            st.push({u, v}); // Push edge to the stack
            findBiconnectedUtil(v, u);

            low[u] = min(low[u], low[v]);

            if ((parent == -1 && children > 1) || (parent != -1 && low[v] >= disc[u])) {
                // If u is an articulation point or if there is a back edge to the parent or ancestor of u
                while (st.top() != make_pair(u, v)) {
                    cout << st.top().first << " - " << st.top().second << " ";
                    st.pop();
                }
                cout << st.top().first << " - " << st.top().second << endl;
                st.pop();
            }
        } else if (v != parent && disc[v] < low[u]) {
            low[u] = disc[v];
            st.push({u, v}); // Push edge to the stack
        }
    }
}

void findBiconnected() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            findBiconnectedUtil(i, -1);
        }
    }
}

int main() {
    // Add the graph
    V = 5;
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(0);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(3);

    findBiconnected();

    return 0;
}
