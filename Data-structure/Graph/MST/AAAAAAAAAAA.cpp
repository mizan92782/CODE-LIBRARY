#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

void get_Co_factor(Matrix matrix, Matrix &cofactore, int row, int clm, int n)
{
    int Colum = 0;
    int Row = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            // unconsider row and clm all element,
            if (i != row && j != clm)
            {
                // row
                cofactore[Row][Colum] = matrix[i][j];

                Colum++;

                //  ! incresing colum and row of cofactor;
                if (Colum == n - 1)
                {
                    Colum = 0;
                    Row++;
                }
            }
        }

        cout << endl;
    }
}

int Determinant(Matrix matrix, int n)
{
    if (n == 1)
    {
        return matrix[0][0];
    }

    // store total determinant for first row
    int determinant = 0;

    // confirm sign for co-factoe
    int sign = 1;

    // first row
    for (int clm = 0; clm < n; clm++)
    {

        // ! ***** find co-factor for  row's node respectively
        // ** co factor store in here

        Matrix cofactore(n - 1, vector<int>(n - 1, 0));

        //* here,thired argument always 0,bcz we work always with first row

        get_Co_factor(matrix, cofactore, 0, clm, n);

        cout << clm << " -- co factor " << endl;
        for (int j = 0; j < cofactore.size(); ++j)
        {

            for (int k = 0; k < cofactore[j].size(); ++k)
            {

                cout << cofactore[j][k] << ",";
            }

            cout << endl;
        }

        cout << endl
             << endl
             << endl;

        // ** now count and add determinat value for every everu clm of first row
        // !! one important things here: we recursivel call the next co-factor of recent matrix,such way,we can find smallest (1) matrix ,
        // ! onother important : in recursive Determinat() ,we give cofactor matrix as matrix to find the cofactor of current cofactor matrix

        determinant += sign * matrix[0][clm] * Determinant(cofactore, n - 1);
        // its return determinat for specific clm

        // after clm change sign will change;
        sign = -sign;
    }

    return determinant;
}

void CountSpanningTree(Matrix adjacent_matrix)
{
    // number of node
    int num_nodes = adjacent_matrix.size();

    // ! 1.we have adjacent matrix
    cout << "Adjacet Matrix :   \n";
    for (int row = 0; row < num_nodes; row++)
    {
        for (int clm = 0; clm < num_nodes; clm++)
        {
            cout << adjacent_matrix[row][clm] << ",";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    // ! 2. construct degree matrix  in below

    Matrix degree_matrix(num_nodes, vector<int>(num_nodes, 0));

    for (int row = 0; row < num_nodes; row++)
    {
        for (int clm = 0; clm < num_nodes; clm++)
        {
            degree_matrix[row][row] += adjacent_matrix[row][clm];
        }
    }

    cout << "Degree matrix :  " << endl;
    for (int row = 0; row < num_nodes; row++)
    {
        for (int clm = 0; clm < num_nodes; clm++)
        {

            cout << degree_matrix[row][clm] << ",";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    // ! 3. degree matrix -adjacent matrix;

    Matrix laplacian_matrix(num_nodes, vector<int>(num_nodes, 0));

    cout << "laplacinan  Matrix :  \n";

    for (int row = 0; row < num_nodes; row++)
    {
        for (int clm = 0; clm < num_nodes; clm++)
        {
            laplacian_matrix[row][clm] = degree_matrix[row][clm] - adjacent_matrix[row][clm];
            cout << laplacian_matrix[row][clm] << ",";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    // ! 4.  // Create a Laplacian matrix for the spanning tree calculation by removing the last row and column (co factor of laplacina_matirx)
    Matrix laplacian_tree_matrix(num_nodes - 1, vector<int>(num_nodes - 1, 0));

    //  ***remove first row
    for (int i = 1; i < num_nodes; i++)
    {
        //* remove fist colum
        for (int j = 1; j < num_nodes; j++)
        {
            laplacian_tree_matrix[i - 1][j - 1] = laplacian_matrix[i][j];
        }
    }

    cout << "laplacian matrix tree :   \n";

    for (int i = 0; i < num_nodes - 1; i++)
    {

        for (int j = 0; j < num_nodes - 1; j++)
        {
            cout << laplacian_tree_matrix[i][j] << ",";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    /*
      ! ************************* *********  **********
      ! 5. Most important part : find deteminant value for laplacina_tree_matrix;

    */

    int deteminant_value = Determinant(laplacian_tree_matrix, num_nodes - 1);

    //! final result :
    cout << "Number of spanning tree : " << abs(deteminant_value) << endl;
}

int main()
{
    Matrix adjacent_matrix = {{0, 1, 1, 1},
                              {1, 0, 0, 1},
                              {1, 0, 0, 1},
                              {1, 1, 1, 0}};

    CountSpanningTree(adjacent_matrix);

    return 0;
}