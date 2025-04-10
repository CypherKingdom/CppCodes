#include<iostream>
using namespace std;
#include<stack>

void infix2postfix(char*,char*);
int priority(char);

float evalExpr(char* , int*);
bool op(char );
float value(char , int*);

int main(){
	char* p = "(A+(B/C-(D*E^F)+G)*H)";//"(A+(B/C-(D*E/F)+G)*H)";//
	char *q = new char[strlen(p)];
	infix2postfix(p,q);
	cout<<q<<endl;

	int a[]={6, 2, 5, 8, 4};//A, B, C, D, E//value of variables
	char* postfix = "AB+C*DE/-" ;
	cout<<postfix<<"="<<evalExpr(postfix,a)<<endl;

	return 0;
}

int priority(char c){
	switch(c){
	case '(': return 1;
	case ')': return 2;
	case '+':
	case '-': return 3;
	case '*':
	case '/':
	case '%': return 4;
	case '^': return 5;
	default: return 0;
	}
}


void infix2postfix(char*p,char*q){
	stack<char> s;
	int i=0, k=0;
	while(p[i]!='\0'){
		switch(priority(p[i])){
		case 1 : s.push(p[i]); break;
		case 2 : 
				while(s.top()!='('){
					q[k++]=s.top();
					s.pop();
				}
				s.pop();
				break;
		case 3 : 
		case 4 :
		case 5 :
				while(priority(p[i])<=priority(s.top())){
					q[k++]=s.top();
					s.pop();	
				}
				s.push(p[i]);
				break;
		default: q[k++]=p[i]; break;
		}	
		i++;
	}
	q[k]='\0';

}

bool op(char c){
	switch(c){
	case '+':
	case '-': 
	case '*':
	case '/':
	case '%':  return true;
	default: return false;
	}
}

float value(char c, int*a){
	return a[c-'A'];
}

float evalExpr(char* q, int*a){
	stack<float> s;
	float x,y,res;
	int i=0;
	while(q[i]!='\0'){
		if(!op(q[i])){
			s.push(value(q[i],a));
		}else{
			y = s.top(); s.pop();
			x = s.top(); s.pop();
			switch(q[i]){
			case '+': res = x+y; break;
			case '-': res = x-y; break;
			case '*': res = x*y; break;
			case '/': res = x/y; break;
			case '%': res = int(x)%int(y); break;
			case '^': res = pow(x,y); break;
			}
			s.push(res);
		}
		i++;
	}
	res = s.top();
	s.pop();
	return res;
}

