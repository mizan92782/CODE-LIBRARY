#include<bits/stdc++.h>
using namespace std;






int findFlips(char str[], int n)
{

    // ! this approach is important
    char last = ' '; int res = 0;
  
    for (int i = 0; i < n; i++) {
  
        // If last character is not equal
        // to str[i] increase res
        if (last != str[i])
            res++;
        last = str[i];
    }
  
    // To return min flips
    return res / 2;
}
  

int main()
{

     /*
     ! this type of solution can be use in problems 
     !where we need to  find difffern part of string
     */


    char str[] = "00011110001110";
    int n = strlen(str);
  
    cout << findFlips(str, n);
  
    return 0;
}