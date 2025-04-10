#include<iostream>
using namespace std;
#include<fstream>

struct Student{
	int id;
	char name[20];
};
struct NODE{
	Student st;
	NODE* next;
};

struct List {
	NODE* head;
	int n;
};

void initialize(List&);
bool isEmpty(List&);
void insert(List&,Student);
bool search(List&, int );
bool remove(List&,int );
int size(List&);
void removeList(List&);
void display(List&);

int main(){
	List l;
	
	Student s;
	ifstream fin;

	initialize(l);
	fin.open("ch01Elementary/in_ex2.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}

	while(fin>>s.id>>s.name){
		insert(l,s);
	}
	display(l);

	if(search(l,678))cout<<"Found"<<endl;
	else cout<<"Not found"<<endl;

	cout<<"List size: "<<size(l)<<endl;
	remove(l,145);
	remove(l,532);
	cout << "List size after 2 removes: " << size(l) << endl;
	display(l);
	removeList(l);
	display(l);
	cout << "List size: " << size(l) << endl;

	return 0;
}

void initialize(List &l){
	l.head = nullptr;
	l.n = 0;
}
bool isEmpty(List &l){
	return l.head == nullptr; // l.n == 0
}

void insert(List &l,Student st){
	NODE* tmp, *cur, *prev;

	tmp = new NODE; 
	tmp->st = st;
	tmp->next = nullptr;

	l.n++;

	if(isEmpty(l)){
		l.head = tmp;
		return;
	}

	if(st.id<l.head->st.id){
		tmp->next = l.head;
		l.head = tmp;
		return;
	}

	cur = l.head;
	while(cur!=nullptr){
		if(st.id<cur->st.id)
			break;
		prev = cur;
		cur = cur->next;
	}
	prev->next = tmp;
	tmp->next = cur;

}
bool search(List& l, int id){
	NODE* cur;

	cur = l.head;
	while(cur!=nullptr){
		if(id == cur->st.id)
			return true;
		cur = cur->next;
	}
	return false;
}
bool remove(List &l,int id){
	NODE* cur, *prev, *tmp;
	
	if(isEmpty(l))
		return false;

	if(id == l.head->st.id){
		tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		l.n--;
		return true;
	}

	cur = l.head;
	while(cur!=nullptr){
		if(id == cur->st.id)
			break;
		prev = cur;
		cur = cur->next;
	}
	if(cur==nullptr) return false;
	prev->next = cur->next;
	delete cur;
	l.n--;
	return true;
}
int size(List& l){
	return l.n;
}
void removeList(List& l){
	NODE *tmp;

	while(l.head!=nullptr){
		tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		l.n--;
	}

}
void display(List& l){
	NODE* cur;

	if(isEmpty(l)){
		cout<<"Empty list"<<endl;
		return;
	}

	cout<<"List is: "<<endl;
	cur = l.head;
	while(cur!=nullptr){
		cout<<cur->st.id<<" "<<cur->st.name<<endl;
		cur = cur->next;
	}

}