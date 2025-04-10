#include<iostream>
using namespace std;

#include<ctime>

void bubbleSortFast(int *, int);
void selectionSortMax(int *, int);
void insertionSortShift(int *, int);
void display(int* ,int);
void swap(int *,int*);

int main(){
	int N, x, prev;
	int *a;
	srand(time(0));
	cout<<"Input N: "; cin>>N;
	a = new int[N];
/*
	cout<<"Input N values in ascending order: "<<endl;
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	*/
	cout<<"Random values sorted: "<<endl;
	prev = 0;
	for (int i = 0; i < N; ){
		x = rand()%100;
		if(x < prev)
			continue;
		prev = x;
		a[i++] = x ;
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"bubbleSortFast..."<<endl;
	bubbleSortFast(a,N);
	display(a,N);
	//--------------//
	cout<<"Random values: "<<endl;
	for(int i=0; i<N; i++){
		x = rand()%100;
		cout<<x<<" ";
		a[i] = x;
	}
	cout<<endl;
	cout<<"selectionSortMax..."<<endl;
	selectionSortMax(a,N);
	display(a,N);
	//--------------//
	cout<<"Random values: "<<endl;
	for(int i=0; i<N; i++){
		x = rand()%100;
		cout<<x<<" ";
		a[i] = x;
	}
	cout<<endl;
	cout<<"insertionSortShift..."<<endl;
	insertionSortShift(a,N);
	display(a,N);

	return 0;
}

void bubbleSortFast(int *a, int N){
	bool sorted;
	/*
	for(int i=0; i<N-1; i++)
		if(a[i]>a[i+1]){
			cout<<"Sorted in asc"<<endl;
			return ;
			}
	*/
	for(int i=1; i<=N-1; i++){
			sorted = true;
			for(int j=0; j<N-i; j++){
				if(a[j]>a[j+1]){
					swap(&a[j],&a[j+1]);
					sorted = false;
				}
			}
			if(sorted){
				cout<<"sorted in asc order"<<endl;
				return;
			}
	}

}

void selectionSortMax(int *a, int N){
	int max;
	for(int i=0; i<N; i++){
		max = i;
		for(int j=i; j<N; j++)
			if(a[j]>a[max])
				max = j;
		swap(&a[i],&a[max]);
	}
}

void insertionSortShift(int *a, int N){
	int key, j;
	for(int i=1; i<N; i++){
		key = a[i];
		for(j = i; j>0; j--)
			if(key<a[j-1])
				a[j] = a[j-1];
			else
				break;				
		a[j] = key;
	}

}
void display(int* a,int N){
	cout<<"Array is: "<<endl;
	for(int i=0; i<N; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

}

void swap(int *x,int*y){
	int tmp;
	tmp = *x; *x = *y; *y = tmp;
}