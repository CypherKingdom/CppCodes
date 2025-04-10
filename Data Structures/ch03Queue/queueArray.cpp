#include<iostream>
using namespace std;

#define Max 100

struct Queue{
	int a[Max];
	int front;
	int rear;
};

void init(Queue&);
bool empty(Queue&);
bool full(Queue&);
bool enqueue(Queue&,int);
bool dequeue(Queue&);
int front(Queue&);
int size(Queue&);
void display(Queue&);

int main(){
	Queue q;
	int n=10, val;
	
	init(q);
	
	for(int i=0; i<n ;i++){
		val = rand()%10+1;
		enqueue(q,val);
	}
	cout<<"Size: "<<size(q)<<endl;
	cout<<"Dequeue 3 elements"<<endl;
	for(int i=0; i<3; i++){
		if(empty(q)) break;
		cout<<front(q)<<" ";
		dequeue(q);
	}
	cout<<"Size: "<<size(q)<<endl;
	display(q);
	while(!empty(q))dequeue(q);
	cout<<"Size: "<<size(q)<<endl;
	display(q);

	return 0;
}

void init(Queue& q){
	q.front = 1;
	q.rear = 0;
}
bool empty(Queue& q){
	return q.front == q.rear+1;
}
bool full(Queue& q){
	return q.rear == Max-1;
}
bool enqueue(Queue& q,int val){
	if(full(q)) return false;
	q.a[++q.rear] = val;
	return true;
}
bool dequeue(Queue& q){
	if(empty(q)) return false;
	q.front++;
	return true;
}
int front(Queue& q){
	if(empty(q)) {cerr<<"Error"<<endl; exit(1);}
	return q.a[q.front];
}
int size(Queue& q){
	if(empty(q)) return 0;
	return q.rear-q.front+1;
}
void display(Queue& q){
	if(empty(q)){
		cout<<"Queue is Empty"<<endl;
		return;
	}
	cout<<"Queue is: "<<endl;
	for(int i=q.front; i<=q.rear;i++){
		cout<<q.a[i]<<" ";
	}
	cout<<endl;
}