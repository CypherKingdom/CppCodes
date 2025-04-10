#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct account
{
	int accountNumber;
	char type[5];
	double balance;
};

struct client
{
	int id, age;
	char firstName[31], lastName[31];
	account *a;
};

void InputClients(client c[], int size, int NbAccounts[])
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the first name of client " << i + 1 << " (max 30 characters) : ";
		cin >> c[i].firstName;
		cout << "Enter the last name of client " << i + 1 << " (max 30 characters) : ";
		cin >> c[i].lastName;
		cout << "Enter the id of client " << i + 1 << " : ";
		cin >> c[i].id;
		cout << "Enter the age of client " << i + 1 << " : ";
		cin >> c[i].age;
		cout << "How many accounts does this client have? : ";
		cin >> NbAccounts[i];
		c[i].a = new account[NbAccounts[i]];
		for (int j = 0; j < NbAccounts[i]; j++)
		{
			cout << "Enter the account number of account " << j + 1 << " of " << c[i].firstName << " : ";
			cin >> c[i].a[j].accountNumber;
			cout << "Enter the type of the account " << j + 1 << " : ";
			cin >> c[i].a[j].type;
			cout << "Enter the balance of account " << j + 1 << " : ";
			cin >> c[i].a[j].balance;
		}
	}
}

double getBalance(client c[], int size, int NbAccounts[], char fname[], char lname[])
{
	double totalBalance = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(c[i].firstName, fname) == 0 && strcmp(c[i].lastName, lname) == 0)
		{
			for (int j = 0; j < NbAccounts[i]; j++)
			{
				cout << "The balance of account " << j + 1 << " of " << fname << " is : " << c[i].a[j].balance << endl;
				totalBalance += c[i].a[j].balance;
			}
		}
	}
	return totalBalance;
}

client HighestBalance(client c[], int size, int NbAccounts[])
{
	double *balances = new double[size];
	double highestBalance;
	int pos;
	for (int i = 0; i < size; i++)
	{
		balances[i] = 0;
		for (int j = 0; j < NbAccounts[i]; j++)
			balances[i] += c[i].a[j].balance;
	}
	highestBalance = balances[0];
	pos = 0;
	for (int i = 0; i < size; i++)
	{
		if (balances[i] > highestBalance)
		{
			highestBalance = balances[i];
			pos = i;
		}
	}
	delete[] balances;
	return c[pos];
}

client AddClient(client c[], int &size, int NbAccounts[])
{
	client *newClientArray = new client[size + 1];
	int numOfAcc;
	for (int i = 0; i < size; i++)
		newClientArray[i] = c[i];
	size++;
	cout << "Enter the first name of the new client (max 30 characters): ";
	cin >> newClientArray[size - 1].firstName;
	cout << "Enter the last name of the new client (max 30 characters): ";
	cin >> newClientArray[size - 1].lastName;
	cout << "Enter the id of the new client: ";
	cin >> newClientArray[size - 1].id;
	cout << "Enter the age of the new client: ";
	cin >> newClientArray[size - 1].age;
	cout << "How many accounts does the new client have? : ";
	cin >> numOfAcc;
	newClientArray[size - 1].a = new account[numOfAcc];
	for (int j = 0; j < numOfAcc; j++)
	{
		cout << "Enter the account number of account " << j + 1 << " of the new client: ";
		cin >> newClientArray[size - 1].a[j].accountNumber;
		cout << "Enter the type of the account " << j + 1 << " of the new client : ";
		cin >> newClientArray[size - 1].a[j].type;
		cout << "Enter the balance of account " << j + 1 << " of the new client : ";
		cin >> newClientArray[size - 1].a[j].balance;
	}
	delete[] c;
	return *newClientArray;
}

int main()
{
	int size;
	char fName[31], lName[31];
	double balanceOfClient;
	client highestBalanceClient;
	do
	{
		cout << "How many clients would you like to input? : ";
		cin >> size;
	} while (size <= 0);
	client *c = new client[size];
	int *NumberOfAccounts = new int[size];
	InputClients(c, size, NumberOfAccounts);
	cout << "Enter the first name of the client whom you want to see the balance: ";
	cin >> fName;
	cout << "Enter the last name of the client whom you want to see the balance: ";
	cin >> lName;
	balanceOfClient = getBalance(c, size, NumberOfAccounts, fName, lName);
	cout << "The total balance of this customer is: " << balanceOfClient << endl;
	highestBalanceClient = HighestBalance(c, size, NumberOfAccounts);
	cout << "The name of the client having the highest balance is " << highestBalanceClient.firstName << " " << highestBalanceClient.lastName << endl;
	AddClient(c, size, NumberOfAccounts);
	return 0;
}