#include<iostream>
using namespace std;
#include<queue>
//#include<set>
#include<functional> //greater

#define n 4
#define INF 99999

typedef pair<float,int> node;//<distance,vertex>

void reliablePath(float [][n], int , float [], int []);//prob4

void displayGraph(int [][n]);
void displayDistPi(float [], int[]);


int main(){

	
				  //0, 1, 2, 3, 
	float a[n][n]={ 0, 0.1, 0.2, 0.3,  //0
				  0.1, 0, 0.9, 0,  //1
				  0.2, 0.9, 0, 0.9,  //2
				  0.3, 0, 0.9, 0 //3
	};

	int s;
	float d[n];
	int pi[n];

	cout<<"Input root vertex s: "; cin>>s;

	reliablePath(a,s,d,pi);
	displayDistPi(d,pi);

	return 0;
}


void reliablePath(float a[][n], int s, float d[], int pi[]) {
	priority_queue<node> q;
	int u;
	int S[n] = { 0 };

	for (int i = 0; i<n; i++) {
		d[i] = -INF;
		pi[i] = -1;
		
	}
	d[s] = 1;

	for (int i = 0; i < n; i++) {
		q.push(make_pair(d[i], i));
	}

	while (!q.empty()) {
		u = q.top().second;
		q.pop();
		if (S[u] == 1) continue;
		else S[u] = 1;
		for (int v = 0; v<n; v++)
			if (a[u][v] != 0)
				if (d[v] < d[u] * a[u][v]) {
					d[v] = d[u] * a[u][v];
					pi[v] = u;
					q.push(make_pair(d[v], v));
				}
	}

}

/*
2nd method
void reliablePath(float a[][n], int s, float d[], int pi[]){
	set<node,greater<node>> q;
	int u;

	for(int i=0; i<n; i++){
		if(i!=s){
			d[i]=-INF;
		}else{
			d[s]=1;
		}
		pi[i]=-1;
		q.insert(make_pair(d[i],i));
	}

	while(!q.empty()){
		u = q.begin()->second;
		q.erase(make_pair(d[u],u));
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(d[v]<d[u]*a[u][v]){
					q.erase(make_pair(d[v],v));
					d[v]=d[u]*a[u][v];
					pi[v] = u;
					q.insert(make_pair(d[v],v));
				}

	}

}
*/

void displayGraph(int a[n][n]){
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

void displayDistPi(float d[], int pi[]){
	cout <<"i: pi dist.: "<<endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<pi[i]<<" "<<d[i]<<endl;
	cout<<"----"<<endl;
}

