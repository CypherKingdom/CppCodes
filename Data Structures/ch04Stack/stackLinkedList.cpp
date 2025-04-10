#include<iostream>
using namespace std;

struct NODE{
	int data;
	NODE* next;
};

struct Stack{
	NODE* top;
	//int n;//stack size
};

void init(Stack&);
bool empty(Stack&);

void push(Stack&,int);
bool pop(Stack&);
int top(Stack&);
int size(Stack&);
void display(Stack&);

int main(){
	Stack s;
	int val, n=10, np=3; 

	init(s);

	for(int i=0; i<n; i++){
		val = rand()%100;
		push(s,val);
	}
	
	display(s);

	for(int i=0; i<np; i++){
		if(empty(s))break;
		cout<<top(s)<<" ";
		pop(s);
	}
	
	cout<<"Size: "<<size(s)<<endl;
	display(s);
	while(!empty(s))pop(s);
	display(s);
	


	return 0;
}

void init(Stack& s){
	s.top = nullptr;
}
bool empty(Stack& s){
	return s.top == nullptr;
}

void push(Stack& s,int val){
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	tmp->next = nullptr;

	if(empty(s)){
		s.top = tmp;
		return ;
	}
	tmp->next = s.top;
	s.top = tmp;
}
bool pop(Stack& s){
	NODE* tmp;
	if(empty(s))
		return false;

	tmp = s.top;
	s.top = s.top->next;
	delete tmp;
	return true;
}
int top(Stack& s){
	if(empty(s)){cerr<<"Error"<<endl; exit(1);}
	return s.top->data;
}
//try to change the implementation of the stack
//to get a size function with O(1), not O(n)
int size(Stack& s){
	NODE* cur;
	int c=0;
	cur = s.top;
	while(cur!=nullptr){
		c++;
		cur = cur->next;
	}
	return c;
}
void display(Stack& s){
	NODE* cur;	
	if(empty(s)){
		cout<<"Empty stack"<<endl;
		return;
	}

	cur = s.top;
	while(cur!=nullptr){
		cout<<cur->data<<" ";
		cur = cur->next;
	}
	cout<<endl;
}
