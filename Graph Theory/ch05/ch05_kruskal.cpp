#include<iostream>
#include<algorithm>
using namespace std;

#define m 14
#define n 9


struct Edge{
	int u;
	int v;
	int w;
};

void makeSets(int []);
int findSet(int [], int );
bool connected(int [], int , int );
void Union(int [], int , int );

void kruskal(Edge [], Edge []);
void displayMST(Edge []);
void displayEdges(Edge []);
bool comp(Edge &a, Edge &b) {return a.w<b.w; }
int main(){
	Edge edge[m];
	Edge MST[n-1];
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
	int k=0;
	//Fill edges
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i][j]!=0){
				edge[k].u=i;
				edge[k].v=j;
				edge[k].w=a[i][j];
				k++;
			}
	displayEdges(edge);
	kruskal(edge,MST);
	displayMST(MST);

	return 0;
}

void kruskal(Edge edge[], Edge MST[]){
	int id[n];
	int k=0;
	//Edge e;
	//e.u=-1; e.v=-1;e.w=-1;
	//for(int i=0; i<n-1; i++)//n-1: nb of edges in tree MST
	//	MST[i]=e;
	
	makeSets(id);
	sort(edge,edge+m,comp) ;
	for(int i=0; i<m; i++){
		if(!connected(id,edge[i].u,edge[i].v)){
			MST[k++]=edge[i];
			Union(id,edge[i].u,edge[i].v);
		}
	}
}

void displayEdges(Edge edge[]){
	cout<<"Edges u-v-w:"<<endl;
	for(int i=0; i<m; i++){
		cout<<edge[i].u<<"-"<<edge[i].v<<"-"<<edge[i].w<<endl;
	}
	cout<<"---"<<endl;
}

void displayMST(Edge MST[]){
	cout<<"MST u-v-w:"<<endl;
	for(int i=0; i<n-1; i++){
		cout<<MST[i].u<<"-"<<MST[i].v<<"-"<<MST[i].w<<endl;
	}
	cout<<"---"<<endl;
}


//------------UNION-FIND-----------//
//initialize id
void makeSets(int id[]){
	for(int i=0; i<n; i++)
		id[i] = i;
}

//component identifier for p (0 to N – 1)
int findSet(int id[], int p){ return id[p];}

//are p and q in the same component?
bool connected(int id[], int p, int q){
	return findSet(id, p) == findSet(id, q);
}


//add connection between p and q
void Union(int id[], int p, int q){
	int pid = id[p];
	int qid = id[q];
	for(int i=0; i<n;i++)
		if(id[i] == pid) id[i] = qid;
}