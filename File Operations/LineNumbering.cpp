/* write a program that adds the number of the line before each line in a file. */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream file;
    string filename, line;
    cout << "Enter the filename: ";
    cin >> filename;

    file.open(filename.c_str(), ios::in);
    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string tempFile = "temp.txt";
    ofstream temp(tempFile.c_str());

    int lineNumber = 1;
    while (getline(file, line))
    {
        temp << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename(tempFile.c_str(), filename.c_str());

    cout << "Line numbers added successfully!" << endl;

    return 0;
}