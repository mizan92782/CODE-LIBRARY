#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

int determinant(const Matrix& mat, int n) {


     cout<<"i : value  is :   "<<endl;

        for (int x = 0; x < mat.size(); ++x) {
           
            for (int y = 0; y< mat[x].size(); ++y) {
              
                    cout<<mat[x][y]<<",";
                  

              
            }

            cout<<endl;
           
        }

        cout<<endl;



    if (n == 1) {
        return mat[0][0];
    }

    int det = 0;
    int sign = 1;

    for (int i = 0; i < n; ++i) {
        // Get the cofactor matrix
        Matrix submat(n - 1, vector<int>(n - 1, 0));

       
    

        for (int j = 1; j < n; ++j) {
            int col = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    submat[j - 1][col] = mat[j][k];
                    col++;
                }

              
            }
           
        }


      
          
                cout<<i<<"  -- non final determinat :  "<<det<<endl<<endl;


        // Recursive call for the cofactor expansion
        det += sign * mat[0][i] * determinant(submat, n - 1);
        sign = -sign;


        cout<<i<<"  -- finala determinat :  "<<det<<endl<<endl;
    }

    return det;
}

int countSpanningTrees(const Matrix& adjacency_matrix) {
    int num_nodes = adjacency_matrix.size();

    // Degree matrix
    Matrix degree_matrix(num_nodes, vector<int>(num_nodes, 0));
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            degree_matrix[i][i] += adjacency_matrix[i][j];
        }
    }

    // Laplacian matrix
    Matrix laplacian_matrix(num_nodes, vector<int>(num_nodes, 0));
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            laplacian_matrix[i][j] = degree_matrix[i][j] - adjacency_matrix[i][j];
        }
    }

    // Create a Laplacian matrix for the spanning tree calculation by removing the last row and column
    Matrix laplacian_tree_matrix(num_nodes - 1, vector<int>(num_nodes - 1, 0));
    for (int i = 1; i < num_nodes; ++i) {
        for (int j = 1; j < num_nodes; ++j) {
            laplacian_tree_matrix[i - 1][j - 1] = laplacian_matrix[i][j];
        }
    }

    // Calculate the determinant of the Laplacian matrix for the spanning tree
    int determinant_value = determinant(laplacian_tree_matrix, num_nodes - 1);

    // The number of spanning trees is the rounded absolute value of the determinant
    int num_spanning_trees = abs(determinant_value);

    return num_spanning_trees;
}

int main() {
    // Example usage:
    Matrix adjacency_matrix = {{0, 1, 1, 1},
                               {1, 0, 0, 1},
                               {1, 0, 0, 1},
                               {1, 1, 1, 0}};

    // Find the number of spanning trees
    int num_spanning_trees = countSpanningTrees(adjacency_matrix);

    // Display the result
    cout << "Number of spanning trees: " << num_spanning_trees << endl;

    return 0;
}
