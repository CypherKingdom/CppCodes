#include <iostream>
using namespace std;

void decbin(int n)
{
    if (n <= 1)
    {
        cout << n;
    }
    else
    {
        decbin(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int x;
    cout << "Enter a decimal number: ";
    cin >> x;
    cout << "Binary representation: ";
    decbin(x);
    return 0;
}
