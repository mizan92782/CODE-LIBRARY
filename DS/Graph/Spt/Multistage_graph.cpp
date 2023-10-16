#include <iostream>
#include <climits>
using namespace std;

// Number of stages in the graph
#define N 8

// Function to find the shortest path in the multistage graph
void shortestPath(int graph[N][N]) {
    int cost[N]; // The array to store the minimum costs to reach the end
    int path[N]; // The array to store the path

    // Initialize the cost array with INT_MAX and path array with -1
    for (int i = 0; i < N; i++) {
        cost[i] = INT_MAX;
        path[i] = -1;
    }

    // The cost to reach the last stage is 0
    cost[N - 1] = 0;

    // Traverse the graph in reverse order
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            if (graph[i][j]) {
                if (cost[i] > graph[i][j] + cost[j]) {
                    // Update the cost and path

                    /*
                      socond last stage one node x cost =10
                      and x to to last node edge = 3 and last node cost=0;
                      so here we can set that,to reach last node from x node,
                      we need  3+0=3
                      but x cost is 10;
                      so update x cost = 3;

                      such,we get cost[0]=minimun cost to source to sink node;
                    */
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

    // Print the shortest path and cost
    cout << "The shortest path is: ";
    int stage = 0;
    cout << stage << " ";
    while (path[stage] != -1) {
        stage = path[stage];
        cout << stage << " ";
    }
    cout << endl;

    cout << "The cost of the shortest path is: " << cost[0] << endl;
}

// Driver code
int main() {
    // Define the graph as an adjacency matrix
    int graph[N][N] = {
        {0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 6, 7, 0, 0},
        {0, 0, 0, 0, 6, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Find the shortest path in the multistage graph
    shortestPath(graph);

    return 0;
}
