/* Write a program that inputs from the user the name of 3 files, the first one containing
integers, put the multiples of 3 in the second file and the multiples of 4 in the third file
output on the screen the number of mutliple of 3 and the number of multiple of 4 */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    string inputFile, multiplesOf3File, multiplesOf4File;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "Enter the name of the file for multiples of 3: ";
    cin >> multiplesOf3File;
    cout << "Enter the name of the file for multiples of 4: ";
    cin >> multiplesOf4File;

    ifstream input(inputFile.c_str());
    if (!input)
    {
        cout << "Input file not found!" << endl;
        return 1;
    }

    ofstream multiplesOf3(multiplesOf3File.c_str());
    ofstream multiplesOf4(multiplesOf4File.c_str());

    int number, countMultiplesOf3 = 0, countMultiplesOf4 = 0;
    while (input >> number)
    {
        if (number % 3 == 0)
        {
            multiplesOf3 << number << endl;
            countMultiplesOf3++;
        }
        if (number % 4 == 0)
        {
            multiplesOf4 << number << endl;
            countMultiplesOf4++;
        }
    }

    input.close();
    multiplesOf3.close();
    multiplesOf4.close();

    cout << "Number of multiples of 3: " << countMultiplesOf3 << endl;
    cout << "Number of multiples of 4: " << countMultiplesOf4 << endl;

    return 0;
}