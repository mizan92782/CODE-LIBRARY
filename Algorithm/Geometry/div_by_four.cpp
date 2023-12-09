#include<bits/stdc++.h>
using namespace std;


bool dib_by_four(string str)
{
    int n = str.length();
 
    // Empty string
    if (n == 0)
        return false;
 
    // If there is single digit
    if (n == 1)
        return ((str[0] - '0') % 4 == 0);
 
    // If number formed by last two digits is
    // divisible by 4.
    int last = str[n - 1] - '0';
    int second_last = str[n - 2] - '0';
    return ((second_last * 10 + last) % 4 == 0);
}




int main()
{


    return 0;
}