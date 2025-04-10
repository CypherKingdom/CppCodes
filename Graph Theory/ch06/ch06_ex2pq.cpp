#include<iostream>
using namespace std;
#include<functional>
#include<queue>
//#include<set>


#define n 4
#define INF 99999

typedef pair<int,int> node;//<distance,vertex>

void countSP(int [][n], int, int [], int [], int []);//prob2


void displayGraph(int [][n]);
void displayDistPi(int [], int[]);


int main(){
				//0, 1, 2, 3, 
	int a[n][n]={ 0, 1, 2, 3,  //0
				  1, 0, 1, 0,  //1
				  2, 1, 0, 1,  //2
				  3, 0, 1, 0 //3
	};


	int s;
	int d[n], pi[n];
	int sp[n];

	cout<<"Input root vertex s: "; cin>>s;

	countSP(a,s,d,pi,sp);
	for(int i=0; i<n; i++)
		cout<<i<<":"<<sp[i]<<endl;

	return 0;
}

void countSP(int a[][n], int s, int d[], int pi[], int sp[n]) {
	priority_queue< node, vector<node>, greater<node> > q;
	int u;
	int S[n] = { 0 };

	for (int i = 0; i<n; i++) {
		d[i] = INF;
		pi[i] = -1;
		sp[i] = 0;
	}
	d[s] = 0;
	sp[s] = 1;
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
				if (d[v]>d[u] + a[u][v]) {
					d[v] = d[u] + a[u][v];
					pi[v] = u;
					sp[v] = sp[u];
					q.push(make_pair(d[v], v));
				}
				else if (d[v] == d[u] + a[u][v]) {
					sp[v] += sp[u];
				}
	}

}

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

void displayDistPi(int d[], int pi[]){
	cout <<"i: pi dist.: "<<endl;
	for(int i=0; i<n; i++)
		cout<<i<<": "<<pi[i]<<" "<<d[i]<<endl;
	cout<<"----"<<endl;
}

/*
//2nd method
void countSP(int a[][n], int s, int d[], int pi[], int sp[]){
	set<node> q;
	int u;

	for(int i=0; i<n; i++){
		if(i!=s){
			d[i]=INF;
			sp[i] = 0;
		}else{
			d[s]=0;
			sp[s]=1;
		}
		pi[i]=-1;
		q.insert(make_pair(d[i],i));
	}

	while(!q.empty()){
		u = q.begin()->second;
		q.erase(make_pair(d[u],u));
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(d[v]>d[u]+a[u][v]){
					q.erase(make_pair(d[v],v));
					d[v]=d[u]+a[u][v];
					pi[v] = u;
					q.insert(make_pair(d[v],v));
					sp[v]=sp[u];
				}else
					if(d[v]==d[u]+a[u][v])
						sp[v]+=sp[u];

	}

}
*/