#include <iostream>
using namespace std;

// Simple recursive maximum finder
int maximum_simple(int v[], int n)
{
    if (n == 1)
    {
        return v[0];
    }
    int max = maximum_simple(v, n - 1);
    if (v[n - 1] > max)
    {
        max = v[n - 1];
    }
    return max;
}

// Divide and conquer recursive maximum finder
int maximum_divide_conquer(int v[], int low, int high)
{
    int maxinf, maxsup, middle, max;
    if (low == high)
    {
        return v[low];
    }
    middle = (low + high) / 2;
    maxinf = maximum_divide_conquer(v, low, middle);
    maxsup = maximum_divide_conquer(v, middle + 1, high);
    if (maxinf > maxsup)
    {
        max = maxinf;
    }
    else
    {
        max = maxsup;
    }
    return max;
}

int main()
{
    int v[100], i, n;
    char choice;
    
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
    
    cout << "Choose algorithm (s for simple recursive, d for divide and conquer): ";
    cin >> choice;
    
    if (choice == 'd')
        cout << "The max is: " << maximum_divide_conquer(v, 0, n - 1);
    else
        cout << "The max is: " << maximum_simple(v, n);
    
    return 0;
}
