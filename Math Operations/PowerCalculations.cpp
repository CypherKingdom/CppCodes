#include <iostream>
using namespace std;

// Iterative power calculation
int power_iterative(int x, int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p *= x;
    }
    return p;
}

// Simple recursive power calculation
int power_recursive(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power_recursive(x, n - 1) * x;
}

// Optimized recursive power calculation
double power_optimized(double x, int n)
{
    double r;
    if (n == 0)
    {
        return 1;
    }
    r = power_optimized(x, n / 2);
    if (n % 2 == 0)
    {
        return r * r;
    }
    else
    {
        return r * r * x; // x^n = x^n/2 * x^n/2 (if n even), x^n = x^n/2 * x^n/2 * x (if n odd)
    }
}

int main()
{
    int x, n;
    int choice;
    
    cout << "Enter an integer base: ";
    cin >> x;
    
    do
    {
        cout << "Enter a positive integer exponent: ";
        cin >> n;
    } while (n < 0);
    
    cout << "Choose calculation method:\n"
         << "1. Iterative\n"
         << "2. Simple recursive\n"
         << "3. Optimized recursive\n"
         << "Enter choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << x << "^" << n << " = " << power_iterative(x, n);
            break;
        case 2:
            cout << x << "^" << n << " = " << power_recursive(x, n);
            break;
        case 3:
            cout << x << "^" << n << " = " << power_optimized(x, n);
            break;
        default:
            cout << "Invalid choice. Using iterative method.\n";
            cout << x << "^" << n << " = " << power_iterative(x, n);
    }
    
    return 0;
}
