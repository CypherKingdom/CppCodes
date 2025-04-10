#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

#define n 8
#define m 7
#define INF 99999

//Problem 3
struct Node {
		int dist;
		int v;
	} ;
Node distMax(int [][n], int , int []);
int diameter1(int [][n]);
int diameter2(int [][n]);

int main(){

	int d[n];
	int A[n][n]={ 0, 1, 0, 0, 0, 0, 0, 0,
				  1, 0, 1, 0, 1, 0, 0, 0,
				  0, 1, 0, 1, 0, 0, 0, 0,
				  0, 0, 1, 0, 0, 0, 0, 0,
				  0, 1, 0, 0, 0, 1, 1, 0,
				  0, 0, 0, 0, 1, 0, 0, 0,
				  0, 0, 0, 0, 1, 0, 0, 1,
				  0, 0, 0, 0, 0, 0, 1, 0
	};//tree

	  //Display adjacency 
	cout<<"Adjacency matrix"<<endl;
	cout<<"vertex: neighbors"<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<": ";
		for(int j=0; j<n; j++)
			if(A[i][j]!=0)
				cout<<j<<" ";
		cout<<endl;	
	}

	cout<<"diameter1: "<<diameter1(A)<<endl;
	cout<<"diameter2: "<<diameter2(A)<<endl;

	return 0;
}

Node distMax(int a[][n], int s, int d[]){
	Node nodeMax;
	int u, dmax=0, vmax=s;

	queue<int> q;//create FIFO queue
	for(int i=0; i<n; i++){
		d[i]=INF;
	}
	d[s]=0;
	q.push(s);//input s to the end of queue
	while(!q.empty()){
		u = q.front();//output the value in front of queu
		q.pop();//remove the front of queue from queue
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(d[v]==INF){
					d[v]=d[u]+1;
					if(d[v]>dmax){
						dmax=d[v];
						vmax=v;
					}
					q.push(v);
				}
	}
	nodeMax.dist=dmax;
	nodeMax.v=vmax;
	return nodeMax;
}

int diameter1(int a[][n]){
	Node nodeMax;
	int diam=0;
	int d[n];
	for(int i=0; i<n; i++){
		nodeMax=distMax(a,i,d);
		if(nodeMax.dist>diam)
			diam = nodeMax.dist;
	}
	return diam;
}

int diameter2(int a[][n]){
	Node nodeMax;
	int d[n];
	nodeMax=distMax(a,0,d);
	nodeMax=distMax(a,nodeMax.v,d);
	return nodeMax.dist;
}
