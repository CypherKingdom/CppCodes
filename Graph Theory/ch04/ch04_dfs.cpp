#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

#define n 8
#define m 7
#define INF 99999

void displayPi(int []);
void displayD_F(int [], int []);

int dfs(int [][n],int [], int [], int []);
void dfsVisit(int [][n],int , int [], int [], int [], int&);

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
	int f[n];

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



	if(dfs(a,d,f,pi)>1)
		cout<<"Disconnected graph"<<endl;
	else cout<<"Not disconnected"<<endl;

	displayD_F(d,f);
	displayPi(pi);


	return 0;
}


void displayPi(int pi[]){
	cout <<"Predecessors Pi: ";
	for(int i=0; i<n; i++)
		cout<<pi[i]<<" ";
	cout<<endl;
}

void displayD_F(int d[], int f[]){
	cout <<"Times d/f: ";
	for(int i=0; i<n; i++)
		cout<<d[i]<<"/"<<f[i]<<" ";
	cout<<endl;
}

int dfs(int a[][n],int d[], int f[], int pi[]){
	int c=0;//nb of components
	int time=0;
	for(int i=0; i<n; i++){
		d[i]=0; f[i]=0;
		pi[i]=-1;
	}
	for(int i=0; i<n; i++)
		if(d[i]==0){
			dfsVisit(a,i,d,f,pi,time);
			c++;
		}
	return c;
}

void dfsVisit(int a[][n],int k, int d[], int f[], int pi[], int& time){
	d[k]=++time;
	for(int t=0; t<n; t++)
		if(a[k][t]!=0)
			if(d[t]==0){
				pi[t]=k;
				dfsVisit(a,t,d,f,pi,time);
			}
	f[k]=++time;
}
