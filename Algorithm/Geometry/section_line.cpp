#include <bits/stdc++.h>
using namespace std;

void section_line(double x1, double y1, double x2, double y2, int m, int n)
{
    double x = (m * x2 + n * x1) / (m + n);
    double y = (m * y2 + n * y1) / (m + n);

    cout << "( " << x << "," << y << ")"
         << "\n";
}




int main()
{

    double x1 = 2, x2 = 4, y1 = 4,
           y2 = 6, m = 2, n = 3;
    section_line(x1, x2, y1, y2, m, n);
}