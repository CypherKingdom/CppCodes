#include<iostream>
using namespace std;
#include <vector>
#include <queue>
#include<functional>
//#include<set>
#define n 5
#define INF 99999

typedef pair<int,int> node;//<distance,vertex>

//Method 1
void dijkstra(int [][n], int, int [], int []);

void displayGraph(int [][n]);
void displayDistPi(int [], int[]);

//Method 2
//void dijkstra2(int[][n], int, int[], int[]);

int main(){
				//0, 1, 2, 3, 4
	int a[n][n]={ 0, 10, 0, 0, 5, //0
				  0, 0, 1, 0, 2, //1
				  0, 0, 0, 4, 0, //2
				  7, 0, 6, 0, 0, //3
				  0, 3, 9, 2, 0//4
	};

	int s;
	int d[n], pi[n];


	cout<<"Input root vertex s: "; cin>>s;
	dijkstra(a,s,d,pi);
	displayDistPi(d,pi);

	return 0;
}


void dijkstra(int a[][n], int s, int d[], int pi[]){
	priority_queue< node, vector<node>, greater<node> > q;
	int u;
	int S[n]={0};

	for(int i=0; i<n; i++){
		if(i!=s)
			d[i]=INF;
		else
			d[s]=0;
		pi[i]=-1;
		q.push(make_pair(d[i],i));
	}

	while(!q.empty()){
		u = q.top().second;
		q.pop();
		if(S[u]==1) continue;
		else S[u] = 1;
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(d[v]>d[u]+a[u][v]){					
					d[v]=d[u]+a[u][v];
					pi[v] = u;
					q.push(make_pair(d[v],v));
				}
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
void dijkstra2(int a[][n], int s, int d[], int pi[]) {
	set<node> q;
	int u;

	for (int i = 0; i<n; i++) {
		if (i != s)
			d[i] = INF;
		else
			d[s] = 0;
		pi[i] = -1;
		q.insert(make_pair(d[i], i));
	}

	while (!q.empty()) {
		u = q.begin()->second;
		q.erase(make_pair(d[u], u));
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (d[v]>d[u] + a[u][v]) {
					q.erase(make_pair(d[v], v));
					d[v] = d[u] + a[u][v];
					pi[v] = u;
					q.insert(make_pair(d[v], v));

				}

	}

}
*/