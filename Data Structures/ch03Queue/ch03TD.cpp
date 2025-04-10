#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include<ctime>

void display(queue<int>);
void TD1();
void TD2();

int inOut(queue<int>&,int, int);
void TD3();

int timeInterval(int, int);
void TD4();

int main(){
	//TD1();
	//TD2();
	//TD4();
	TD3();
	return 0;
}
void display(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	cout<<"---"<<endl;
}
void TD1(){
	queue<int> q;
	int n=10, val;

	for(int i=0; i<n ;i++){
		val = rand()%10+1;
		q.push(val);
	}
	cout<<"Size: "<<q.size()<<endl;
	cout<<"Dequeue 3 elements"<<endl;
	for(int i=0; i<3; i++){
		if(q.empty())break;
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"Size: "<<q.size()<<endl;
	display(q);
	while(!q.empty())q.pop();
	cout<<"Size: "<<q.size()<<endl;
	display(q);
}

void TD2(){
	int N=12345, x;
	queue<int> q;

	while(N>0){
		x = N%10;
		N = N/10;
		q.push(x);
	}
	cout<<"Number in reverse order"<<endl;
	display(q);
}

int inOut(queue<int>& q,int n1, int n2){
	for(int i=0; i<n1; i++)
		q.push(0);
	for(int i=0; i<n2; i++){
		if(!q.empty()) q.pop();
	}
	return q.size();
}
void TD4(){
	queue<int> q;
	int n1, n2;
	int N=1000, size;
	float aver=0;
	srand(time(0));
	cout<<"n1 \t n2 \t qSize"<<endl;
	for(int i=0; i<N; i++){
		n1 = rand()%10;
		n2 = rand()%10;
		size=inOut(q,n1,n2);
		cout<<n1<<" \t"<<n2<<" \t"<<size<<endl;
		aver += size;
	}
	cout<<"Average size: "<<aver/N<<endl;
}

int timeInterval(int a, int b){
	return rand()%(b-a+1)+a;
}

void TD3(){
	const int MaxTime=50;
	const int MaxArrival=4;
	const int MaxService=4;
	int val, td=-1, ta=0;//td: time departure, ta: time arrival

	int wait = 0;//waiting time for each arrival
	float sumWait=0, maxWait=0;
	int nb=0;//nb of cutomer
	queue<int> q;

	srand(time(0));

	ta = timeInterval(1,MaxArrival);
	for(int t=0; t<MaxTime; t++){

		if(t == ta){
			if(q.empty())
				td = t + timeInterval(1,MaxService);

			q.push(t); 
			nb++;
			ta = t + timeInterval(1,MaxArrival); 	
		}

		 if(t == td){
			val = q.front();
			q.pop();
			wait = td - val; 
			if(!q.empty())
				td = t + timeInterval(1,MaxService);
		}
			
		sumWait+=wait;
		if(wait>maxWait)
			maxWait = wait;
		cout<<"t="<<t<<" QueueSize: "<<q.size();
		cout<<"; ta: "<<ta<<"; "
			<<"td: "<<td<<"; wait:"<<wait<<endl;
	}
	cout<<"nb of customers: "<<nb<<endl;
	cout<<"Average waiting time: "<<sumWait/nb<<endl;
	cout<<"Max waiting time: "<<maxWait<<endl;
}