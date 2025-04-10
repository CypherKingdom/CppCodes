#include<iostream>
using namespace std;
#include<queue>
#include<fstream>
#include<functional>

#define n 5
#define INF 99999

typedef pair<int, int> node;//<distance,vertex>


void dijkstralen(int[][n], int, int[], int[], int[]);
void displayPath(int s, int t, int pi[], int a[][n]);
void longestSP(int[][n]);

void displayGraph(int[][n]);
void displayDistPi(int[], int[], int length[]);


int main() {
	//0, 1, 2, 3, 4
	int a[n][n] = { 0, 10, 0, 0, 5, //0
		0, 0, 1, 0, 2, //1
		0, 0, 0, 4, 0, //2
		7, 0, 6, 0, 0, //3
		0, 3, 9, 2, 0//4
	};
	int d[n], pi[n], length[n];

	int s, t;

	displayGraph(a);
	cout << "Input s: "; cin >> s;
	dijkstralen(a, s, d, pi, length);
	displayDistPi(d, pi, length);

	cout << "Input t: "; cin >> t;
	displayPath(s, t, pi, a);

	longestSP(a);

	return 0;
}
void longestSP(int a[][n]) {
	int d[n], pi[n], length[n];
	int max = 0, u, v;
	for (int s = 0; s < n; s++) {
		dijkstralen(a, s, d, pi, length);
		for (int i = 0; i<n; i++)
			if (d[i] != INF && d[i]>max) {
				max = d[i];
				u = s;
				v = i;
			}
	}
	cout << "longest SP: u v dist: " << u << " " << v << " " << max << endl;
}


void dijkstralen(int a[][n], int s, int d[], int pi[], int length[]) {
	priority_queue< node, vector<node>, greater<node> > q;
	int u;
	int S[n] = { 0 };

	for (int i = 0; i<n; i++) {
		if (i != s){
			d[i] = INF;
			length[i] = INF;
		}
		else{
			d[s] = 0;
			length[s] = 0;
		}
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
					length[v] = length[u] + 1;
					q.push(make_pair(d[v], v));
				}
	}

}

void displayPath(int s, int t, int pi[], int a[][n]) {
	int v = t, k = 0;
	int path[n], min = INF;
	while (v != s) {
		path[k++] = v;
		if (a[pi[v]][v]<min)
			min = a[pi[v]][v];
		v = pi[v];
	}
	cout << "Path: " << s << " ";
	for (int i = k - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
	cout << "min weight on path: " << min << endl;
}


void displayGraph(int a[n][n]) {
	//Display adjacency 
	cout << "Adjacency matrix" << endl;
	cout << "vertex: neighbors w" << endl;
	for (int i = 0; i<n; i++) {
		cout << i << ": ";
		for (int j = 0; j<n; j++)
			if (a[i][j] != 0)
				cout << "(" << j << " " << a[i][j] << ") ";
		cout << endl;
	}
	cout << "----" << endl;
}

void displayDistPi(int d[], int pi[], int length[]) {
	cout << "i: pi dist length: " << endl;
	for (int i = 0; i<n; i++)
		cout << i << ": " << pi[i] << " " << d[i] << " " << length[i] << endl;
	cout << "----" << endl;
}
