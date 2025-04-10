#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Student
{
    char f_name[30];
    char l_name[30];
    char address[30];
    float gpa;
    int age;
};

int main()
{
    Student s1, student[20];
    char firstname[20], lastname[20];
    cout << "Enter first name: ";
    cin >> s1.f_name;
    cout << "Enter last name: ";
    cin >> s1.l_name;
    cout << "Enter address: ";
    cin >> s1.address;
    cout << "Enter age: ";
    cin >> s1.age;
    cout << "Enter gpa: ";
    cin >> s1.gpa;
    if (s1.gpa < 3)
    {
        cout << "First Name" << setw(15) << "Last Name" << setw(8) << "Age" << setw(15) << "Address" << setw(8) << "GPA" << endl;
        cout << setw(10) << s1.f_name << setw(15) << s1.l_name << setw(8) << s1.age << setw(15) << s1.address << setw(8) << s1.gpa << endl;
    }
    cout << "Enter the data of 20 students:\n";
    for (int i = 0; i < 20; i++)
    {
        cout << "Enter first name: ";
        cin >> student[i].f_name;
        cout << "Enter last name: ";
        cin >> student[i].l_name;
        cout << "Enter address: ";
        cin >> student[i].address;
        cout << "Enter age: ";
        cin >> student[i].age;
        cout << "Enter gpa: ";
        cin >> student[i].gpa;
    }
    cout << "Enter the first and last name of the student to search: ";
    cin >> firstname >> lastname;
    int i = 0, pos = -1;
    while (i < 20 && pos == -1)
    {
        if (strcmp(firstname, student[i].f_name) == 0 && strcmp(lastname, student[i].l_name) == 0)
            pos = i;
        i++;
    }
    if (pos == -1)
        cout << "Student not found";
    else
    {
        cout << "first name" << setw(15) << "last name" << setw(8) << "Age" << setw(15) << "Address" << setw(8) << "GPA" << endl;
        cout << setw(10) << student[pos].f_name << setw(15) << student[pos].l_name << setw(8) << student[pos].age << setw(15) << student[pos].address << setw(8) << student[pos].gpa << endl;
    }
    float total = 0;
    for (int i = 0; i < 20; i++)
        total += student[i].gpa;
    cout << "the average gpa is: " << total / 20;
    return 0;
}