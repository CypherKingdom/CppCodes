#include <iostream>
using namespace std;

// Reverse array - print only
void reverse_print(int tab[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << tab[i] << " ";
    }
}

// Reverse array - modify in place
void reverse_in_place(int v[], int n)
{
    int c;
    for (int i = 0; i < n / 2; i++)
    {
        c = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = c;
    }
}

// Recursive array reversal - print only
void reverse_recursive(int v[], int n)
{
    if (n >= 1)
    {
        cout << v[n - 1] << " ";
        reverse_recursive(v, n - 1);
    }
}

int main()
{
    int v[100], n;
    int choice;
    
    do
    {
        cout << "Enter the size of the array: ";
        cin >> n;
    } while (n <= 0 || n > 100);
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " of the array: ";
        cin >> v[i];
    }
    
    cout << "Choose reversal method:\n"
         << "1. Print in reverse order\n"
         << "2. Reverse array in place\n"
         << "3. Recursive reversal\n"
         << "Enter choice (1-3): ";
    cin >> choice;
    
    cout << "The reversed array is: ";
    
    switch (choice) {
        case 1:
            reverse_print(v, n);
            break;
        case 2:
            reverse_in_place(v, n);
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            break;
        case 3:
            reverse_recursive(v, n);
            break;
        default:
            cout << "Invalid choice. Using simple print reversal.\n";
            reverse_print(v, n);
    }
    
    return 0;
}
