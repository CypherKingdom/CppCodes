#include<iostream>
using namespace std;
#include<ctime>

void swap(int *,int*);

void quickSort0(int*, int , int, int);
void quickSort(int*, int, int);
void quickSort1(int*, int , int);

int partition(int*, int, int);
void display(int*,int );
void insertionSort1(int *, int );

void mergesort(int *, int *, int , int, int );
void merge(int *, int *, int , int , int );

void bubbleSort(int *,int );
void selectionSort(int *,int );
void insertionSort(int*, int);

void heapsort(int*,int );
void sink(int *, int , int );
void swap(int *,int i,int j);
void shiftArray(int*a, int N);
void resetArray(int *a, int* b, int N);
void display1(int*a,int N);


int main(){
	int *a, *aux, *b;
	int N=10;

	srand(time(0));
	//cout<<"Input N: ";
	//cin>>N;
	a = new int[N+1];
	b = new int[N+1];
	aux = new int[N+1];

	for(int i=0;i<N; i++){
		a[i]=rand()%100;
		b[i] = a[i];
	}


	cout<<"Array before sorting"<<endl;
	display(a,N);
	cout<<"Insertion sort: "<<endl;
	insertionSort(a,N);
	resetArray(a,b,N);
	display(a,N);
	cout<<"Selection sort: "<<endl;
	selectionSort(a,N);
	resetArray(a,b,N);
	display(a,N);
	cout<<"Mergesort : "<<endl;
	mergesort(a,aux,0,N-1,N);
	resetArray(a,b,N);
	display(a,N);
	cout<<"Quicksort : "<<endl;
	quickSort0(a,0,N-1,N);
	resetArray(a,b,N);
	cout << "Quicksort1 : " << endl;
	quickSort1(a, 0, N - 1);
	resetArray(a, b, N);
	cout<<"heapsort : "<<endl;
	shiftArray(a,N);
	display1(a,N);
	heapsort(a,N);

	/*
	bubbleSort(a,N);	
	cout<<"Sorted Array:"<<endl;
	display(a,N);
	*/

	return 0;
}

void resetArray(int *a, int *b, int N){
	for(int i=0;i<N; i++){
		a[i] = b[i];
	}
}
void shiftArray(int*a,int N){
	//shift array (to start from index 1)
	for(int i = N-1; i>=0; i--){
		a[i+1] = a[i];
	}
	a[0]=-1;
}

void heapsort(int *a, int N)
{
	int n = N;
	for(int k = N/2; k>=1; k--)
		sink(a,k,N);
	while(N>1)
	{
		swap(a,1,N);
		sink(a,1,--N);
		display1(a,n);
	}
}

void sink(int *a, int k, int N)
{
	while(2*k <= N)
	{
		int j=2*k;
		if(j < N && a[j] < a[j+1]) j++;
		if(a[k] >= a[j]) break;
		swap(a,k,j);
		k=j;
	}
}

void swap(int *a,int i,int j){
	int tmp;
	tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

void insertionSort(int *a,int N){
	for(int i=1; i<N; i++){
		for(int j=i;j>0;j--)
			if(a[j]<a[j-1])
				swap(&a[j],&a[j-1]);
			else
				break;
		display(a,N);
	}
}

void selectionSort(int *a,int N){
 int min;
 for(int i=0; i<N; i++){
     min=i;
     for(int j=i+1; j<N ; j++)
        if(a[j]<a[min])
            min=j;
    swap(&a[i], &a[min]);
	display(a,N);
 }
}


void bubbleSort(int *a,int N){
	 for(int i=1; i<=N-1; i++)
		for(int j=0; j<N-i; j++)
			if(a[j] > a[j+1])
				swap(&a[j],&a[j+1]);
}

void mergesort(int *a, int *aux, int lo, int hi, int N){
	if(hi<=lo) return;
	int mid = (lo+hi)/2;
	mergesort(a,aux,lo,mid, N);
	mergesort(a,aux,mid+1,hi, N);
	merge(a,aux,lo,mid,hi);
	display(a,N);
}

void merge(int *a, int *aux, int lo, int mid, int hi){
	for(int k=lo; k<=hi; k++)
		aux[k] = a[k];

	int i=lo, j=mid+1;
	for(int k=lo; k<=hi; k++){
		if(i>mid)				a[k] = aux[j++];
		else if(j>hi)			a[k] = aux[i++];
		else if(aux[j]<aux[i])	a[k] = aux[j++];
		else					a[k] = aux[i++];
	}
}

void insertionSort1(int *a, int N){
    int tmp, j;
    for(int i=1; i<N ; i++){
        tmp=a[i];
        for(j=i; j>0 && a[j-1] >tmp; j--)
            a[j]=a[j-1]; //shifting
        a[j]=tmp; //insertion
    }
}


void display(int*a,int N){
	for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void display1(int*a,int N){
	for(int i=1;i<=N;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void quickSort0(int* a, int lo, int hi, int N){
	
	if(hi<=lo) return;
	int j = partition(a,lo,hi);
	quickSort0(a,lo,j-1,N);
	quickSort0(a,j+1,hi,N);
	display(a,N);
}
void quickSort(int* a, int lo, int hi) {
	if (hi <= lo) return;
	int j = partition(a, lo, hi);
	quickSort(a, lo, j - 1);
	quickSort(a, j + 1, hi);
}
int partition(int* a, int lo, int hi){
	int i=lo, j=hi+1, pivot=a[lo];

	while(true){
		
		while(a[++i]<pivot)
			if(i==hi) break;
		
		while(pivot<a[--j])
			if(j==lo) break;

		if(i < j)
			swap(&a[i],&a[j]);
		else
			break;	
	}
	swap(&a[lo],&a[j]);
	return j;
}

void swap(int *x,int*y){
	int tmp;
	tmp = *x; *x = *y; *y = tmp;
}

int median3(int* a, int lo, int hi){
	int center = (lo+hi)/2;
	
	if(a[lo]>a[center]) swap(&a[lo],&a[center]);

	if(a[lo]>a[hi]) swap(&a[lo],&a[hi]);

	if(a[center]>a[hi]) swap(&a[center],&a[hi]);

	return center;
}

void quickSort1(int* a, int lo, int hi){
	
	int median=median3(a,lo,hi);
	swap(&a[lo],&a[median]);

	if(hi<=lo+10-1){//cutoff=10
		insertionSort(a,hi-lo+1);//cout<<"Use INSERTION sort"<<endl;
		return;	
	}

	int j = partition(a,lo,hi);
	quickSort1(a,lo,j-1);
	quickSort1(a,j+1,hi);
}