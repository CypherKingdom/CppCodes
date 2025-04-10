#include<iostream>
using namespace std;
#include <ctime>
#include "maxHeap.h"

void merge(HEAP*, HEAP*);//ex9
bool isHeap(int*,int);//ex16

bool isHeap(int*,int, int);//ex16, another method
void shiftArray(int*,int);
void display(int*,int);

int main(){
	HEAP*h;
	int max=100, n;
	int val;
	int *a;

	srand(time(0));
	//cout<<"Input max: "; cin>>max;
	cout<<"Input n: ";
	cin>>n;
	a = new int[n+1];

	h = initialize(max);
	cout<<"Random values for h"<<endl;
	for(int i = 0; i< n; i++){
		val = rand()%100;
		a[i] = val;
		cout<<val<<" ";
		insert(h,val);
	}
	cout<<endl;
	displayHeapArray(h);
	displayHeapTree(h);

	heapsort2(a,n);
	cout<<"heapsort2...: "<<endl;
	display(a,n);
	
	shiftArray(a,n); display(a,n);
	if(isHeap(a,n))cout<<"heap true"<<endl; else cout<<"heap false"<<endl;
	if(isHeap(h->a,n))cout<<"heap true"<<endl; else cout<<"heap false"<<endl;

	minheapsort(a,n);
	display(a,n);
	heapsort1(a,n);
	cout<<"heapsort1...Sorted array is: "<<endl;
	display(a,n);


	return 0;
}

void shiftArray(int*a,int n){
	//shift array (to start from index 1)
	for(int i = n-1; i>=0; i--){
		a[i+1] = a[i];
	}
	a[0]=-1;
}

void display(int* a,int n){
	cout<<"Array is: ";
	for(int i = 0; i<= n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


bool isHeap(int* a, int n){	
	for(int k=1; k<=n/2; k++){
		int j = 2*k;
		if(j < n && a[j] < a[j+1]) j++;
		if(a[k] < a[j] ) return false;
	}
	return true;
}

void merge(HEAP*h1, HEAP*h2){
	int val, n2 = h2->n;
	for(int i = 1; i<= n2; i++){
		val = deleteMax(h2);
		insert(h1,val);
	}
	cout<<endl;
}



//flag= 0 or 1, i.e. heap starting from 0 or 1
bool isHeap(int *a, int n, int flag){
	if(flag==0){
		for(int k = 0; k<=(n-3)/2; k++) 
			if(a[k]<a[2*k+1] || a[k]<a[2*k+2])
				return false;
		return true;
	}else{
		for(int k = 1; k<=(n-1)/2; k++) 
			if(a[k]<a[2*k] || a[k]<a[2*k+1])
				return false;
		return true;
	}
}

/*
bool isHeap(int *a, int n, int flag){
	if(flag==0){
		for(int k = 0; k<=(n-2)/2; k++) 
			if(a[k]<a[2*k+1] || (2*k+2<n &&a[k]<a[2*k+2]))
				return false;
		return true;
	}else{
		for(int k = 1; k<=n/2; k++) 
			if(a[k]<a[2*k] || (2*k+1<=n && a[k]<a[2*k+1]))
				return false;
		return true;
	}
}
*/