typedef int dataType;

struct HEAP{
	dataType *a;
	int max;
	int n;
};

HEAP* initialize(int);
bool isEmpty(HEAP*);
bool isFull(HEAP*);

void insert(HEAP*,dataType);
dataType deleteMax(HEAP*);


void swim(HEAP*,int);
void sink(HEAP*, int);

void displayHeapArray(HEAP*);
void displayHeapTree(HEAP*);

void swap(dataType*,int,int);
int nbNodes(HEAP*);


void decreaseKey(HEAP*,int , dataType);//ex10.1
void increaseKey(HEAP*,int , dataType);//ex10.1
void changeKey(HEAP*,dataType,dataType);
int find(HEAP*,dataType);

void swim1(HEAP*,int); //ex10.2
void insert1(HEAP*,dataType);//ex10.2

dataType findMax(HEAP*);
dataType findMin(HEAP*);//ex13


void heapsort(dataType*,int );// a start from 1, using aux
void heapsort1(dataType*,int );//a start from 1, ascending order
void sink1(dataType*,int, int);
void heapsort2(dataType*,int);//a start from 0
void sink2(dataType*,int, int);
void heapsort3(HEAP*, dataType*,int);

void sinkMinHeap(int *, int , int );
void minheapsort(int *, int );//a start from 1, descending order

