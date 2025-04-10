#include <iostream>
#include <iomanip>
using namespace std;

// Copy array using indices
void copyUsingIndices(double *q, double *p, int n)
{
    for (int i = 0; i < n; i++)
        *(q + i) = *(p + i);
}

// Copy array using pointer arithmetic
void copyUsingPointers(double *q, double *p, int n)
{
    double *t;
    for (t = p; t < p + n; t++)
    {
        *q = *t;
        q++;
    }
}

// Search for a value in array using indices
int *searchUsingIndices(int *v, int n, int val)
{
    for (int i = 0; i < n; i++)
        if (*(v + i) == val)
            return (v + i);
    return NULL;
}

// Search for a value in array using pointers
int *searchUsingPointers(int *v, int n, int val)
{
    int *p;
    for (p = v; p < v + n; p++)
        if (*p == val)
            return p;
    return NULL;
}

// Example of array copy
void demoArrayCopy()
{
    double *p, *q, *t;
    int n;
    do
    {
        cout << "Enter a strictly positive integer: ";
        cin >> n;
    } while (n <= 0);
    p = new double[n];
    q = new double[n];
    cout << "Enter the arrays: ";
    for (t = p; t < p + n; t++)
        cin >> *t;
    copyUsingPointers(q, p, n);
    cout << "The array copied using pointers: \n";
    for (t = q; t < q + n; ++t)
        cout << *t << "   ";
    cout << endl;

    delete[] q;
    q = new double[n];
    copyUsingIndices(q, p, n);
    cout << "The array copied using indices: \n";
    for (int i = 0; i < n; i++)
        cout << *(q + i) << "   ";

    delete[] p;
    delete[] q;
}

// Example of array search
void demoArraySearch()
{
    int *v, n, val, *q;
    do
    {
        cout << "\nEnter a positive integer n: ";
        cin >> n;
    } while (n < 0);
    v = new int[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> *(v + i);
    cout << "Enter the value to search: ";
    cin >> val;

    // Search using indices
    q = searchUsingIndices(v, n, val);
    if (q != NULL)
        cout << "Using indices: The value is found at address " << q << endl;
    else
        cout << "Using indices: The value is not found" << endl;

    // Search using pointers
    q = searchUsingPointers(v, n, val);
    if (q != NULL)
        cout << "Using pointers: The value is found at address " << q << endl;
    else
        cout << "Using pointers: The value is not found" << endl;

    delete[] v;
}

int main()
{
    cout << "=== Array Copy Demo ===" << endl;
    demoArrayCopy();

    cout << "\n=== Array Search Demo ===" << endl;
    demoArraySearch();

    return 0;
}
