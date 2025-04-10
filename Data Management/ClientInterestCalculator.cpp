/* consider 2 files:
client.txt:
    1   Jean	2	January		100
                    April		200
    2	Smith	3	March		500
                    May			100
                    April       50

Interest.txt:
    January		10
    February	15
    March		10
    April		5

Write a function that takes as input parameters: the number of a client, the names of 2 source files
and creates a destination file, containing the number, the name and the account of the client */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

void calculateClientInterest(int clientNumber, const string &clientFile, const string &interestFile, const string &outputFile)
{
    ifstream clientStream(clientFile);
    ifstream interestStream(interestFile);
    ofstream outputStream(outputFile);

    if (!clientStream || !interestStream)
    {
        cout << "Error opening input files!" << endl;
        return;
    }

    map<string, int> interestRates;
    string month;
    int rate;

    while (interestStream >> month >> rate)
        interestRates[month] = rate;

    string line;
    int number;
    string name;
    int account = 0;

    while (getline(clientStream, line))
    {
        istringstream iss(line);
        iss >> number >> name;

        if (number == clientNumber)
        {
            string month;
            int amount;

            while (iss >> month >> amount)
                account += amount * interestRates[month] / 100;

            outputStream << number << "\t" << name << "\t" << account << endl;
            break;
        }
    }

    clientStream.close();
    interestStream.close();
    outputStream.close();
}

int main()
{
    int clientNumber;
    string clientFile, interestFile, outputFile;

    cout << "Enter the client number: ";
    cin >> clientNumber;
    cout << "Enter the client file name: ";
    cin >> clientFile;
    cout << "Enter the interest file name: ";
    cin >> interestFile;
    cout << "Enter the output file name: ";
    cin >> outputFile;

    calculateClientInterest(clientNumber, clientFile, interestFile, outputFile);

    cout << "Client interest calculated successfully!" << endl;

    return 0;
}