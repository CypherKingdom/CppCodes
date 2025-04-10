#include<iostream>
using namespace std;


void initMatrix(int **a, int n);
void fillPn(int **a, int n);
void fillKpq(int **a, int n, int p);
void displayG(int **a, int n);

int main() {
	int **a;
	int n;
	int p, q;

	cout << "Input n: "; 
	cin >> n;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	initMatrix(a, n);
	fillPn(a,n);
	cout << "Display Pn:" << endl;
	displayG(a, n);
	initMatrix(a, n);

	cout << "Input p of Kpq : "; 
	cin >> p;
	fillKpq(a, n, p);
	cout << "Display Kpq:" << endl;
	displayG(a, n);


	return 0;
}

void initMatrix(int **a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}

void fillPn(int **a, int n) {
	for (int i = 1; i < n-1; i++) {
		a[i][i - 1] = a[i][i + 1] = 1;
	}
	a[0][1] = a[n - 1][n - 2] = 1;
}

void fillKpq(int **a, int n, int p) {
	for (int i = 0; i < p; i++){
		for (int j = p; j < n; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = p; i < n; i++) {
		for (int j = 0; j < p; j++) {
			a[i][j] = 1;
		}
	}
}

void displayG(int **a, int n) {
	for (int i = 0; i < n; i++){
		cout << i << " --> ";
		for (int j = 0; j < n; j++){
			if (a[i][j] != 0)
				cout << j << " ";
		}
		cout << endl;
	}
}