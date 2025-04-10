#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

#define n 13
//#define m 7
#define INF 99999

void displayPi(int []);
void displayD_F(int [], int []);

int dfs(int [][n],int [], int [], int [], int []);
void dfsVisit(int [][n],int , int [], int [], int [], int&, int [], int &);
void displayComponents(int [], int);


void dfsVisit2(int [][n], int, int[], int[]);
bool isPath2(int [][n], int, int, int[]);
bool isPath(int [], int, int , int);
void displayPath(int[], int, int);

int main(){

	//int a[n][n]={0};
				  //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2,
	int a[n][n] = { 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,//0
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//1
					1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//2
					0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,//3
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//4
					0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,//5
					0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,//6
					0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,//7
					0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,//8
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,//9
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//10
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//11
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0//12
	};
	int u, v, s;
	int id[n] = { 0 }, nbc;
	int d[n], pi[n], f[n];

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

	nbc = dfs(a, d, f, pi, id);
	cout << "Nb of components: " << nbc << endl;
	displayComponents(id, nbc);
	displayPi(pi);
	displayD_F(d,f);

	cout << "Input two vertices: "; cin >> u >> v;
	//we cannot use isPath(id,nbc,u,v) here because the graph is a digraph

	if(isPath2(a,u,v,pi))cout << "There is a path" << endl;
	else cout << "No path" << endl;
	cout << "Path between u and v: " << endl;
	//displayPath needs to use the pi given from isPath2, otherwise the result may be false
	displayPath(pi, u, v);
	cout << endl;

	return 0;
}


void displayPi(int pi[]){
	cout << "i: Pi" << endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<pi[i]<<endl;
}

void displayD_F(int d[], int f[]){
	cout << "i: d/f " << endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<d[i]<<"/"<<f[i]<<endl;
}

void displayComponents(int id[], int nbc) {

	cout << "Display id: ";
	for (int i = 0; i < n; i++) {
		cout << id[i] << " ";
	}
	cout << endl;
	cout << "Component: vertices" << endl;
	for (int k = 0; k < nbc; k++)
	{
		cout << k << ": ";
		for (int i = 0; i < n; i++) {
			if (id[i] == k)
				cout << i << " ";
		}
		cout << endl;
	}
}

int dfs(int a[][n],int d[], int f[], int pi[], int id[]){
	int c=0;//nb of components
	int time=0;
	for(int i=0; i<n; i++){
		d[i]=0; f[i]=0;
		pi[i] = -1; id[i] = 0;
	}
	for(int i=0; i<n; i++)
		if(d[i]==0){
			dfsVisit(a,i,d,f,pi,time, id, c);
			c++;
		}
	return c;
}
//Output also id[] array that specifies the component id to each vertex.
void dfsVisit(int a[][n],int k, int d[], int f[], int pi[], int& time, int id[], int& c){
	d[k]=++time;
	id[k] = c;
	for(int t=0; t<n; t++)
		if(a[k][t]!=0)
			if(d[t]==0){
				pi[t]=k;
				dfsVisit(a,t,d,f,pi,time,id,c);
			}
	f[k]=++time;
}

//This works only if the graph is undirected.
bool isPath(int id[], int nbc, int u, int v) {
	int c;
	for (int k = 0; k < nbc; k++)
	{
		c = 0;
		for (int i = 0; i < n; i++) {
			if (id[i] == k) {
				if (i == u) c++;
				if (i == v) c++;
			}
		}
		if (c == 2) return true;		
	}
	return false;
}

bool isPath2(int a[][n], int u, int v, int pi[]) {
	int d[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		pi[i] = -1;
	}
	dfsVisit2(a,u,d,pi);
	//for (int i = 0; i < n; i++)cout << i<<"/"<<d[i]<<"/"<<pi[i] << " ";
	if (pi[v] == -1) return false;
	else return true;

}

void displayPath(int pi[], int s, int v) {
	if (v == s) return;
	if (pi[v] == -1) {
		cout << "no path: blocked at vertex " <<v<< endl; return;
	}
	else{
		displayPath(pi, s, pi[v]);
		cout << v << " ";
	}
}

void dfsVisit2(int a[][n], int u, int d[], int pi[]) {
	d[u] = 1;
	for (int t = 0; t<n; t++)
		if (a[u][t] != 0)
			if (d[t] == 0) {
				pi[t] = u;
				dfsVisit2(a, t, d, pi);
			}
}