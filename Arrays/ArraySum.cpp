#include <iostream>
using namespace std;

// Iterative sum
int sum_iterative(int v[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += v[i];
    }
    return s;
}

// Recursive sum
int sum_recursive(int v[], int size)
{
    if (size == 0)
    { 
        return 0;
    }
    return sum_recursive(v, size - 1) + v[size - 1];
}

int main()
{
    int v1[100], i, n;
    char choice;
    
    do
    {
        cout << "Enter the size of the array: ";
        cin >> n;
    } while (n <= 0 || n > 100);
    
    for (i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << " of the array: ";
        cin >> v1[i];
    }
    
    cout << "Choose method (i for iterative, r for recursive): ";
    cin >> choice;
    
    if (choice == 'r')
        cout << "The sum of the elements in the array is: " << sum_recursive(v1, n);
    else
        cout << "The sum of the elements in the array is: " << sum_iterative(v1, n);
    
    return 0;
}
