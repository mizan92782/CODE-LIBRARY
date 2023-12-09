#include <bits/stdc++.h>
using namespace std;

// ! long(n*2^n);
void printPowerSet(string str)
{
    int setSize = pow(2, str.size());

    // ! run binary 0 to setsize-1
    for (int i = 0; i < setSize; i++)
    {

        for (int j = 0; j < setSize; j++)
        {
            // Check if jth bit in the counter is set
            // If set then print jth element from set

            // no value print for i=0,bcs its alwauys give 0

            if (i & (1 << j))
            {

                //gtaphical representaiton
                cout<<"i,j value ;  ("<<i<<" "<<j<<") :   ";
                cout << str[j]<<" ";

                // cout<<"--> "<<i<<" "<<j<<" "<<(1 << j)<<"  "<<(i & (1 << j))<<endl;
                // when j==0 and 1<<j its means 1,and we actuall print j index
            }


        }
        cout << endl;
    }
}







int main()
{

    //https://www.geeksforgeeks.org/power-set/

    string str = "abc";
    printPowerSet(str);

    return 0;
}