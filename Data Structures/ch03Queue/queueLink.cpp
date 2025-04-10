#include<iostream>
using namespace std;

struct NODE{
	int data;
	NODE* next;
};
struct Queue{
	NODE* front;
	NODE* rear;
};

void init(Queue&);
bool empty(Queue&);
void enqueue(Queue&, int);
bool dequeue(Queue&);
int front(Queue&);
int size(Queue&);
void display(Queue&);


int main(){
	Queue q;
	int val, n=10;

	init(q);

	for(int i=0; i<n ;i++){
		val = rand()%10+1;
		enqueue(q,val);
	}
	display(q);
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
	q.front = q.rear = nullptr;
}
bool empty(Queue& q){
	return q.front == nullptr;
}
void enqueue(Queue& q, int val){
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	tmp->next = nullptr;
	if(empty(q)){
		q.front = q.rear = tmp;
		return;
	}
	q.rear->next = tmp;
	q.rear = tmp;
}
bool dequeue(Queue& q){	
	NODE* tmp;
	if(empty(q)) return false;

	tmp = q.front;
	q.front = q.front->next;
	delete tmp;
	if(q.front == nullptr) q.rear = nullptr;
	return true;
}
int front(Queue& q){
	if(empty(q)) {cerr<<"Error"<<endl; exit(1);}
	return q.front->data;
}
int size(Queue& q){
	NODE* cur;
	int c=0;
	if(empty(q)) return 0;
	cur = q.front;
	while(cur!=nullptr){
		c++;
		cur = cur->next;
	}
	return c;
}
void display(Queue& q){
	NODE* cur;
	if(empty(q)){
		cout<<"Empty queue"<<endl;
		return ;
	}
	cout<<"Queue is: "<<endl;
	cur = q.front;
	while(cur!=nullptr){
		cout<<cur->data<<" ";
		cur = cur->next;
	}
	cout<<endl;
}