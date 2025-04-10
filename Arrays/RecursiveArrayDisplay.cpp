#include <iostream>
using namespace std;

void outputarray(int v[], int n)
{
    if (n >= 1)
    {
        outputarray(v, n - 1);
        cout << v[n - 1] << "  ";
    }
}

int main()
{
    int v[100], i, n; // n: size
    do
    {
        cout << "Enter the size of the array: ";
        cin >> n;
    } while (n <= 0 || n > 100);
    
    for (i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << " of the array: ";
        cin >> v[i];
    }
    
    cout << "The array is: ";
    outputarray(v, n);
    return 0;
}
