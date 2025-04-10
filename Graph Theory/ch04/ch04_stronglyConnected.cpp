#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
using namespace std;

#define n 13
//#define m 7
#define INF 99999
struct Node { int i, f; };

int dfs(int[][n], int[], int[], int[], int[],int[]);
void dfsVisit(int[][n], int, int[], int[], int[], int&,int[],int);
void topologicalSort(int[], int[]);
bool comp(Node& a, Node& b) { return a.f > b.f; }

void reverseDigraph(int [][n], int [][n]);
int SrongComponents(int [][n], int []);

void displayPi(int []);
void displayD_F(int [], int []);


int main(){

	//int a[n][n]={0};
				//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2,
	int a[n][n]={ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,//0
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//1
				  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//2
				  0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,//3
		          0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//4
				  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,//5
		          1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0,//6
		          0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,//7
				  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,//8
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,//9
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//10
				  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,//11
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0//12
					};
	int A[n][n] = { 0 };
	int u, v, s;
	int d[n], pi[n], f[n];
	int topSort[n];
	int id[n], nbc;

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

	nbc = SrongComponents(a,id);
	cout << "Strong Components: vertices" << endl;
	for (int k = 0; k < nbc; k++)
	{
		cout << k << ": ";
		for (int i = 0; i < n; i++) {
			if (id[i] == k)
				cout << i << " ";
		}
		cout << endl;
	}
	/*
	cout << "i id" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << id[i] << endl;
	}*/

	return 0;
}
//Kosaraju-Sharir algorithm
int SrongComponents(int a[][n], int id[]) {
	int A[n][n] = { 0 };
	int d[n], f[n],pi[n], topSort[n];
	int nbc;
	for (int i = 0; i < n; i++) topSort[i] = i;
	reverseDigraph(a, A);
	dfs(A, d, f, pi, topSort,id);
	topologicalSort(f, topSort);
	nbc = dfs(a, d, f, pi, topSort,id);
	return nbc;
}

void reverseDigraph(int a[][n], int A[][n]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = a[j][i];
		}
	}
}

int dfs(int a[][n], int d[], int f[], int pi[], int topSort[],int id[]) {
	int c = 0;//nb of components
	int time = 0, v;
	for (int i = 0; i<n; i++) {
		d[i] = 0; f[i] = 0;
		pi[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		v = topSort[i];
		if (d[v] == 0) {
			dfsVisit(a, v, d, f, pi, time,id,c);
			c++;
		}
	}
	return c;
}

void dfsVisit(int a[][n], int k, int d[], int f[], int pi[], int& time, int id[], int c) {
	d[k] = ++time;
	id[k] = c;
	for (int t = 0; t<n; t++)
		if (a[k][t] != 0)
			if (d[t] == 0) {
				pi[t] = k;
				dfsVisit(a, t, d, f, pi, time,id,c);
			}
	f[k] = ++time;
}


void topologicalSort(int f[], int topSort[]) {
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


