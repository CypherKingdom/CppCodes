#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int n;
    float result;
    do
    {
        cout << "Enter the number of candles: ";
        cin >> n;
    } while (n <= 0);
    result = n;
    for (int i = 1; i < n; i++)
        result += n / pow(3, i);
    cout << "The number of candles is: " << (int)result << endl;
    return 0;
}