#include <iostream>
#include <iomanip>
using namespace std;

// Point structure and related functions
struct point
{
    int x;
    int y;
};

point sum(point A, point *B)
{
    point C;
    C.x = A.x + (*B).x;
    C.y = A.y + B->y;
    return C;
}

void demoPointStructure()
{
    point A, *B, C;
    cout << "Enter first point (x y): ";
    cin >> A.x >> A.y;

    B = new point;
    cout << "Enter the second point (x y): ";
    cin >> (*B).x >> (*B).y;
    C = sum(A, B);
    cout << "Sum of points: " << C.x << setw(4) << C.y << endl;
    
    delete B;
}

// Student structure and related functions
struct student
{
    char name[20];
    double grade;
    int ID;
};

void demoStudentStructure()
{
    student *V;
    int n;
    do
    {
        cout << "Enter number of students: ";
        cin >> n;
    } while (n <= 0);
    
    V = new student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << (i+1) << ":" << endl;
        cout << "Enter name: ";
        cin >> (V + i)->name; // cin>>V[i].name;
        cout << "Enter ID: ";
        cin >> (V + i)->ID;
        cout << "Enter grade: ";
        cin >> (V + i)->grade; // cin>>V[i].grade;
    }
    
    // Display student information
    cout << "\nStudent Information:" << endl;
    cout << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Grade" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(20) << (V + i)->name 
             << setw(10) << (V + i)->ID
             << setw(10) << (V + i)->grade << endl;
    }
    
    delete[] V;
}

int main()
{
    int choice;
    
    do {
        cout << "\nPointer to Structure Demo" << endl;
        cout << "1. Point Structure" << endl;
        cout << "2. Student Structure" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: demoPointStructure(); break;
            case 2: demoStudentStructure(); break;
            case 0: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
