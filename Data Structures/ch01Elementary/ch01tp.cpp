#include<iostream>
using namespace std;
#include<ctime>

struct NODE{
	int data;
	NODE* next;
};

struct List {
	NODE* head;
	int n;
};

void initialize(List&);
bool isEmpty(List&);

void insert(List&,int);
void insertAtHead(List&,int);
void display(List&);
void remove(List&, int);
void merge(List&, List&, List&);
void partition(List&, List&);

int main(){
	List l, l1, l2, l3, l4, lp;
	int N=10 , x;
	srand(time(0));
	
	initialize(l);
	
	for(int i=0; i<N; i++){
		x = rand()%51 + 50;
		insert(l,x);
	}
	display(l);

	//remove(head,80); display(head);

	initialize(l1); initialize(l2); initialize(l3);
	for(int i=0; i<N; i++){
		x = rand()%51 + 50;
		insert(l1,x);
	}
	display(l1);
	for(int i=0; i<N; i++){
		x = rand()%51 + 50;
		insert(l2,x);
	}
	display(l2);
	merge(l1,l2,l3);
	cout<<"After merging"<<endl;
	display(l3);


	initialize(l4);  initialize(lp);
	for(int i=0; i<N; i++){
		x = rand()%51 + 50;
		insertAtHead(l4,x);
	}
	cout<<"List 4"<<endl;
	display(l4);
	partition(l4,lp);
	cout<<"After partition"<<endl;
	display(lp);

	return 0;
}

void initialize(List& l){
	l.head = nullptr;
	l.n = 0;
}
bool isEmpty(List& l){
	return l.head == nullptr;
}

void insert(List& l,int val){
		NODE* tmp, *cur, *prev;

	tmp = new NODE; 
	tmp->data = val;
	tmp->next = nullptr;

	if(isEmpty(l)){
		l.head = tmp;
		return;
	}

	if(val<l.head->data){
		tmp->next = l.head;
		l.head = tmp;
		return;
	}

	cur = l.head;
	while(cur!=nullptr){
		if(val<cur->data)
			break;
		prev = cur;
		cur = cur->next;
	}
	prev->next = tmp;
	tmp->next = cur;


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
		cout<<cur->data<<" ";
		cur = cur->next;
	}
	cout<<endl;
}
void remove(List& l, int x){
	NODE* cur, *tmp, *prev;

	if(isEmpty(l))
		return ;

	if(x <= l.head->data){
		while(l.head!=nullptr){
			tmp = l.head;
			l.head = l.head->next;
			delete tmp;
		}
		return;
	}
	
	cur = l.head;
	while(cur!=nullptr){
		if(x <= cur->data)
			break;
		prev = cur;
		cur = cur->next;
	}

	if(cur==nullptr) return;
	
	while(cur!=nullptr){
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}

	prev->next = nullptr;
}
void merge(List& l1, List& l2, List& l){
	NODE* cur1, *cur2, *cur;

	cur1 = l1.head;
	cur2 = l2.head;
	while(cur1!=nullptr && cur2 != nullptr){
		if(cur1->data < cur2->data){
			insert(l,cur1->data);
			cur1 = cur1->next;
		}else if (cur1->data > cur2->data){
			insert(l,cur2->data);
			cur2 = cur2->next;
		}else{
			insert(l,cur1->data);
			insert(l,cur2->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

	while(cur2!=nullptr){
		insert(l,cur2->data);
		cur2 = cur2->next;
	}


	while(cur1!=nullptr){
		insert(l,cur1->data);
		cur1 = cur1->next;
	}

}
void partition(List& l, List& hi){//hi same as lp
	NODE* cur, *tmp;
	int pivot ;
	List lo;
	initialize(lo);
	if(isEmpty(l))
		return;

	pivot = l.head->data;
	
	cur = l.head->next;
	while(cur!=nullptr){
		if(cur->data<=pivot)
			insertAtHead(lo,cur->data);
		else
			insertAtHead(hi,cur->data);
		cur = cur->next;
	}

	//merging both list with pivot

	insertAtHead(hi, pivot);

	cur = lo.head;
	while (cur!= nullptr) {
		insertAtHead(hi, cur->data);
		cur = cur->next;
	}

}

void insertAtHead(List& l,int val){
		NODE* tmp, *cur, *prev;

	tmp = new NODE; 
	tmp->data = val;
	tmp->next = nullptr;

	tmp->next = l.head;
	l.head = tmp;

}

