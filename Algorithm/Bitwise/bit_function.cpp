#include <bits/stdc++.h>
using namespace std;



/////////// power of 2
long long power2(long long n)
{
    // this func can be use for any power(x,y);
    if (n == 0)
        return 1;

    if (n == 1)
        return 2; // here are base

    int x = n / 2;
    return power2(x) * power2(n - x);
}

///////----------xor  to n
int Xor_1_to_n(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 3)
        return 0;
    if (n % 4 == 2)
        return n + 1;

    return 1;
}

///////-------add to binary number
string addition_two_binary_number(string one, string two)
{
    string str = "";

    int i = one.size() - 1;
    int j = two.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
        {
            carry += one[i] - 48;
            i--;
        }

        if (j >= 0)
        {
            carry += two[j] - 48;
            j--;
        }

        str = (char)((carry % 2) + '0') + str;
        carry = carry >> 1;
    }

    return str;
}
