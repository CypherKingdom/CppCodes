#include <iostream>
using namespace std;

double maximum(double x, double y, double z)
{
    double max = x;
    if (max < y)
    {
        max = y;
    }
    if (max < z)
    {
        max = z;
    }
    return max;
}

int main()
{
    double a, b, c;
    cout << "Enter 3 numbers: ";
    cin >> a >> b >> c;
    cout << "The max is: " << maximum(a, b, c);
    return 0;
}
