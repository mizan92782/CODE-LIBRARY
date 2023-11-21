#include <bits/stdc++.h>
using namespace std;

// **********************  Raw code **************

void permutation_util(string &str, int index, int end)
{

    if (index == end)
    {
        cout << str << " ";
    }
    else
    {

        for (int i = index; i <= end; i++)
        {

            /*
             * swap a specific index with other index whose right of him
             * every specific index comes by recursive call
             * and return by backtraking
             * its bottom up approach
             */
            swap(str[index], str[i]);

            //  * recursive call until last index
            permutation_util(str, index + 1, end);

            // ** return past string by swapping again
            //** ex : ABC ->>ACB >ABC
            // *this  is brack

            swap(str[index], str[i]);
        }
    }
}
void permutation(string &str)
{
    int end = str.size() - 1;
    //  ** permutation util
    permutation_util(str, 0, end);
}

int main()
{

    //https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
    string str = "ABC";
    permutation(str);
}