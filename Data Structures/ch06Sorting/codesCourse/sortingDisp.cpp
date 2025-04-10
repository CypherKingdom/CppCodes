#include<iostream>
using namespace std;
#include<ctime>
#include<algorithm>

#define MAX 23
#define STOP 14


void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int*, int);

void mergesort(int *, int *, int, int);
void merge(int *, int *, int, int, int);

void quicksort(int*, int, int);
int partition(int*, int, int);

void heapsort(int*, int);
void sink(int *, int, int);


void heapsort1(int*, int);
void sink1(int *, int, int);

void swap(int *a, int i, int j);
void display(int*a, int N);
void resetArray(int *a, int *b, int N);

int main() {
	int *a, *aux, *b;
	int N = MAX;
	srand(time(0));

	a = new int[N];
	b = new int[N];
	aux = new int[N];

	for (int i = 0; i<N; i++) {
		a[i] = rand() % 100;
		b[i] = a[i];
	}

	cout << "Array before sorting" << endl;
	display(a, N);
	sort(a, a + N);
	cout << "Array after sorting" << endl;
	display(a, N);
	resetArray(a, b, N);

	cout << "Insertion sort: " << endl;
	insertionSort(a, N);
	display(a, N);
	resetArray(a, b, N);

	cout << "Selection sort: " << endl;
	selectionSort(a, N);
	display(a, N);
	resetArray(a, b, N);

	cout << "Bubble sort: " << endl;
	bubbleSort(a, N);
	display(a, N);
	
	resetArray(a, b, N);
	cout << "Mergesort: " << endl;
	mergesort(a, aux, 0,N-1);
	display(a, N);

	resetArray(a, b, N);
	cout << "Quicksort : " << endl;
	quicksort(a, 0, N - 1);
	display(a, N);

	resetArray(a, b, N);
	cout << "heapsort: " << endl;
	heapsort(a, N);
	display(a, N);

	resetArray(a, b, N);
	cout << "heapsort1: " << endl;
	heapsort1(a, N);
	display(a, N);
	return 0;
}

void display(int*a, int N) {
	for (int i = 0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int *a, int i, int j) {
	int tmp;
	tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

void resetArray(int *a, int *b, int N) {
	for (int i = 0; i<N; i++) {
		a[i] = b[i];
	}
}

void insertionSort(int *a, int N) {
	for (int i = 1; i<N; i++) {
		if (i == STOP) return;
		for (int j = i; j>0; j--)
			if (a[j]<a[j - 1])
				swap(a,j,j-1);
			else
				break;
	}
}

void selectionSort(int *a, int N) {
	int min;
	for (int i = 0; i<N; i++) {
		if (i == STOP) return;
		min = i;
		for (int j = i + 1; j<N; j++)
			if (a[j]<a[min])
				min = j;
		swap(a, i, min);
	}
}


void bubbleSort(int *a, int N) {
	for (int i = 1; i <= N - 1; i++){
		if (i == STOP) return;
		for (int j = 0; j<N - i; j++){
			if (a[j] > a[j + 1])
				swap(a, j, j+1);
		}
	}
}

void mergesort(int *a, int *aux, int lo, int hi) {
	if (hi <= lo) return;
	int mid = (lo + hi) / 2;
	mergesort(a, aux, lo, mid);
	mergesort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
	display(a, MAX);
}

void merge(int *a, int *aux, int lo, int mid, int hi) {
	for (int k = lo; k <= hi; k++)
		aux[k] = a[k];

	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++) {
		if (i>mid)				a[k] = aux[j++];
		else if (j>hi)			a[k] = aux[i++];
		else if (aux[j]<aux[i])	a[k] = aux[j++];
		else					a[k] = aux[i++];
	}
}

void quicksort(int* a, int lo, int hi) {
	if (hi <= lo) return;
	int j = partition(a, lo, hi);
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
	display(a, MAX);
}
int partition(int* a, int lo, int hi) {
	int i = lo, j = hi + 1, pivot = a[lo];

	while (true) {

		while (a[++i]<pivot)
			if (i == hi) break;

		while (pivot<a[--j])
			if (j == lo) break;

		if (i < j)
			swap(a,i,j);
		else
			break;
	}
	swap(a, lo, j);
	return j;
}

void heapsort(int *a, int N){
	for (int k = (N-1) / 2; k >= 0; k--)
		sink(a, k, N);
	while (N>0){
		swap(a, 0, N-1);
		sink(a, 0, --N);
		display(a, MAX);
	}
}

void sink(int *a, int k, int N){
	while (2 * k + 1 <= N-1){
		int j = 2 * k + 1;
		if (j < N-1 && a[j] < a[j + 1]) j++;
		if (a[k] >= a[j]) break;
		swap(a, k, j);
		k = j;
	}
}



void heapsort1(int *b, int N)
{
	int*a = new int[N+1];
	for (int i = 0; i < N; i++) a[i+1] = b[i];
	for (int k = N / 2; k >= 1; k--)
		sink1(a, k, N);
	while (N>1)
	{
		swap(a, 1, N);
		sink1(a, 1, --N);
		display(a, MAX+1);
	}
}

void sink1(int *a, int k, int N)
{
	while (2 * k <= N)
	{
		int j = 2 * k;
		if (j < N && a[j] < a[j + 1]) j++;
		if (a[k] >= a[j]) break;
		swap(a, k, j);
		k = j;
	}
}