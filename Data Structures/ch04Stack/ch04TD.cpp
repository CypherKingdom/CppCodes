#include<iostream>
using namespace std;
#include<stack>

struct NODE{
	int data;
	NODE* next;
};
void display(stack<int>);
void display(stack<float>);
void remove(stack<int>&);
void td1();
void insertAtRear(NODE*&,int);
void td2();
void td3();
void td5();
void series(int n, stack<float>& s);
void td6();


int main(){
	//td1();
	//td2();
	//td3();
	//td5();
	td6();
	return 0;
}
void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
void display(stack<float> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
void remove(stack<int>& s){
	while(!s.empty()){
		s.pop();
	}
}
void td1(){
	stack<int> s;
	int val, n=10, np=3; 

	for(int i=0; i<n; i++){
		val = rand()%100;
		s.push(val);
	}
	display(s);
	for(int i=0; i<np; i++){
		if(s.empty())break;
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"Size: "<<s.size()<<endl;
	display(s);
	remove(s);
	display(s);
}

void insertAtRear(NODE*&head,int val){
	NODE* tmp, *cur;
	tmp = new NODE;
	tmp->data = val;
	tmp->next = nullptr;
	if(head==nullptr){
		head = tmp; 
		return;
	}
	cur=head;
	while(cur->next!=nullptr){
		cur = cur->next;
	}
	cur->next = tmp;
}
void td2(){
	NODE* head=nullptr;
	NODE* cur;
	stack<int> s;
	int val, n=10;
	cout<<"List is"<<endl;
	for(int i=0; i<n; i++){
		val = rand()%100;
		cout<<val<<" ";
		insertAtRear(head,val);
	}
	cout<<endl;
	cur = head;
	while(cur!=nullptr){
		s.push(cur->data);
		cur = cur->next;
	}
	cout<<"List in reverse order"<<endl;
	display(s);
}
void td3(){
	stack<char> s;
	char *str = "layal";//hello
	bool palindrome;
	int i=0;
	while(str[i]!='\0'){
		s.push(str[i]);
		i++;
	}
	i=0;
	palindrome=true;
	while(str[i]!='\0'){
		if(str[i]!=s.top()){
			palindrome = false;
			break;
		}
		i++;
		s.pop();
	}
	if(palindrome)cout<<"Palindrome";
	else cout<<"Not palindrome";
	cout<<endl;
}

/*
td5
Example: if the original Stack contain [2,3,5,7,11] (where 11 is the top of stack), then the StackTop becomes: [11, 7, 5] and the StackBottom becomes: [3, 2].   
*/
void td5(){
	stack<int> s, s1, s2;//s1: stackTop, s2: stackBottom
	int val, n=11, n1; 

	for(int i=0; i<n; i++){
		val = rand()%100;
		s.push(val);
	}
	display(s);

	if(n%2==0)
		n1 = n/2;
	else
		n1 = n/2+1;

	while(!s.empty()){
		if(s1.size()<n1){
			s1.push(s.top());
			s.pop();
		}else{
			s2.push(s.top());
			s.pop();
		}				
	}
	display(s1);
	display(s2);
}
void series(int n, stack<float>& s){
	float u0=0.5, u1=1.5, ui;
	if(n==0) {s.push(u0); return; }

	s.push(u0);
	s.push(u1);
	for(int i=2; i<=n; i++){
		u1 = s.top(); s.pop();
		u0 = s.top(); s.pop();
		ui = 2*(i-1)*u1 - 1.5*(i-2)*u0;
		s.push(u0);s.push(u1);s.push(ui);
	}

}
void td6(){
	stack<float> s;
	int n=5;
	series(n,s);
	display(s);
	//write a function that returns only Un using stacks
}