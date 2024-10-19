// A C++ program to demonstrate STL stable_sort()
// to sort intervals according to start time.
#include <bits/stdc++.h>
using namespace std;

// An interval has start time and end time
struct Interval {
	int start, end;
};

// Compares two intervals according to starting
// times.
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

int main()
{
	// Given intervals are sorted according to end time
	Interval arr[]
		= { { 1, 3 }, { 2, 4 }, { 1, 7 }, { 2, 19 } ,{ 1, 19 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	// sort the intervals in increasing order of
	// start time such that the start time intervals
	// appear in same order as in input.
	stable_sort(arr, arr + n, compareInterval);

	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i].start << ", " << arr[i].end
			<< "] ";

	return 0;
}
