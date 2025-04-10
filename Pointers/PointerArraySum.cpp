#include <iostream>
using namespace std;

// Calculate sum of values pointed to by array of pointers
float sum(float *p[], int n)
{
    int i;
    float s = 0;
    for (i = 0; i < n; i++)
        s = s + *p[i];
    return s;
}

// Example with static array of pointers
void demoStaticPointerArray()
{
    float *p[20];
    int n, i;
    do
    {
        cout << "Enter a strictly positive integer: ";
        cin >> n;
    } while (n < 0);
    for (i = 0; i < n; i++)
        p[i] = new float;
    cout << "Enter " << n << " float values: ";
    for (i = 0; i < n; i++)
        cin >> *p[i];
    cout << "The sum is: " << sum(p, n) << endl;
    for (i = 0; i < n; i++)
        delete p[i];
}

// Example with dynamically allocated array of pointers
void demoDynamicPointerArray()
{
    float **p;
    int n, i;
    do
    {
        cout << "Enter a strictly positive integer: ";
        cin >> n;
    } while (n < 0);
    p = new float *[n];
    for (i = 0; i < n; i++)
        p[i] = new float;
    cout << "Enter " << n << " float values: ";
    for (i = 0; i < n; i++)
        cin >> *p[i];
    cout << "The sum is: " << sum(p, n) << endl;
    for (i = 0; i < n; i++)
        delete p[i];
    delete[] p;
}

int main()
{
    cout << "=== Static Pointer Array Demo ===" << endl;
    demoStaticPointerArray();
    
    cout << "\n=== Dynamic Pointer Array Demo ===" << endl;
    demoDynamicPointerArray();
    
    return 0;
}
