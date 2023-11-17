#include<bits/stdc++.h>
using namespace std;

typedef long long ll;




int lcm(vector<int>vec)
{
     int lcm=vec[0];

     for(int i=1;i<vec.size();i++)
     {
        lcm=(lcm*vec[i])/__gcd(lcm,vec[i]);
     }


     return lcm;
}








int main()
{

//https://www.geeksforgeeks.org/lcm-of-given-array-elements/
std::vector<int> numbers = {2, 3, 4, 5};
    int LCM = lcm(numbers);
    std::cout << "LCM of " << numbers.size() << " numbers is " << LCM << std::endl;

}