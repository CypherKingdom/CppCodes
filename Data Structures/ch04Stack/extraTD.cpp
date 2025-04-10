/*
Question: (write efficient code)
1. Sort a stack using stacks
2. Remove duplication from a sorted stack
3. Consider 2 sorted stacks (without duplication)
a. find their intersection 
b. find their union (with no duplication in the result)
c. find their complement
*/

#include<iostream>
using namespace std;
#include <ctime>
#include<stack>

void sortStack(stack<int>&);
void removeDup(stack<int>&);
void intersection(stack<int>,stack<int>,stack<int>&);
void Union(stack<int>,stack<int>,stack<int>&);
void complement(stack<int>,stack<int>,stack<int>&);

void driver1();
void driver2();


void display(stack<int>);

int main(){
	//driver1();
	driver2();

	return 0;
}

void driver1(){
	int n=20, val;
	stack<int> s;
	for(int i=0; i<n; i++){
		val = rand()%100;
		s.push(val);
	}
	display(s);
	sortStack(s);
	display(s);

	removeDup(s);
	display(s);
}
void driver2(){
	int n1=20, n2=25, val;
	stack<int> s1, s2, inter, uni, comp;
	srand(time(0));
	for(int i=0; i<n1; i++){
		val = rand()%50;
		s1.push(val);
	}
	for(int i=0; i<n2; i++){
		val = rand()%50;
		s2.push(val);
	}
	
	sortStack(s1);
	removeDup(s1);
	display(s1);
	sortStack(s2);
	removeDup(s2);
	display(s2);
	intersection(s1,s2,inter);
	Union(s1,s2,uni);
	complement(s1,s2,comp);
	cout<<"Intersection"<<endl;
	display(inter);
	cout<<"Union"<<endl;
	display(uni);
	cout<<"Complement"<<endl;
	display(comp);
}

void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
//not optimized method
void sortStack(stack<int>& s){
	stack<int> s1, s2;
	int n = s.size();
	if(s.empty()) return;

	for(int i=1; i<=n-1 ; i++){
		s1.push(s.top());
		s.pop();
		while(!s.empty()){
			if(s.top()<s1.top()){
				s2.push(s1.top());
				s1.pop();
				s1.push(s.top());
			}else{
				s2.push(s.top());		
			}
			s.pop();
		}
		while(!s2.empty()){
			s.push(s2.top());
			s2.pop();
		}
	}
	s = s1;

}
void removeDup(stack<int>& s){
	stack<int> s1;
	if(s.empty()) return;
	s1.push(s.top());
	while(!s.empty()){
		if(s.top()!=s1.top()){
			s1.push(s.top());
		}
		s.pop();
	}
	while(!s1.empty()){
		s.push(s1.top());
		s1.pop();
	}

}
void intersection(stack<int> s1,stack<int> s2,stack<int>& s){
	while(!s1.empty() && !s2.empty()){
		if(s1.top()>s2.top()){		
			s1.pop();
		}else if(s1.top()<s2.top()){
			s2.pop();
		}else{ 
			s.push(s1.top());
			s1.pop();
			s2.pop();
		}
	}
}
void Union(stack<int> s1,stack<int> s2,stack<int>& s){
	while(!s1.empty() && !s2.empty()){
		if(s1.top()>s2.top()){
			s.push(s1.top());
			s1.pop();
		}else if(s1.top()<s2.top()){
			s.push(s2.top());
			s2.pop();
		}else{ 
			s.push(s1.top());
			s1.pop();
			s2.pop();
		}
	}	
	while(!s1.empty()){
		s.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		s.push(s2.top());
		s2.pop();
	}
}
void complement(stack<int>s1,stack<int>s2,stack<int>&s){
	while(!s1.empty()&&!s2.empty()){
		if(s1.top()>s2.top()){
			s.push(s1.top());
			s1.pop();
		}else if(s1.top()<s2.top()){
			s.push(s2.top());
			s2.pop();
		}else{
			s1.pop();
			s2.pop();
		}
	}
	while(!s1.empty()){
		s.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		s.push(s2.top());
		s2.pop();
	}
}