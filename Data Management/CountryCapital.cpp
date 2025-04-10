#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const char *findCapital(const char country[], int size, const char *countries[], const char *capitals[])
{
	for (int i = 0; i < size; i++)
		if (strcmp(country, countries[i]) == 0)
			return capitals[i];
	return nullptr;
}

int main()
{
	int size = 7;
	char country[30];
	const char *found;
	const char *countries[] = {"France", "Italy", "Canada", "US", "England", "India", "Japan"};
	const char *capitals[] = {"Paris", "Rome", "Ottawa", "Washington", "London", "New Delhi", "Tokyo"};
	cout << "Enter the name of the country you want to find: ";
	cin >> country;
	found = findCapital(country, size, countries, capitals);
	if (found != nullptr)
		cout << "The capital is: " << found << endl;
	else
		cout << "Country not found." << endl;
	return 0;
}