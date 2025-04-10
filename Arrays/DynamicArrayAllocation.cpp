#include <iostream>
#include <iomanip>
using namespace std;

// Calculate sum of 2D array
int sum(int **a, int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s = s + *(*(a + i) + j);
    return s;
}

// Demo: Array of pointers approach (Method 1)
void demo1DArrayOfPointers()
{
    const int n = 10;
    int *a[n], i, j, m;
    
    cout << "=== 2D Array Using Array of Pointers ===" << endl;
    do
    {
        cout << "Enter number of columns (positive integer): ";
        cin >> m;
    } while (m <= 0);
    
    // Allocate memory for each row
    for (i = 0; i < n; i++)
        a[i] = new int[m];
    
    // Input array elements
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> *(*(a + i) + j); // equivalent to a[i][j]
        }
    }
    
    // Display array
    cout << "The array contains: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(4) << *(*(a + i) + j);
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
}

// Demo: Pointer to array approach (Method 2)
void demo2DFixedColumnArray()
{
    const int m = 10; // Fixed number of columns
    int(*a)[m], i, j, n;
    
    cout << "\n=== 2D Array Using Pointer to Fixed-Size Array ===" << endl;
    do
    {
        cout << "Enter number of rows (positive integer): ";
        cin >> n;
    } while (n <= 0);
    
    // Allocate memory for the entire 2D array
    a = new int[n][m];
    
    // Input array elements
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> *(*(a + i) + j); // equivalent to a[i][j]
        }
    }
    
    // Display array
    cout << "The array contains: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(4) << *(*(a + i) + j);
        cout << endl;
    }
    
    // Free memory
    delete[] a;
}

// Demo: Double pointer approach (Method 3)
void demo2DDynamicArray()
{
    int **a, i, j, n, m;
    
    cout << "\n=== 2D Array Using Double Pointer ===" << endl;
    do
    {
        cout << "Enter number of rows (positive integer): ";
        cin >> n;
    } while (n <= 0);
    
    do
    {
        cout << "Enter number of columns (positive integer): ";
        cin >> m;
    } while (m <= 0);
    
    // Allocate memory for array of pointers
    a = new int *[n];
    
    // Allocate memory for each row
    for (i = 0; i < n; i++)
        a[i] = new int[m];
    
    // Input array elements
    cout << "Enter the array elements:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> *(*(a + i) + j); // equivalent to a[i][j]
        }
    }
    
    // Calculate and display sum
    cout << "The sum of all elements is: " << sum(a, n, m) << endl;
    
    // Free memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int main()
{
    int choice;
    do {
        cout << "\nDynamic Array Allocation Demo" << endl;
        cout << "1. Array of Pointers (Fixed rows)" << endl;
        cout << "2. Pointer to Array (Fixed columns)" << endl;
        cout << "3. Double Pointer (Fully dynamic)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: demo1DArrayOfPointers(); break;
            case 2: demo2DFixedColumnArray(); break;
            case 3: demo2DDynamicArray(); break;
            case 0: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}
