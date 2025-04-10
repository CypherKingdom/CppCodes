#include <iostream>
using namespace std;

// Iterative linear search
int linear_search(int v[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Recursive linear search
int recursive_linear_search(int v[], int size, int x)
{
    int index;
    if (v[size - 1] == x)
    {
        index = size - 1;
    }
    else if (size == 1)
    {
        if (v[0] == x)
        {
            index = 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        index = recursive_linear_search(v, size - 1, x);
    }
    return index;
}

// Recursive binary search (requires sorted array)
int binary_search(int v[], int low, int high, int x)
{
    int mid;
    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    if (x == v[mid])
    {
        return mid;
    }
    if (x < v[mid])
    {
        return binary_search(v, low, mid - 1, x);
    }
    return binary_search(v, mid + 1, high, x);
}

int main()
{
    int v[100], i, n, x, index;
    int choice;
    
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
    
    cout << "Enter the element to search: ";
    cin >> x;
    
    cout << "Choose search algorithm:\n"
         << "1. Iterative linear search\n"
         << "2. Recursive linear search\n"
         << "3. Binary search (requires sorted array)\n"
         << "Enter choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            index = linear_search(v, n, x);
            break;
        case 2:
            index = recursive_linear_search(v, n, x);
            break;
        case 3:
            index = binary_search(v, 0, n - 1, x);
            break;
        default:
            cout << "Invalid choice. Using iterative linear search.\n";
            index = linear_search(v, n, x);
    }
    
    if (index == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index: " << index;
    }
    
    return 0;
}
