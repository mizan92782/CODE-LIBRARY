#include <bits/stdc++.h>
using namespace std;

// ***** Recursion

bool isSubsetSum(int set[], int n, int sum)
{
    if (sum < 0)
    {
        return false;
    }

    if (sum == 0)
    {
        return true;
    }

    // if last elment is greater than sum;

    if (set[n - 1] > sum)
    {
        return isSubsetSum(set, n - 1, sum);
    }

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}





//********* Memorization

void mem_tab()
{
   //!  https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
}








// Driver code
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}