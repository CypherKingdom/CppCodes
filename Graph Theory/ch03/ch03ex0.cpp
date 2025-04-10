/*
Write C++ functions that input from the user the adjacency matrices for: 
a simple graph, a simple weighted graph, a multigraph, a random simple graph.
*/

#include<iostream>
using namespace std;
#include<ctime>

#define n 4 //nb of vertices

/*
	int a[n][n]={0, 1, 1, 0,
				 1, 0, 1, 0,	
				 1, 1, 0, 1,
				 0, 0, 1, 0
				};
*/


void inSimpleG(int [][n]);
void inWeightedG(int [][n]);
void inMultigraph(int [][n]);
void inSimpleRandomG(int [][n],int);
void displayG(int [][n]);
void initMatrix(int [][n]);

int main(){
	int a[n][n]={0};
	int m;//nb of edges
	cout << "n=" << n << endl;
	cout << "Simple Graph" << endl;
	inSimpleG(a);
	displayG(a);

	cout << "Weighted Simple Graph" << endl;
	initMatrix(a);
	inWeightedG(a);
	displayG(a);

	cout << "Multigraph" << endl;
	initMatrix(a);
	inMultigraph(a);
	displayG(a);

	cout << "Input m : ";
	cin >> m;
	initMatrix(a);
	inSimpleRandomG(a,m);
	displayG(a);



	return 0;
}

void inSimpleG(int a[][n]){
	int u, v;
	cout<<"Input edges: u-v: "<<endl;
	while(cin>>u>>v){
		a[u][v]=1;
		a[v][u]=1;
	}
	cin.clear();
}

void inWeightedG(int a[][n]){
	int u, v, w;
	cout<<"Input edges: u-v-w: "<<endl;
	while(cin>>u>>v>>w){
		a[u][v]=w;
		a[v][u]=w;
	}
	cin.clear();
}


void inMultigraph(int a[][n]){
	int u, v;
	cout<<"Input edges: u-v: "<<endl;
	while(cin>>u>>v){
		a[u][v]+=1;
		a[v][u]+=1;
	}
	cin.clear();
}


void inSimpleRandomG(int a[][n], int m){
	int u, v;
	srand(time(0));
	for(int i=0; i<m ;){
		u = rand()%n;
		v = rand()%n;
		if(a[u][v]!=0 || u==v)continue;
		a[u][v] = 1;
		a[v][u] = 1;
		i++;
	}
}

void displayG(int a[][n]){
//Could change according to the type of graph
	cout<<"Graph is: "<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<" -> ";
		for(int j=0; j<n; j++){
			if(a[i][j]!=0)
				cout<<j<<" ";
		}
		cout<<endl;
	}
}

void initMatrix(int a[][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}