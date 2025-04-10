/*
Explanation about some useful codes used in this program.
---
1. Example: using pair class 
pair<int, int> p;//define a pair of 2 integers, similar to a structure with 2 int.
p.first = 3; p.second = 5; //the first and second int of the pair, first and second are predefined. Like a struct with 2 int variables (identified by first and second)
cout<<p.second<<“ “<<p.first<<endl;

2. Example: make_pair()
int x=2, y=6;
p = make_pair(x,y); //create a pair, and assign the value x to first and value y to second. So p.first is equal to x, and p.second equal to y.

3. Typedef : define a new type, used to simplify things
typedef pair<int,int> node;// so we can write just “node” instead of writing pair<int,int>, the 2 integers will correspond to key and vertex.

4. Priority Queue in C++ STL (Standard Template Library)
#include<queue>
#include<functional> //defines the term “greater” in priority_queue

-priority_queue<node> q; //define a max-priority queue containing pairs of integers

-priority_queue<node,vector<node>,greater<node>> q; //define a min-priority queue (corresponds to our case). node: equivalent to pair<int,int>.  greater<node>: used to specify that this priority queue is a min priority queue. vector<node> : specify that the priority queue is implemented using a vector which is based on dynamic arrays.

-q.push(make_pair(key[i], i));//input to the q a pair of integers: the key of vertex i and the vertex i. make_pair creates the pair and then it is pushed to q. key[i] should be before the i, so the min priority queue is based on key, i.e. the pairs in q are like sorted in increasing order based on key.
-
q.top(); return the pair of the top of q, i.e. the element with the min key
-
q.top().second;// returns the second element of pair situated at the top of q, i.e. returns the vertex of the min key. q.top().first returns the min key of q.

-q.pop();//remove the element of the top from the q.

*/

#include<iostream>
#include<functional>
#include<queue>

//#include<set>
using namespace std;

#define n 9
#define INF 99999

typedef pair<int,int> node;//<key,vertex>
//Method 0
void prim(int [][n], int, int [], int []);
//Method1
void prim1(int[][n], int, int[], int[]);
//Method2
//void prim2(int [][n], int, int [], int []);


void displayGraph(int [][n]);
void displayKeyPi(int [], int[]);
void displayMST(int[], int[], int);

int main(){
				//0, 1, 2, 3, 4, 5, 6, 7, 8, vertices
	int a[n][n]={ 0, 4, 0, 0, 0, 0, 0, 8, 0,//0
				  4, 0, 8, 0, 0, 0, 0, 11, 0,//1
				  0, 8, 0, 7, 0, 4, 0, 0, 2,//2
				  0, 0, 7, 0, 9, 14, 0, 0, 0,//3
				  0, 0, 0, 9, 0, 10, 0, 0, 0,//4
				  0, 0, 4, 14, 10, 0, 2, 0, 0,//5
				  0, 0, 0, 0, 0, 2, 0, 1, 6,//6
				  8, 11, 0, 0, 0, 0, 1, 0, 7,//7
				  0, 0, 2, 0, 0, 0, 6, 7, 0//8
					};
	int u, v, r;
	int key[n];
	int pi[n];

	displayGraph(a);
	cout<<"Input root "; cin>>r;
	prim(a,r,key,pi);
	displayKeyPi(key,pi);
	displayMST(key, pi, r);

	return 0;
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

void displayKeyPi(int d[], int pi[]){
	cout <<"i: pi key: "<<endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<pi[i]<<" "<<d[i]<<endl;
	cout<<"----"<<endl;
}

void displayMST(int key[], int pi[], int r) {
	int w = 0;
	for (int i = 0; i < n; i++) {
		if (i != r) {
			cout << i << " " << pi[i] << " " << key[i] << endl;
			w += key[i];
		}
	}
	cout << "MST total weight: " << w << endl;
}


void prim(int a[][n], int r, int key[], int pi[]){
	int u;
	int inQ[n];
	priority_queue<node,vector<node>,greater<node>> q; 
	for(int i=0; i<n; i++){
		key[i]=INF;
		pi[i]=-1;
	}
	key[r] = 0;
	
	for (int i = 0; i < n; i++) {
		q.push(make_pair(key[i], i));
		inQ[i] = 1;
	}

	while(!q.empty()){
		u = q.top().second;
		q.pop();
		if (inQ[u] == 0) continue;
		else inQ[u] = 0;
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(inQ[v] == 1 && a[u][v]<key[v]){
					pi[v] = u;
					key[v] = a[u][v];
					q.push(make_pair(key[v],v));
				}
	}
}

void prim1(int a[][n], int r, int key[], int pi[]) {
	int u;
	int inMST[n] = { 0 };
	priority_queue<node, vector<node>, greater<node>> q;
	for (int i = 0; i<n; i++) {
		key[i] = INF;
		pi[i] = -1;
	}
	key[r] = 0;

	q.push(make_pair(key[r], r));

	while (!q.empty()) {
		u = q.top().second;
		q.pop();
		inMST[u] = 1;
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (inMST[v] != 1 && a[u][v]<key[v]) {
					pi[v] = u;
					key[v] = a[u][v];
					q.push(make_pair(key[v], v));
				}
	}
}

/*
void prim2(int a[][n], int s, int key[], int pi[]) {
	set<node> q;
	int u;
	int inQueue[n];

	for (int i = 0; i<n; i++) {
		if (i != s)
			key[i] = INF;
		else
			key[s] = 0;
		pi[i] = -1;
		q.insert(make_pair(key[i], i));
		inQueue[i] = 1;
	}
	cout << endl;
	while (!q.empty()) {
		u = q.begin()->second;
		q.erase(make_pair(key[u], u));
		inQueue[u] = 0;
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (inQueue[v] == 1 && key[v]>a[u][v]) {
					q.erase(make_pair(key[v], v));
					key[v] = a[u][v];
					pi[v] = u;
					q.insert(make_pair(key[v], v));
				}
	}

}
*/