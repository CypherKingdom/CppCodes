#include<iostream>
using namespace std;
#include<ctime>

enum entryType {EMPTY,ACTIVE,DELETED};
struct NODE{
	int key;
	int data;
	entryType info;
};

struct HASH{
	NODE* a; //hashing table
	int m;//size
	int n;//nb of elements
};

HASH* initialize(int);
void insert(HASH*,int, NODE);

int hashing(int,int);

//Linear Probing
int hashingLP(HASH*,int);
HASH* rehashLP(HASH*,int);//dynamic hashing 
int searchLP(HASH*,int);

//Quadratic Probing
int hashingQP(HASH*&,int);
HASH* rehashQP(HASH*,int);//dynamic hashing
int searchQP(HASH*,int);

//Double Hashing
int hashing2(int,int);
int hashingDouble(HASH*&, int, int);
HASH* rehashDouble(HASH*,int,int);//dynamic hashing
int searchDouble(HASH*,int,int);

void display(HASH*);
int prime(int);
int primeSmaller(int);

int main(){
	HASH *h;
	int m, n, k, key;	
	NODE node;

	srand(time(0));
	cout<<"Input m - size of Hashing table: "; cin>>m;
	h = initialize(m);
	cout<<"Input n - nb of elements to insert: "; cin>>n;

	cout<<"Inserting n nodes (key,data) in table: "<<endl;
	for(int i=0; i<n; i++){
		node.data = rand()%100;
		node.key = rand()%1000;
		node.info = ACTIVE;
		k=hashingQP(h,node.key);//hashingLP(h,node.key);//R=primeSmaller(m);hashingDouble(h,node.key,R);
		cout<<"("<<node.key<<","<<node.data<<") in "<<k<<" "<<endl;
		insert(h, k, node);
	}
	display(h);

	cout<<"Input a key: "; cin>>key;
	cout<<"Searching..."<<endl<<"index: "<<searchQP(h,key)<<endl;
	cout<<"Input a key: "; cin>>key;
	cout<<"Searching..."<<endl<<"index: "<<searchQP(h,key)<<endl;
/*
	cout<<"Input a key: "; cin>>key;
	cout<<"Searching..."<<endl<<"index: "<<searchDouble(h,key,7)<<endl;
	cout<<"Input a key: "; cin>>key;
	cout<<"Searching..."<<endl<<"index: "<<searchDouble(h,key,7)<<endl;
*/
	return 0;
}

HASH* initialize(int m){
	HASH* h = new HASH;
	h->a = new NODE[m];
	h->m = m;
	h->n = 0;
	for(int i=0;i<m;i++)
		h->a[i].info=EMPTY;
	return h;
}

int hashing(int key,int m){
	return key%m;
}

void insert(HASH* h,int k, NODE node){
	h->a[k] = node;
	h->n++;
}

void display(HASH* h){	
	cout<<"Hashing table: index: (key,data)..."<<endl;
	for(int k=0; k<h->m; k++){
		if(h->a[k].info==ACTIVE)
			cout<<k<<": "<<h->a[k].key<<","<<h->a[k].data<<endl;	
	}
	cout<<endl;
}

//-----------LP--------------//
int hashingLP(HASH* h, int key){
	int k;
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i)%h->m;
		if(h->a[k].info != ACTIVE)
			return k;
	}
	return -1;
}

HASH* rehashLP(HASH* h,int newSize){//dynamic hashing
	HASH* newh=initialize(newSize);
	int k;
	for(int i=0; i<h->m; i++){
		if(h->a[i].info==ACTIVE){
			k=hashingLP(newh,h->a[i].key);
			insert(newh,k,h->a[i]);
		}
	}
	delete [] h->a;
	delete h;
	return newh;
}

int searchLP(HASH*h,int key){
	int k;
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i)%h->m;
		if(h->a[k].info == EMPTY)
			return -1;
		if(h->a[k].info == ACTIVE && h->a[k].key == key)
			return k;
	}
	return -1;
}

//-----------QP--------------//
int hashingQP(HASH*& h, int key){
	int k;
	if(h->n >= h->m/2) 
		h = rehashQP(h,2*h->m);//rehash(h,prime(2*h->m));
	//if n<=m/2 && m prime, then for sure we can find a place
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i*i)%h->m;
		cout<<k<<" ";
		if(h->a[k].info != ACTIVE)
			return k;
	}
	return -1;
}

HASH* rehashQP(HASH* h,int newSize){//dynamic hashing
	HASH* newh=initialize(newSize);
	int k;
	for(int i=0; i<h->m; i++){
		if(h->a[i].info==ACTIVE){
			k=hashingQP(newh,h->a[i].key);
			insert(newh,k,h->a[i]);
		}
	}
	delete [] h->a;
	delete h;
	return newh;
}

int searchQP(HASH* h, int key){
	int k;
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i*i)%h->m;
		if(h->a[k].info == EMPTY)
			return -1;
		if(h->a[k].info == ACTIVE && h->a[k].key == key)
			return k;
	}
	return -1;
}

//-----------Double hashing--------------//
int hashing2(int key,int R){
	return R-key%R;
}

int hashingDouble(HASH*& h, int key, int R){
	int k;
	if(h->n >= h->m/2) 
		h = rehashDouble(h,2*h->m,R);//rehashDouble(h,prime(2*h->m),primeSmaller(prime(2*h->m)));
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i*hashing2(key,R))%h->m;
		cout<<k<<" ";
		if(h->a[k].info != ACTIVE)
			return k;
	}
	return -1;
}

HASH* rehashDouble(HASH* h,int newSize,int R){//dynamic hashing
	HASH* newh=initialize(newSize);
	int k;
	for(int i=0; i<h->m; i++){
		if(h->a[i].info==ACTIVE){
			k=hashingDouble(newh,h->a[i].key,R);
			insert(newh,k,h->a[i]);
		}
	}
	delete [] h->a;
	delete h;
	return newh;
}

int searchDouble(HASH* h, int key, int R){
	int k;
	cout<<"Searching..."<<endl;
	for(int i=0; i<h->m; i++){
		k = (hashing(key,h->m)+i*hashing2(key,R))%h->m;
		cout<<k<<" ";
		if(h->a[k].info == EMPTY)
			return -1;
		if(h->a[k].info == ACTIVE && h->a[k].key == key)
			return k;
	}
	return -1;
}

int prime(int x){
	//return the 1st prime greater than x
	bool isprime;
	while(1){
		isprime=true;
		for(int i=2; i<=x/2; i++){
			if(x%i==0){
				isprime=false;
				break;
			}
		}
		if(isprime)
			return x;
		x++;
	}

}

int primeSmaller(int x){
	//return the 1st prime smaller than x
	bool isprime;
	while(1){
		isprime=true;
		for(int i=2; i<=x/2; i++){
			if(x%i==0){
				isprime=false;
				break;
			}
		}
		if(isprime)
			return x;
		x--;
	}

}