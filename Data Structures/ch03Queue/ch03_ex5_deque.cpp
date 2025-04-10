/*
We aim to implement a new data structure called Deque. The main operations to do in Deque are called: push_front, push_back, pop_front and pop_back. Each with complexity O(1). Other operations are: front and end. Each with complexity O(1). 
Implement Deque and its operations using linked list or array implementation. Data in Deque are integers.
Example: consider many random numbers in sequence: 2, 4, 6, 8, 10, 12, 14. We need to put them in Deque by using the following operations: if we use push_front for the first four numbers, Deque becomes: 8, 6, 4, 2, then if we use push_back for the next three numbers, Deque becomes: 8, 6, 4, 2, 10, 12, 14. The front function returns 8, and the end function returns 14. If we do pop_front, the front number 8 is removed. If we do pop_back, the end number 14 is removed.   
*/


#include<iostream>
using namespace std;
#include<ctime>

struct NODE {
	int data;
	NODE* next;
	NODE* prev;
};
struct Deque {
	NODE* front;
	NODE* rear;
};

void init(Deque&);
bool empty(Deque&);
void push_back(Deque&, int);
bool pop_front(Deque&);
void push_front(Deque&, int);
bool pop_back(Deque&);
int front(Deque&);
int end(Deque&);
void display(Deque&);


int main() {
	Deque q;
	int val, n = 12;
	srand(time(0));
	init(q);

	for (int i = 0; i<n/2; i++) {
		val = rand() % 20 + 1;
		cout << val << " ";
		push_back(q, val);
	}
	cout << " * ";
	for (int i = n/2; i<n ; i++) {
		val = rand() % 20 + 1;
		cout << val << " ";
		push_front(q, val);
	}
	cout << endl;
	cout << front(q) << " "<<end(q) << endl;
	display(q);
	cout << "Dequeue 3 elements" << endl;
	for (int i = 0; i<n/3; i++) {
		if (empty(q)) break;
		cout << front(q) << " ";
		pop_front(q);
	}
	cout << endl;
	for (int i = 0; i<n/3; i++) {
		if (empty(q)) break;
		cout << end(q) << " ";
		pop_back(q);
	}
	cout << endl;
	display(q);

	return 0;
}


void init(Deque& q) {
	q.front = q.rear = nullptr;
}
bool empty(Deque& q) {
	return q.front == nullptr;
}
void push_back(Deque& q, int val) {
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	tmp->next = tmp->prev = nullptr;
	if (empty(q)) {
		q.front = q.rear = tmp;
		return;
	}
	q.rear->next = tmp;
	tmp->prev = q.rear;
	q.rear = tmp;
}
bool pop_front(Deque& q) {
	NODE* tmp;
	if (empty(q)) return false;

	tmp = q.front;
	q.front = q.front->next;
	q.front->prev = nullptr;
	delete tmp;
	if (q.front == nullptr) q.rear = nullptr;
	return true;
}

void push_front(Deque& q, int val) {
	NODE* tmp;
	tmp = new NODE;
	tmp->data = val;
	tmp->next = tmp->prev = nullptr;
	if (empty(q)) {
		q.front = q.rear = tmp;
		return;
	}
	tmp->next = q.front;
	q.front->prev = tmp;
	q.front = tmp;
}
bool pop_back(Deque& q) {
	NODE* tmp;
	if (empty(q)) return false;

	tmp = q.rear;
	q.rear = q.rear->prev;
	q.rear->next = nullptr;
	delete tmp;
	if (q.front == nullptr) q.rear = nullptr;
	return true;
}


int front(Deque& q) {
	if (empty(q)) { cerr << "Error" << endl; exit(1); }
	return q.front->data;
}
int end(Deque& q) {
	if (empty(q)) { cerr << "Error" << endl; exit(1); }
	return q.rear->data;
}
void display(Deque& q) {
	NODE* cur;
	if (empty(q)) {
		cout << "Empty Deque" << endl;
		return;
	}
	cout << "Deque is: " << endl;
	cur = q.front;
	while (cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}