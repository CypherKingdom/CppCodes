#include<iostream>
using namespace std;

#include "maxHeap.h"

HEAP* initialize(int max){
	HEAP* h = new HEAP;
	h->max = max;
	h->a = new dataType[max+1];
	h->n = 0;
	return h;
}
bool isEmpty(HEAP* h){
	return h->n == 0;
}
bool isFull(HEAP*h){
	return h->n == h->max;
}

void swim(HEAP* h,int k){
	while(k>1 && h->a[k] > h->a[k/2]){
		swap(h->a,k,k/2);
		k = k/2;
	}
}


void insert(HEAP* h,dataType val){
	if(isFull(h)){
		cout<<"Heap is full!"<<endl;
		return;
	}
	h->a[++h->n] = val;
	swim(h,h->n);
}

void sink(HEAP* h, int k){
	int j;
	while(2*k <= h->n){
		j = 2*k;
		if(j < h->n && h->a[j+1] > h->a[j] ) j = 2*k+1;//j++
		if(h->a[k] >= h->a[j]) break;
		swap(h->a, k, j);
		k = j;
	}
}

dataType deleteMax(HEAP* h){
	dataType max;
	if(isEmpty(h)){
		return -1;
	}
	max = h->a[1];
	h->a[1] = h->a[h->n--];
	sink(h,1);
	return max;
}



void displayHeapArray(HEAP* h){
	if(isEmpty(h)){
		cout<<"Heap is empty"<<endl;
		return;
	}
	cout<<"Heap array is: "<<endl;
	for(int i=1; i<=h->n; i++){
		cout<<h->a[i]<<" ";
	}
	cout<<endl;
}

void displayHeapTree(HEAP* h){
	int k;
	if(isEmpty(h)){
		cout<<"Heap is empty"<<endl;
		return;
	}
	cout<<"Heap tree is: "<<endl;	
	cout<<h->a[1];
	k=2;
	for(int i=2; i<=h->n; i++){
		if(i == k){
			cout<<endl;
			k*=2;
		}
		cout<<h->a[i]<<" ";
	}
	cout<<endl;
}

void swap(dataType*a,int i,int j){
	dataType tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int nbNodes(HEAP* h){
	return h->n;
}

void decreaseKey(HEAP* h,int k, dataType newkey){
	h->a[k] = newkey;
	sink(h,k);
}
void increaseKey(HEAP*h,int k, dataType newkey){
	h->a[k] = newkey;
	swim(h,k);
}

void changeKey(HEAP*h,dataType oldkey,dataType newkey){
	int k = find(h,oldkey);
	if(k==-1) return;
	if(h->a[k]<newkey)
		increaseKey(h,k,newkey);
	else
		decreaseKey(h,k,newkey);
}

int find(HEAP* h,dataType key){
	for(int i=1;i<=h->n;i++)
		if(h->a[i]==key)
			return i;
	return -1;
}


void swim1(HEAP* h,int k){
	dataType val = h->a[k];
	while(k>1 && val > h->a[k/2]){
		h->a[k] = h->a[k/2];
		k = k/2;
	}
	h->a[k] = val;
}

void insert1(HEAP* h,dataType val){
	if(isFull(h)){
		cout<<"Heap is full!"<<endl;
		return;
	}
	h->a[++h->n] = val;
	swim1(h,h->n);
}

dataType findMax(HEAP* h){
	dataType max;
	if(isEmpty(h)){
		return -1;
	}
	max = h->a[1];
	return max;
}

int findMin(HEAP* h){
	int min;
	min = h->a[h->n/2+1];
	for(int i = h->n/2+1; i<= h->n; i++){
		if(h->a[i]<min)
			min = h->a[i];
	}
	return min;
}

void heapsort(dataType*a,int n){
	HEAP* h = initialize(n);
	for(int i=0; i<n; i++)
		insert(h,a[i]);
	for(int i=n-1; i>=0; i--)
		a[i] = deleteMax(h);
}
void heapsort1(dataType*a,int n){
	for(int k=n/2; k>=1; k--)
		sink1(a,k,n);
	while(n>1){
		swap(a,1,n);
		sink1(a,1,--n);
	}
}
void sink1(dataType*a,int k, int n){
	int j;
	while(2*k<=n){
		j = 2*k;
		if(j<n && a[j]<a[j+1]) j = 2*k+1;//j++
		if(a[k]>=a[j]) break;
		swap(a,k,j);
		k = j;
	}
}
/*
heapsort2, indices start at 0
the parent of index k is (k-1)/2
the parent of the last element which has index n-1, is (n-1-1)/2 = (n-2)/2
*/
void heapsort2(dataType*a,int n){
	if(n<=1) return;
	for(int k=n/2-1; k>=0; k--)//(n-2)/2 = n/2 - 1
		sink2(a,k,n);
	while(n>1){
		swap(a,0,n-1);
		sink2(a,0,--n);
	}
}
void sink2(dataType*a,int k, int n){
	int j;
	if(n<=1) return;
	while(2*k+1<=n-1){//k<=(n-2)/2
		j = 2*k+1;
		if(j<n-1 && a[j] < a[j+1]) j++;//j = 2*k+2;
		if(a[k]>=a[j]) break;
		swap(a,k,j);
		k = j;
	}
}

void heapsort3(HEAP*h, dataType*a,int n){
	for(int i=n; i>=1; i--)
		a[i] = deleteMax(h);
}


void sinkMinHeap(int *a, int k, int n){//min-heap
	while(2*k <= n){
		int j = 2*k;
		if(j < n && a[j] > a[j+1]) j++;
		if(a[k] <= a[j]) break;
		swap(a,k,j);
		k = j;
	}
}
void minheapsort(int *a, int n){
	for(int k=n/2;k>=1;k--)
		sinkMinHeap(a,k,n);
	while(n>1){
		swap(a,1,n);
		sinkMinHeap(a,1,--n);
	}
}