#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

#define n 8
#define m 7
#define INF 99999

//Problem 2
bool isBipartite(int a[][n], int , int []);

int main(){

	//int a[n][n]={0};
	int a[n][n]={ 0, 1, 0, 0, 1, 0, 0, 0,
				  1, 0, 0, 0, 0, 1, 0, 0,
				  0, 0, 0, 1, 0, 1, 1, 0,
				  0, 0, 1, 0, 0, 0, 1, 1,
				  1, 0, 0, 0, 0, 0, 0, 0,
				  0, 1, 1, 0, 0, 0, 1, 0,
				  0, 0, 1, 1, 0, 1, 0, 1,
				  0, 0, 0, 1, 0, 0, 1, 0
					};
	int u, v, s;
	int d[n];
	int pi[n];

	/*
	//Random simple graph generation//
	srand(time(0));
	int i=0;
	while(i<m){
		u = rand()%n;
		do{ v = rand()%n;}while(u==v);
		if(a[u][v] == 1) continue;
		a[u][v] = 1;
		a[v][u] = 1;
		i++;
	}
	*/
	//Display adjacency 
	cout<<"Adjacency matrix"<<endl;
	cout<<"vertex: neighbors"<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<": ";
		for(int j=0; j<n; j++)
			if(a[i][j]!=0)
				cout<<j<<" ";
		cout<<endl;	
	}

	cout<<"Input root s for bfs: "; cin>>s;

	if(isBipartite(a,s,d))
		cout<<"Bipartite"<<endl;
	else
		cout<<"Not Bipartite"<<endl;


	return 0;
}

bool isBipartite(int a[][n], int s, int d[]){
	int u;
	queue<int> q;//create FIFO queue
	for(int i=0; i<n; i++)
		d[i]=INF;

	d[s]=0;
	q.push(s);//input s to the end of queue
	while(!q.empty()){
		u = q.front();//output the value in front of queu
		q.pop();//remove the front of queue from queue
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(d[v]==INF){
					d[v]=d[u]+1;
					q.push(v);
				}else if(d[u]==d[v])
					//v: discovered and has same level as u
					//it exists an odd cycle
					return false;
	}
	return true;
}
