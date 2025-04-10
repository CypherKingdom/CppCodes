#include<iostream>
#include<fstream>
using namespace std;


struct Student {
	int id;
	char name[20];
};

struct Array {
	Student *a;
	int n;
	int Max;
};

void initialize(Array &, int);
bool isFull(Array&);
bool isEmpty(Array&);
bool insert(Array&, Student st);
int search(Array&, int id);
bool modify(Array&, int id, char* newname);
bool remove(Array&, int id);
int nbElements(Array&);
void display(Array&);

int main() {
	Array t;
	Student st;
	int Max, N;
	int id;

	ifstream fin;

	fin.open("ch01Elementary/in_ex1.txt");
	if (!fin) { cerr << "Error" << endl; return 1; }
	fin >> Max >> N;
	initialize(t, Max);
	for (int i = 0; i<N; i++) {
		fin >> st.id >> st.name;
		if (!insert(t, st))cout << "List is full" << endl;
	}
	display(t);
	cout << "Input id: "; cin >> id;
	cout << "Searching...";
	if (search(t, id) == -1) cout << "Not found" << endl;
	else cout << "found" << endl;

	cout << "Input id and new name to modify" << endl;
	cin >> st.id; cin >> st.name;
	if (!modify(t, st.id, st.name))
		cout << "Cannot be modified: not in list" << endl;
	else
		cout << "Modified done!" << endl;

	cout << "Input id: "; cin >> st.id;
	if (!remove(t, st.id))
		cout << "Cannot be removed: not in list" << endl;
	else
		cout << "Removed!";

	display(t);




	return 0;
}


void initialize(Array &t, int Max) {
	t.a = new Student[Max];
	t.n = 0;
	t.Max = Max;
}
bool isFull(Array &t) {
	return t.n == t.Max;
}
bool isEmpty(Array &t) {
	return t.n == 0;
}
bool insert(Array& t, Student st) {
	int k;
	if (isFull(t))
		return false;

	for (k = 0; k<t.n; k++)
		if (st.id < t.a[k].id)
			break;
	for (int i = t.n - 1; i >= k; i--)
		t.a[i + 1] = t.a[i];

	t.a[k] = st;
	t.n++;
	return true;
}

int search(Array& t, int id) {
	for (int k = 0; k<t.n; k++)
		if (t.a[k].id == id)
			return k;
	return -1;
}
bool modify(Array& t, int id, char* newname) {
	int k = search(t, id);
	if (k == -1)
		return false;
	strcpy(t.a[k].name, newname);
	return true;
}
bool remove(Array& t, int id) {
	int k = search(t, id);
	if (k == -1)
		return false;
	for (int i = k; i<t.n - 1; i++)
		t.a[i] = t.a[i + 1];
	t.n--;
}
int nbElements(Array&t) {
	return t.n;
}
void display(Array&t) {
	if (isEmpty(t)) {
		cout << "Empty list" << endl;
		return;
	}
	cout << "List of students: " << endl;
	for (int i = 0; i<t.n; i++)
		cout << t.a[i].id << " " << t.a[i].name << endl;
}
