#include <bits/stdc++.h>
using namespace std;

void greatest_prime_factorization(int n)
{
    if (n <= 1)
    {
        cout << "There is no prime factore of : " << n << endl;
        return;
    }



    int fact = 2;
    cout << "Prime factorization of  " << n << " : ";


   // ! we cant use here(n):bcz 0%n==0 ,so it will be infinite
    while (n>1)
    {
        if (n % fact==0)
        {
            n = n / fact;
        }
        else
        {
            fact++;
        }
    }

       cout<<fact<<endl;
}

int main()
{

    greatest_prime_factorization(24);
    greatest_prime_factorization(49);
}