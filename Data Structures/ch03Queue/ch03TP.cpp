#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include<ctime>

void display(queue<char>);
void display(queue<int>);
void TP1();
void TP2();
void TP3();

int main(){
	TP1();
	//TP2();
	//TP3();
	return 0;
}
void display(queue<char> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	cout<<"---"<<endl;
}
void display(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	cout<<"---"<<endl;
}
void TP1(){
	queue<char> q1;
	queue<char> q2;//queue<char,list<char>> q2;
	char *str = "What a beautiful world!";
	int i=0;
	while(str[i]!='\0'){
		if(str[i]=='a' || str[i]=='e' ||str[i]=='i'||  
			str[i]=='o'|| str[i]=='u' || str[i]=='y')
			q1.push(str[i]);
		else
			if(str[i]>'A' && str[i]<= 'z')
				q2.push(str[i]);
		i++;
	}
	cout<<"q1: "<<endl; display(q1);
	cout<<"q2: "<<endl; display(q2);
}

void TP2(){
	queue<int> q[10];
	int N=200, val, k;
	srand(time(0));

	for(int i=0; i<N; i++){
		val = rand()%100;
		k = val/10;
		q[k].push(val);
	}
	for(int i=0; i<10; i++){
		display(q[i]);
	}
}

void TP3(){
	char *str="abc*cba";
	bool correct = true;
	queue<char> q;
	int len = strlen(str);
	int i=0;
	while(str[i]!='*'){
		q.push(str[i]);
		i++;
	}
	if(str[i]=='\0') {correct = false; cout<<"empty str after *"<<endl;}
	display(q);
	i = len-1;
	while(str[i]!='*'){
		//cout<<q.front()<<" "<<str[i]<<endl;
		if(q.front()!=str[i] || q.empty()){
			correct = false;
			break;
		}
		q.pop();
		i--;
	}
	display(q);
	if(!q.empty()) {correct = false; cout<<"q not empty"<<endl;}

	if(correct)
		cout<<"True expression"<<endl;
	else
		cout<<"Bad expression"<<endl;
}