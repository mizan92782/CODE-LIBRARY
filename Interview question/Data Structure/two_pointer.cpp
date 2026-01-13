#include <bits/stdc++.h>
using namespace std;

//! ================== unique triple sum ==========
/*
 !https://neetcode.io/problems/three-integer-sum?list=neetcode150
  * approch : 0,0,2,2,-2  ,target =0

  1.sort first : -2,0,0,2,
  2.if [i]+[i-1] is same than ignore,bcz it must be need to two
     others value ,that already by its past one [i-1]
         -1 -1 0 1
         -> ( -1, 0,1)
         -> so we can see taht for index 1,-1 already be first value of triple pair of 0s next all elemnts
  2. using first pointer for one and two pointer for others
  3. check is equal to to target
  4.if find then remove all same middel and same last element
  *** basic rules: after count pair,remove first and middle and third same element
*/

int main()
{
