/* 1. write a program that fills a file with characters introduced from keyboard until the user enters $ to terminate.
2. output the content the file */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream file;
    string filename, input;
    cout << "Enter the filename: ";
    cin >> filename;

    file.open(filename.c_str(), ios::out);
    if (!file)
    {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    cout << "Enter text (end with $): ";
    cin.ignore();
    getline(cin, input, '$');

    file << input;
    file.close();

    cout << "File written successfully!" << endl;

    ifstream inFile(filename.c_str());
    if (!inFile)
    {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    cout << "File content:" << endl;
    while (getline(inFile, input))
        cout << input << endl;

    inFile.close();
    return 0;
}