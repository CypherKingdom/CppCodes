#include<iostream>
using namespace std;

#define Max 10

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
	int n=9, val;
	
	init(q);
	for(int k=0; k<2 ;k++){

		for(int i=0; i<n ;i++){
			val = rand()%10+1;
			enqueue(q,val);
		}
		cout<<"Size: "<<size(q)<<endl;
		display(q);
		cout<<q.front<<" "<<q.rear<<endl;
		cout<<"Dequeue 7 elements"<<endl;
		for(int i=0; i<7; i++){
			if(empty(q)) break;
			cout<<front(q)<<" ";
			dequeue(q);
		}
		cout<<"Size: "<<size(q)<<endl;
		display(q);
		cout<<q.front<<" "<<q.rear<<endl;
		cout<<"*****"<<endl;
	}



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
	return q.front == (q.rear+1)%Max;
}
bool full(Queue& q){
	return q.front == (q.rear+2)%Max;
}
bool enqueue(Queue& q,int val){
	if(full(q)) return false;
	q.rear = (q.rear+1)%Max;
	q.a[q.rear] = val;
	return true;
}
bool dequeue(Queue& q){
	if(empty(q)) return false;
	q.front = (q.front+1)%Max;
	return true;
}
int front(Queue& q){
	if(empty(q)) {cerr<<"Error"<<endl; exit(1);}
	return q.a[q.front];
}
int size(Queue& q){
	if(empty(q)) return 0;
	if(q.rear >= q.front) 
		return q.rear-q.front+1;
	else 
		return (Max-q.front) + (q.rear+1);
}
void display(Queue& q){
	if(empty(q)){
		cout<<"Queue is Empty"<<endl;
		return;
	}
	cout<<"Queue is: "<<endl;
	if(q.rear >= q.front){
		for(int i=q.front; i<=q.rear;i++)
			cout<<q.a[i]<<" ";
		cout<<endl;
	}else{
		for(int i=q.front; i<Max;i++)
			cout<<q.a[i]<<" ";
		for(int i=0; i<=q.rear;i++)
			cout<<q.a[i]<<" ";
		cout<<endl;
	}
}