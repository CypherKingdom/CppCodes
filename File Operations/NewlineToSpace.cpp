/*Write a program that replaces the carriage return('\n') in a text file with space. If many carriage returns exist,
the first one should only be replaced */

#include <iostream>
#include <fstream>
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

    bool replaced = false;
    while (getline(file, line))
    {
        if (!replaced)
        {
            size_t pos = line.find('\n');
            if (pos != string::npos)
            {
                line.replace(pos, 1, " ");
                replaced = true;
            }
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename(tempFile.c_str(), filename.c_str());

    cout << "Carriage return replaced successfully!" << endl;

    return 0;
}