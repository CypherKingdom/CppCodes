#include<iostream>
using namespace std;
#include<ctime>

struct NODE{
	char key[20];
	int data;
	NODE* next;
};

struct HASH{
	NODE** a; //hashing table
	int m;//size
};

HASH* initialize(int);
void insert(HASH*,int, int,char*);
int hashing(char*,int);
NODE* search(HASH*,char*);
void display(HASH*);

int main(){
	HASH *h;
	int m, n, val, k;	
	char key[20];
	NODE* ptr;

	srand(time(0));
	cout<<"Input m - size of Hashing table: "; cin>>m;
	h = initialize(m);
	cout<<"Input n - nb of elements to insert: "; cin>>n;

	cout<<"Inserting n nodes (key,data) in table: "<<endl;
	for(int i=0; i<n; i++){
		val = rand()%100;
		//key = rand()%1000;
		cout<<"Input key: ";
		cin>>key;
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

int hashing(char *key, int m){ 
	int k = 0, a = 127;
      while (*key != '\0'){
		k = (a*k + *key) % m;
	    key++;
	  }
      return k;
}


void insert(HASH* h,int k, int val,char* key){
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	strcpy(tmp->key,key);
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

NODE* search(HASH*h,char* key){
	int k;
	k = hashing(key,h->m);
	for(NODE* cur=h->a[k]; cur!=NULL; cur=cur->next){
		if(strcmp(cur->key,key)==0)
			return cur;
	}
	return NULL;
}
