#include<iostream>
using namespace std;
#include <vector>
#include <queue>
#include<functional>
//#include<set>
#define n 8
#define INF 99999

typedef pair<int,int> node;//<distance,vertex>

struct Node { int i, f; };

int dfs(int[][n], int[], int[], int[]);
void dfsVisit(int[][n], int, int[], int[], int[], int&);
void topologicalSort(int [], int[]);
bool comp(Node& a, Node& b) { return a.f > b.f; }

void dagSP(int [][n], int, int [], int []);
void dagLP(int[][n], int, int[], int[]);
void dagLP2(int[][n], int, int[], int[]);

void displayGraph(int [][n]);
void displayDistPi(int [], int[]);

//void dijkstra(int[][n], int, int[], int[]);

int main(){
				  //0, 1, 2, 3, 4, 5, 6, 7
	int a[n][n]={	0, 0, 26, 0, 0, 0, 0, 0,//0
					0, 0, 0, 29, 0, 0, 0, 0, //1
					0, 0, 0, 0, 0, 0, 0, 0, //2
					0, 0, 0, 0, 0, 0, 52, 39, //3
					38, 0, 0, 0, 0, 0, 0, 37,//4
					0, 32, 0, 0, 0, 35, 0, 28,//5
					58, 0, 40, 0, 93, 0, 0, 0,//6
					0, 0, 34, 0, 0, 0, 0, 0//7
	};

	int s;
	int d[n], pi[n];


	cout<<"Input root vertex s: "; cin>>s;
	dagLP2(a,s,d,pi);
	displayDistPi(d,pi);

	return 0;
}

int dfs(int a[][n], int d[], int f[], int pi[]) {
	int c = 0;//nb of components
	int time = 0;
	for (int i = 0; i<n; i++) {
		d[i] = 0; f[i] = 0;
		pi[i] = -1;
	}
	for (int i = 0; i<n; i++)
		if (d[i] == 0) {
			dfsVisit(a, i, d, f, pi, time);
			c++;
		}
	return c;
}

void dfsVisit(int a[][n], int k, int d[], int f[], int pi[], int& time) {
	d[k] = ++time;
	for (int t = 0; t<n; t++)
		if (a[k][t] != 0)
			if (d[t] == 0) {
				pi[t] = k;
				dfsVisit(a, t, d, f, pi, time);
			}
	f[k] = ++time;
}


void topologicalSort(int f[], int topSort[]) {
	int d[n], pi[n];
	Node node[n];
	for (int i = 0; i < n; i++)
	{
		node[i].f = f[i];
		node[i].i = i;
	}
	sort(node, node + n, comp);
	for (int i = 0; i < n; i++)
	{
		topSort[i] = node[i].i;
	}
}

void dagSP(int a[][n], int s, int d[], int pi[]) {
	int D[n], Pi[n], f[n], topSort[n];
	int u, v, w;
	dfs(a, D, f, Pi);
	topologicalSort(f, topSort);
	for (int i = 0; i < n; i++) {
		if (i != s)
			d[i] = INF;
		else
			d[s] = 0;
		pi[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		u = topSort[i];
		for (int v = 0; v < n; v++) {
			if (a[u][v] != 0)
				if (d[v] > d[u] + a[u][v]) {
					d[v] = d[u] + a[u][v];
					pi[v] = u;
				}
		}
	}
}

void dagLP(int a[][n], int s, int d[], int pi[]) {
	int D[n], Pi[n], f[n], topSort[n];
	int u, v, w;
	dfs(a, D, f, Pi);
	topologicalSort(f, topSort);
	for (int i = 0; i < n; i++) {
		if (i != s)
			d[i] = -INF;
		else
			d[s] = 0;
		pi[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		u = topSort[i];
		for (int v = 0; v < n; v++) {
			if (a[u][v] != 0)
				if (d[v] < d[u] + a[u][v]) {
					d[v] = d[u] + a[u][v];
					pi[v] = u;
				}
		}
	}
}

//Method 2
void dagLP2(int a[][n], int s, int d[], int pi[]) {
	int A[n][n], D[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = -a[i][j];
		}
	}
	dagSP(A,s,D,pi);
	for (int i = 0; i < n; i++)
	{
		d[i] = -D[i];
	}
}



void displayGraph(int a[][n]){
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
	cout<<"----"<<endl;
}

void displayDistPi(int d[], int pi[]){
	cout <<"i: pi dist.: "<<endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<pi[i]<<" "<<d[i]<<endl;
	cout<<"----"<<endl;
}

/*
void dijkstra(int a[][n], int s, int d[], int pi[]) {
	priority_queue< node, vector<node>, greater<node> > q;
	int u;
	int S[n] = { 0 };

	for (int i = 0; i<n; i++) {
		if (i != s)
			d[i] = INF;
		else
			d[s] = 0;
		pi[i] = -1;
		q.push(make_pair(d[i], i));
	}

	while (!q.empty()) {
		u = q.top().second;
		q.pop();
		if (S[u] == 1) continue;
		else S[u] = 1;
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (d[v]>d[u] + a[u][v]) {
					d[v] = d[u] + a[u][v];
					pi[v] = u;
					q.push(make_pair(d[v], v));
				}
	}

}
*/
/*
8 13 5

5 4 35
4 7 37
5 7 28
5 1 32
4 0 38
0 2 26
3 7 39
1 3 29
7 2 34
6 2 40
3 6 52
6 0 58
6 4 93
*/