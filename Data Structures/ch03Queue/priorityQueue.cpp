#include<iostream>
using namespace std;

struct NODE {
	int data;
	int priority;
	NODE* next;
};
struct Queue {
	NODE* front;
};

void init(Queue&);
bool empty(Queue&);
void enqueue(Queue&, int, int);
bool dequeue(Queue&);
int front(Queue&);
int size(Queue&);
void display(Queue&);


int main() {
	Queue q;
	int val, pri, n = 10;

	init(q);

	for (int i = 0; i<n; i++) {
		val = rand() % 10 + 1;
		pri = rand() % 10 + 1;
		enqueue(q, val, pri);
	}
	display(q);
	cout << "Size: " << size(q) << endl;
	cout << "Dequeue 3 elements" << endl;
	for (int i = 0; i<3; i++) {
		if (empty(q)) break;
		cout << front(q) << " ";
		dequeue(q);
	}
	cout << "Size: " << size(q) << endl;
	display(q);
	while (!empty(q))dequeue(q);
	cout << "Size: " << size(q) << endl;
	display(q);
	return 0;
}

void init(Queue& q) {
	q.front = nullptr;
}
bool empty(Queue& q) {
	return q.front == nullptr;
}
void enqueue(Queue& q, int val, int priority) {
	NODE* tmp, *cur, *prev;
	tmp = new NODE;
	tmp->data = val;
	tmp->priority = priority;
	tmp->next = nullptr;
	//insert 1st element
	if (empty(q)) {
		q.front = tmp;
		return;
	}
	//insert at head
	if (q.front->priority > priority) {
		tmp->next = q.front;
		q.front = tmp;
		return;
	}
	cur = q.front->next;
	prev = q.front;
	while (cur != nullptr && cur->priority<priority) {
		prev = cur;
		cur = cur->next;
	}
	tmp->next = cur;
	prev->next = tmp;
}
bool dequeue(Queue& q) {
	NODE* tmp;
	if (empty(q)) return false;
	tmp = q.front;
	q.front = q.front->next;
	delete tmp;
	return true;
}
int front(Queue& q) {
	if (empty(q)) { cerr << "Error" << endl; exit(1); }
	return q.front->data;
}
int size(Queue& q) {
	NODE* cur;
	int c = 0;
	if (empty(q)) return 0;
	cur = q.front;
	while (cur != nullptr) {
		c++;
		cur = cur->next;
	}
	return c;
}
void display(Queue& q) {
	NODE* cur;
	if (empty(q)) {
		cout << "Empty queue" << endl;
		return;
	}
	cout << "Queue is: " << endl;
	cur = q.front;
	while (cur != nullptr) {
		cout << "("<<cur->data << ","<<cur->priority<<") ";
		cur = cur->next;
	}
	cout << endl;
}