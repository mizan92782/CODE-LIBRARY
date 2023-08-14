
/*
  *Static variables in a Function: When a variable
  * is declared as static, space for it gets allocated for 
  * the lifetime of the program. Even if the function is called multiple 
  * times, space for the static variable is allocated only once and the value 
  * of the variable in the previous call gets carried through the next function call.
  *  This is useful for implementing coroutines in C/C++ or any other
  * application where the previous state of function needs to be stored. 
  * 
  * 
  * 
  * https://www.geeksforgeeks.org/static-keyword-cpp/
  * 
  * 
  * 
  * static value assing hole,programmer jaikahnai jak,static value
  * unchanged thaeke,even programm recursive kore
  * picone galeo stataic value change hoi na,,,bcs its static
  
  */

#include <iostream>
#include <string>
using namespace std;

void demo()
{
	// static variable
	static int count = 0;
	cout << count << " ";

	// value is updated and
	// will be carried to next
	// function calls
	count++;
}

int main()
{
	for (int i = 0; i < 5; i++)
		demo();
	return 0;
}
