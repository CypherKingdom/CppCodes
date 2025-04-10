#include<iostream>
using namespace std;
#include<stack>
#include<ctime>
#include<algorithm>
#include<functional>


void display(stack<int>);
void display(stack<char>);
int intersection(stack<int>&,stack<int>&,int*);
void tp1();

void split(stack<char>,stack<char>&,stack<char>&);
void tp2();

bool isFullyParenthesized(char*);
void tp3();

float evalExpr(char* , int*);
int op(char );
float value(char , int*);
float operation(char , float , float );
void tp4();

int min(stack<int> s);
void tp5();


int main(){
	//tp1();
	//tp2();
	//tp3();
	tp4();
	//tp5();

	return 0;
}
void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
void display(stack<char> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

int intersection(stack<int>&s1,stack<int>&s2,int*a){
	stack<int> s;
	int k;
	while(!s1.empty() && !s2.empty() ){
		if(s1.top() == s2.top()){
			s.push(s1.top());
			s1.pop();
			s2.pop();
		}else if(s1.top() > s2.top()){
			s1.pop();
		}else
			s2.pop();
	}
	k=0;
	while(!s.empty()){
		a[k++] = s.top();
		s.pop();
	}
	return k;
}

void tp1(){
	stack<int> s1, s2;
	int n1=10, n2=7;
	int *a1 = new int[n1];
	int *a2 = new int[n2];
	int n=n1+n2;
	int *a = new int[n];

	srand(time(0));
	for(int i=0; i<n1; i++)
		a1[i] = rand()%20;
	
	for(int i=0; i<n2; i++)
		a2[i] = rand()%20;
	
	sort(a1,a1+n1);
	sort(a2,a2+n2);
	//use sort(a1,a1+n1),greater<int>()) for descending order
	for(int i=0; i<n1; i++)
		s1.push(a1[i]);
	for(int i=0; i<n2; i++)
		s2.push(a2[i]);
	display(s1);
	display(s2);
	n = intersection(s1,s2,a);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void split(stack<char>s,stack<char>&s1,stack<char>&s2){
	while(!s.empty()){
		if(s.top()=='a' || s.top()=='e' || s.top()=='i' ||
			s.top()=='o' || s.top()=='u' ||s.top()=='y')
			s1.push(s.top());
		else if(s.top()>'a' && s.top()<='z')
			s2.push(s.top());
		s.pop();
	}
}
void tp2(){
	stack<char> s, s1, s2;
	char *str = "what a beautiful world";
	int i=0;
	while(str[i]!='\0'){
		s.push(str[i]);
		i++;
	}
	split(s,s1,s2);
	display(s);
	display(s1);
	display(s2);
}

bool isFullyParenthesized(char*expr){
	stack<char> s;
	char c;

	for(int i=0; expr[i]!='\0'; i++){
		if(expr[i]=='(')
			s.push(expr[i]);
		else
			if(expr[i]==')'){
				if(s.empty()) return false;
				s.pop();	
			}
	}
	if(s.empty())
		return true;
	else
		return false;
}

void tp3(){
	char *expr = "(A+(B/C-(D*E^F)+G)*H)";
	if(isFullyParenthesized(expr))
		cout<<"Completly parenthesized expression"<<endl;
	else
		cout<<"NOT Completly parenthesized expression"<<endl;
}

int op(char c){
	switch(c){
	case '+':
	case '-': 
	case '*':
	case '/':
	case '%':  return 1;
	case '(': return 2;
	case ')': return 3;
	default: return 4;
	}
}

float value(char c, int*a){
	return a[c-'A'];
}

float operation(char c, float x1, float x2){
	switch(c){
		case '+': return x1+x2;
		case '-': return x1-x2;
		case '*': return x1*x2;
		case '/': return x1/x2;
		case '%': return int(x1)%int(x2);
		default: return -99999;
	}
}

float evalExpr(char*expr, int* a){
	stack<float> s1;//values
	stack<char> s2;//operators
	char c;
	float x1, x2, res;
	for(int i=0; expr[i]!='\0'; i++){
		switch(op(expr[i])){
		case 1:  s2.push(expr[i]); break; 
		case 2:	 break;
		case 3: x2 = s1.top(); s1.pop();
				x1 = s1.top(); s1.pop();
				c = s2.top();  s2.pop();
				res = operation(c,x1,x2);
				s1.push(res); break;
		default: s1.push(value(expr[i],a)); break;
		}

	}
	res = s1.top();
	s1.pop();
	return res;
}


void tp4(){
	int a[]={6, 2, 10};//A, B, C//value of variables
	int A, B, C;
	//char *expr = "(((A*B)+(B*C))-C)";
	char *expr = "((((A*B)-(B*C))+(B*(A+B)))+(((A*B)*(B-C))+C))";
	A = a[0]; B=a[1]; C = a[2];
	//cout<<(((A*B)+(B*C))-C)<<endl;
	cout<<((((A*B)-(B*C))+(B*(A+B)))+(((A*B)*(B-C))+C))<<endl;
	cout<<evalExpr(expr,a)<<endl;
}
int min(stack<int> s){
	stack<int> s1;
	int min;
	if(s.empty())return -1;

	min = s.top();
	while(!s.empty()){
		if(s.top()<min)
			min = s.top();
		s.pop();
	}
	return min;
}
/*
int min(stack<int> s){
	stack<int> s1;
	if(s.empty()) return -1;
	
	s1.push(s.top());
	while(!s.empty()){
		if(s.top()<s1.top()){
			s1.pop();
			s1.push(s.top());
		}
		s.pop();
	}
	return s1.top();
}
*/
void tp5(){
	int n=10, val;
	stack<int> s;
	for(int i=0; i<n; i++){
		val = rand()%100;
		s.push(val);
	}
	display(s);
	cout<<"min = "<<min(s)<<endl;
}