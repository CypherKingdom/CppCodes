#include <iostream>
using namespace std;

// Iterative factorial
int factorial_iterative(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * i;
    }
    return p;
}

// Recursive factorial
int factorial_recursive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial_recursive(n - 1) * n;
}

int main()
{
    int x;
    char choice;
    
    do
    {
        cout << "Enter a positive integer: ";
        cin >> x;
    } while (x < 0);
    
    cout << "Choose method (i for iterative, r for recursive): ";
    cin >> choice;
    
    if (choice == 'r')
        cout << "The factorial of " << x << " is: " << factorial_recursive(x);
    else
        cout << "The factorial of " << x << " is: " << factorial_iterative(x);
    
    return 0;
}
