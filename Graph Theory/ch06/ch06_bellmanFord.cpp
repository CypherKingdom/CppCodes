#include<iostream>
using namespace std;

#define n 5
#define m 10
#define INF 99999

struct Edge{
	int u, v, w;
};


bool bellmanFord(int [][n], int, int [], int []);


void displayGraph(int [][n]);
void displayDistPi(int [], int[]);

int main(){
				//0, 1, 2, 3, 4
	int a[n][n]={ 0, 6, 0, 0, 7, //0
				  0, 0, 5, -4, 8, //1
				  0, -2, 0, 0, 0, //2
				  2, 0, 7, 0, 0, //3
				  0, 0, -3, 9, 0//4
	};

	int s;
	int d[n], pi[n];


	cout<<"Input root vertex s: "; cin>>s;
	bellmanFord(a,s,d,pi);
	displayDistPi(d,pi);


	return 0;
}


bool bellmanFord(int a[][n], int s, int d[], int pi[]){
	Edge edge[m];
	int k=0;
	int u, v, w;

	for(int i=0; i<n; i++){
		if(i!=s)
			d[i]=INF;
		else
			d[s]=0;
		pi[i]=-1;
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(a[i][j]!=0){
				edge[k].u = i;
				edge[k].v = j;
				edge[k].w = a[i][j];
				k++;
			}

	for(int i=1; i<=n-1; i++)
		for(int j=0; j<m; j++){
			u = edge[j].u; v = edge[j].v; w=edge[j].w;
			if(d[v] > d[u]+w){
				d[v]=d[u]+w;
				pi[v]=u;
			}
		}

	for(int j=0; j<m; j++){
		u = edge[j].u; v = edge[j].v; w=edge[j].w;
		if(d[v] > d[u]+w)
			return false;
	}	
	return true;
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
