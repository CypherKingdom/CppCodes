/* Creates a binary file contaning 100 empty records */
#include <fstream>
#include <iostream>

using namespace std;

struct Record
{
    char data[100];
};

int main()
{
    fstream file("binaryfile.dat", ios::out | ios::binary);
    if (!file)
    {
        cout << "Error creating file!" << endl;
        return 1;
    }

    Record record;
    memset(&record, 0, sizeof(record));

    for (int i = 0; i < 100; ++i)
        file.write(reinterpret_cast<char *>(&record), sizeof(record));

    file.close();
    cout << "Binary file created successfully!" << endl;

    return 0;
}