#include<iostream>
using namespace std;

#define Max 100

struct Stack{
	int a[Max];
	int top;
};

void init(Stack&);
bool empty(Stack&);
bool full(Stack&);
bool push(Stack&,int);
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
	s.top = -1;
}
bool empty(Stack& s){
	return s.top == -1;
}
bool full(Stack& s){
	return s.top == Max-1;
}
bool push(Stack& s,int val){
	if(full(s)) return false;
	s.a[++s.top] = val;
	return true;
}
bool pop(Stack& s){
	if(empty(s)) return false;
	s.top--;
	return true;
}
int top(Stack& s){
	if(empty(s)){cerr<<"Error"<<endl; exit(1);}
	return s.a[s.top];
}
int size(Stack& s){
	if(empty(s))return 0;
	return s.top+1;
}
void display(Stack& s){
	if(empty(s)){
		cout<<"Empty stack"<<endl;
		return ;
	}
	cout<<"Stack is"<<endl;
	for(int i=s.top; i>=0; i--){
		cout<<s.a[i]<<" ";
	}
	cout<<endl;
}