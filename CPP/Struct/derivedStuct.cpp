// C++ Program to demonstrate
// Inheritance with structures.
#include <iostream>

using namespace std;

struct Base {
public:
	int x;
};

// is equivalent to
// struct Derived : public Base {}

struct Derived : Base {
public:
	int y;
};

int main()
{
	Derived d;

	// Works fine because inheritance
	// is public.

    //! parent memeber varible
	d.x = 20;


    //! chield variable
    d.y=55;


	cout << d.x<<endl<<d.y<<endl;

    
	cin.get();
	return 0;
}
