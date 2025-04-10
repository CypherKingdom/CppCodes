#include<iostream>
using namespace std;
#include<ctime>

struct NODE{
	int key;
	int data;
	NODE* next;
};

struct HASH{
	NODE** a; //hashing table
	int m;//size
};

HASH* initialize(int);
void insert(HASH*,int, int,int);
int hashing(int,int);
NODE* search(HASH*,int);
void display(HASH*);

int main(){
	HASH *h;
	int m, n, key, val, k;	
	NODE* ptr;

	srand(time(0));
	cout<<"Input m - size of Hashing table: "; cin>>m;
	h = initialize(m);
	cout<<"Input n - nb of elements to insert: "; cin>>n;

	cout<<"Inserting n nodes (key,data) in table: "<<endl;
	for(int i=0; i<n; i++){
		val = rand()%100;
		key = rand()%1000;
		k = hashing(key,m);
		cout<<"("<<key<<","<<val<<") in "<<k<<" "<<endl;
		insert(h, k, val, key);
	}
	display(h);

	cout<<"Input a key: "; cin>>key;
	ptr=search(h,key);
	if(ptr!=NULL)
		cout<<"Data is: "<<ptr->data<<endl;
	else
		cout<<"Data not found"<<endl;

	return 0;
}

HASH* initialize(int m){
	HASH* h = new HASH;
	h->a = new NODE*[m];
	for(int i=0; i<m ;i++)
		h->a[i] = NULL;
	h->m = m;
	return h;
}

int hashing(int key,int m){
	return key%m;
}

void insert(HASH* h,int k, int val,int key){
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	tmp->key = key;
	tmp->next = NULL;
	
	tmp->next = h->a[k];
	h->a[k] = tmp;
}

void display(HASH* h){	
	cout<<"Hashing table: index: (key,data)..."<<endl;
	for(int k=0; k<h->m; k++){
		cout<<k<<": ";
		for(NODE* cur=h->a[k];cur!=NULL; cur=cur->next){
			cout<<"("<<cur->key<<","<<cur->data<<");\t";
		}
		cout<<endl;
	}
}

NODE* search(HASH*h,int key){
	int k;
	k = hashing(key,h->m);
	for(NODE* cur=h->a[k]; cur!=NULL; cur=cur->next){
		if(cur->key==key)
			return cur;
	}
	return NULL;
}
