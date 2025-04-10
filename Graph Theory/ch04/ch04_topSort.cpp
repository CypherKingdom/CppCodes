#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
using namespace std;

#define n 13
//#define m 7
#define INF 99999

struct Node { int i, f; };

void displayPi(int []);
void displayD_F(int [], int []);

//Method 0
int dfs(int[][n], int[], int[], int[]);
void dfsVisit(int[][n], int, int[], int[], int[], int&);
void topologicalSort(int[][n], int[]);
bool comp(Node& a, Node& b) { return a.f > b.f; }

//Method 1
int dfs1(int[][n], int[], int[], int[], int[]);
void dfsVisit1(int[][n], int, int[], int[], int[], int&, int[], int&);

//Method 2 using stack
int dfs2(int [][n],int [], int [], int [], int[]);
void dfsVisit2(int [][n],int , int [], int [], int [], int&,stack<int>&);

int main(){

	//int a[n][n]={0};
				//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2,
	int a[n][n]={ 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,//0
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//1
				  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//2
				  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,//3
		          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//4
				  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,//5
		          0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,//6
		          0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,//7
				  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,//8
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,//9
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//10
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//11
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0//12
					};
	int u, v, s;
	int d[n],pi[n],f[n];
	int topSort[n];

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

	//Method 0
	//topologicalSort(a, topSort);
	
	//Method 1;
	dfs1(a, d, f, pi, topSort);
	//Method 2
	//dfs2(a, d, f, pi, topSort);

	cout << "Topological Sort: ";
	for (int i = 0; i < n; i++) {
		cout << topSort[i] << " ";
	}
	cout << endl;



	return 0;
}


void displayPi(int pi[]){
	cout <<"Predecessors Pi: ";
	for(int i=0; i<n; i++)
		cout<<pi[i]<<" ";
	cout<<endl;
}

void displayD_F(int d[], int f[]){
	cout <<"i: d/f";
	for(int i=0; i<n; i++)
		cout<<i<<": "<<d[i]<<"/"<<f[i]<<endl;
	cout<<endl;
}

//Method 0
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


void topologicalSort(int a[][n], int topSort[]) {
	int d[n], f[n], pi[n];
	Node node[n];
	dfs(a, d, f, pi);
	for (int i = 0; i < n; i++)
	{
		node[i].f = f[i];
		node[i].i = i;
	}
	sort(node, node+n,comp);
	for (int i = 0; i < n; i++)
	{
		topSort[i] = node[i].i;
	}
}

//Method 1
int dfs1(int a[][n], int d[], int f[], int pi[], int topSort[]) {
	int c = 0;//nb of components
	int time = 0, count = n;
	for (int i = 0; i<n; i++) {
		d[i] = 0; f[i] = 0;
		pi[i] = -1; topSort[i] = -1;
	}
	for (int i = 0; i<n; i++)
		if (d[i] == 0) {
			dfsVisit1(a, i, d, f, pi, time, topSort, count);
			c++;
		}
	return c;
}

void dfsVisit1(int a[][n], int k, int d[], int f[], int pi[], int& time, int topSort[], int&count) {
	d[k] = ++time;
	for (int t = 0; t<n; t++)
		if (a[k][t] != 0)
			if (d[t] == 0) {
				pi[t] = k;
				dfsVisit1(a, t, d, f, pi, time, topSort, count);
			}
	f[k] = ++time;
	count--;
	topSort[count] = k;
}






//Method 2 using stack
int dfs2(int a[][n], int d[], int f[], int pi[], int topSort[]) {
	int c = 0;//nb of components
	int time = 0;
	stack<int> s;
	int v;
	for (int i = 0; i<n; i++) {
		d[i] = 0; f[i] = 0;
		pi[i] = -1;
	}
	for (int i = 0; i<n; i++)
		if (d[i] == 0) {
			dfsVisit2(a, i, d, f, pi, time, s);
			c++;
		}
	v = 0;
	while (!s.empty()) {
		topSort[v++] = s.top();
		s.pop();
	}
	return c;
}

void dfsVisit2(int a[][n], int k, int d[], int f[], int pi[], int& time, stack<int>& s) {
	d[k] = ++time;
	for (int t = 0; t<n; t++)
		if (a[k][t] != 0)
			if (d[t] == 0) {
				pi[t] = k;
				dfsVisit2(a, t, d, f, pi, time, s);
			}
	f[k] = ++time;
	s.push(k);
}
