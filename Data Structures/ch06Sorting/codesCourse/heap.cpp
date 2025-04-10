#include<iostream>
using namespace std;

#include<ctime>
#include<iomanip>

struct HEAP{
	int Max;
    int N;
    int *a;
};

//basic operations
HEAP* initialize( int );
int isEmpty( HEAP*  );
int isFull( HEAP* );

//main operations
void insert( HEAP* , int );
int deleteMax( HEAP* );

//usefull operations
void sink(HEAP* , int );
void swim(HEAP* , int );

//display
void displayHeapTree(HEAP* );
void displayHeapArray(HEAP* );
//heapsort
void heapsort1(int*,int );
void heapsort2(HEAP*,int*,int );
void heapsort(int*,int );
void sink1(int *, int , int );

void swap(int *,int i,int j);

int main()
{
	
    HEAP* h;
	int Max, N;
	int *A;
	
	srand(time(0));
	cout<<"Input capacity of Heap: ";
	cin>>Max;
    h = initialize( Max );

	cout<<"Input nb of elements : ";
	cin>>N;
	A = new int[N];

	for(int i=0; i<N; i++){
		A[i]=rand()%101+0;
		cout<<A[i]<<" "<<endl;
		insert( h, A[i] );
	}
	displayHeapTree(h);
	displayHeapArray(h);
	heapsort2(h,A,N);
	
	//---------------------//
	/*
	int N;
	int *A;
	cout<<"Input nb of elements : ";
	cin>>N;
	A = new int[N+1];//A starts from 1 to N
	cout<<"Fill A with random values: "<<endl;
	for(int i=1; i<=N; i++){
		A[i]=rand()%101+0;
		cout<<A[i]<<" ";
	}
	cout<<endl;
	heapsort(A,N);
	*/

	cout<<"Sorted Array"<<endl;
	for(int i=1; i<=N; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;	
}

HEAP* initialize( int Max ){
    HEAP* h;
	h = new HEAP;
/* Allocate the array plus one extra for sentinel */
	h->a = new int[Max + 1];
	h->Max = Max;
	h->N = 0;
	return h;
 }

int isEmpty( HEAP* h ){
   return h->N == 0;
}
int isFull( HEAP* h){
   return h->N == h->Max;
}

void displayHeapArray(HEAP* h){
	for(int i=1;i<=h->N; i++)
		cout<<h->a[i]<<" ";
	cout<<endl;
}

void displayHeapTree(HEAP* h){
	int k;
	if(isEmpty(h)){
		cout<<"Heap is empty!"<<endl;
		return ;
	}
	cout<<"The heap is: "<<endl;
	cout<<setw(5)<<h->a[1];
	k=2;
	for(int i=2; i<=h->N; i++){				
		if(i==k){
			cout<<endl;
			k*=2;
		}
		cout<<setw(5)<<h->a[i];
	}
	cout<<endl;
}

void insert( HEAP* h, int x )
{
  if( isFull( h ) ){
    cout<<"Priority queue is full";
    return;
  }
  h->a[++h->N]=x;
  swim(h,h->N);
}

void swim(HEAP* h, int k)
{
	while(k>1 && h->a[k] > h->a[k/2])
	{
		swap(h->a,k,k/2);
		k=k/2; 
	}
}


int deleteMax( HEAP* h )
{
    int max;
	if(isEmpty(h))
		return -1;
	max = h->a[ 1 ];
	h->a[ 1 ] = h->a[ h->N-- ];
	sink(h,1);
	return max;
}

//j++ is needed to catch the bigger child
//j<h->N needed if 2*k is N so there is no right child, 
//only left child,so no need to do j++
void sink(HEAP* h, int k)
{
	while(2*k <= h->N)
	{
		int j=2*k;
		if(j < h->N && h->a[j] < h->a[j+1]) j++;
		if(h->a[k] >= h->a[j]) break;
		swap(h->a,k,j);
		k=j;
	}
}

//NlogN but uses extra array in heap
void heapsort1(int *A, int N)
{
	HEAP* h = initialize(N);
	for(int i=0; i<N; i++)
		insert(h,A[i]);
	for(int i=N-1; i>=0; i--)
		A[i]=deleteMax(h);
}

void heapsort2(HEAP* h, int* A, int N)
{
	for(int i=N-1; i>=0; i--)
		A[i]=deleteMax(h);
}

void heapsort(int *a, int N)
{
	for(int k = N/2; k>=1; k--)
		sink1(a,k,N);
	while(N>1)
	{
		swap(a,1,N);
		sink1(a,1,--N);
	}
}

void sink1(int *a, int k, int N)
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

/* END */

