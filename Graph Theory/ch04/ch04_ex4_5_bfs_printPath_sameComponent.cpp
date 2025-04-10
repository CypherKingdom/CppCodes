#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

#define n 8
#define m 7
#define INF 99999

void bfs(int [][n], int, int [], int []);

void displayDistance(int []);
void displayPi(int []);


//Problem 4
void printPath(int a[][n], int s, int v, int pi[]);
void printPathIter(int a[][n], int s, int v, int pi[]);

//Problem 5
void sameComponent(int[][n], int, int);

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
	bfs(a,s,d,pi);

	displayDistance(d);
	displayPi(pi);

	cout<<"Input destination vertex: ";
	cin>>v;
	cout<<"Path recursive: ";
	printPath(a,s,v,pi);
	cout<<endl;
	printPathIter(a,s,v,pi);

	cout<<"Input u and v: "; cin>>u>>v;
	sameComponent(a,u,v);

	return 0;
}

void bfs(int a[][n], int s, int d[], int pi[]){
	int u;
	queue<int> q;//create FIFO queue
	for(int i=0; i<n; i++){
		d[i]=INF;
		pi[i]=-1;
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
					pi[v] = u;
					q.push(v);
				}
	}

}

void displayDistance(int d[]){
	cout <<"Distances: ";
	for(int i=0; i<n; i++)
		cout<<d[i]<<" ";
	cout<<endl;
}

void displayPi(int pi[]){
	cout <<"Predecessors Pi: ";
	for(int i=0; i<n; i++)
		cout<<pi[i]<<" ";
	cout<<endl;
}


void printPath(int a[][n], int s, int v, int pi[]){
	if(v == s)
		cout<<s<<" ";
	else
		if(pi[v]==-1)
			cout<<"No path from "<<s<<" to "<<v<<endl;
		else{
			printPath(a,s,pi[v],pi);
			cout<<v<<" ";
		}
}

void printPathIter(int a[][n], int s, int v, int pi[]){
	int path[n];
	int k=0;
	if(v == s){
		cout<<"Path: "<<s<<endl;
		return ;
	}

	path[0]=v;
	while(pi[v]!=-1){
		v=pi[v];
		path[++k]=v;
	}
	if(k==0){
		cout<<"No path"<<endl;
		return;
	}
	cout<<"Path: ";
	for(int i=k; i>=0; i--)
		cout<<path[i]<<" ";
	cout<<endl;
}

void sameComponent(int a[][n], int u, int v){
	int d[n], pi[n];

	bfs(a,u,d,pi);

	if(pi[v]==-1)
		cout<<"Not same component"<<endl;
	else
		cout<<"Same component"<<endl;

	if(u==pi[v])
		cout<<"Predecessor"<<endl;
	else
		cout<<"Not predecessor"<<endl;

}