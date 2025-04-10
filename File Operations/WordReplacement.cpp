/* write a program that replaces a word in a text file with another word entered by the user */

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    fstream file;
    string filename, word, newWord, line;
    cout << "Enter the filename: ";
    cin >> filename;
    cout << "Enter the word to be replaced: ";
    cin >> word;
    cout << "Enter the new word: ";
    cin >> newWord;

    file.open(filename.c_str(), ios::in);
    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string tempFile = "temp.txt";
    ofstream temp(tempFile.c_str());

    while (getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos)
        {
            line.replace(pos, word.length(), newWord);
            pos += newWord.length();
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename(tempFile.c_str(), filename.c_str());

    cout << "Word replaced successfully!" << endl;

    return 0;
}