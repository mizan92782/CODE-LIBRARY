#include<bits/stdc++.h>
using namespace std;

bool check(string str)
{
    int n = str.length();
 
    // Return false if number is not divisible by 2.
    if ((str[n-1]-'0')%2 != 0)
       return false;
 
    // If we reach here, number is divisible by 2.
    // Now check for 3.
 
    // Compute sum of digits
    int digitSum = 0;
    for (int i=0; i<n; i++)
        digitSum += (str[i]-'0');
 
    // Check if sum of digits is divisible by 3
    return (digitSum % 3 == 0);
}
 
// Driver code
int main()
{
    string str = "1332";
    check(str)?  cout << "Yes" : cout << "No ";
    return 0;
}