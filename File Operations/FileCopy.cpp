// Program to copy contents from a source file to a destination file

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream srcFile;
    ofstream destFile;
    string srcFilename, destFilename, line;

    cout << "Enter the source filename: ";
    cin >> srcFilename;
    cout << "Enter the destination filename: ";
    cin >> destFilename;

    srcFile.open(srcFilename.c_str(), ios::in);
    if (!srcFile)
    {
        cout << "Source file not found!" << endl;
        return 1;
    }

    destFile.open(destFilename.c_str(), ios::out);
    if (!destFile)
    {
        cout << "Error creating destination file!" << endl;
        return 1;
    }

    while (getline(srcFile, line))
        destFile << line << endl;

    srcFile.close();
    destFile.close();

    cout << "File copied successfully!" << endl;

    return 0;
}