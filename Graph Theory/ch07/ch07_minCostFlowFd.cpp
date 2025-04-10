#include<iostream>
#include<queue>
using namespace std;

#define n 5
#define M 14
#define INF 9999

struct Weight{
	int c, w;
};
struct Edge{
	int u, v, c, w;
};


void minCostFlowRoy(int [][n], int [][n], int , int , int, int [][n]);

void constructGf(int [][n], int [][n], Weight [][n]);
bool hasAugmentingPath(Weight [][n], int , int , int [], int []);
int minResCapacity(Weight [][n], int, int, int []);
void updateFlowGf(Weight [][n], int, int, int [], int, int [][n] );

void displayResult(int [][n], int [][n], int);

int main(){
			   //0,1,2,3,4,
	int c[n][n]={0,200,0,400,0,
				 0,0,200,200,0,
				 0,0,0,0,300,
				 0,0,200,0,200,
				 0,0,0,0,0};
	int w[n][n]={0,0,0,2,0,
				 0,0,13,2,0,
				 0,-13,0,-9,0,
				 -2,-2,9,0,16,
				 0,0,0,-16,0};

	int f[n][n]={0};
	int s=0, t=4, Fd=400;
	minCostFlowRoy(c,w,s,t,Fd,f);
	displayResult(f,w,s);

	return 0;
}

void minCostFlowRoy(int c[n][n], int w[n][n], int s, int t, int Fd, int f[n][n] ){
	Weight Gf[n][n];
	int d[n], pi[n];
	int  min;//cf(p)
	int fmax;

	constructGf(c,w,Gf);
	while(hasAugmentingPath(Gf,s,t,d,pi)){
		fmax=0;
		for(int j=0; j<n; j++)
			fmax+=f[s][j];
		cout<<fmax<<endl;
		if(fmax >= Fd) break;
		min = minResCapacity(Gf,s,t,pi);
		if(fmax+min>Fd)
			min = Fd-fmax;
		updateFlowGf(Gf,s,t,pi,min,f);

	}
}

void constructGf(int c[][n], int w[][n], Weight Gf[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			Gf[i][j].c= c[i][j];
			Gf[i][j].w= w[i][j];
		}
	}
}

int minResCapacity(Weight Gf[n][n], int s, int t, int pi[n]){
	int v, min=INF;	//cf(p)
	v = t;
	//for sure we have a path bcz hasAugmentingPath()=true
	//and t != s
	cout<<"Augmenting Path: ";
		while(v!=s){//find cf(p) on aug. path
			cout<<v<<" ";
			if(Gf[pi[v]][v].c < min)
				min = Gf[pi[v]][v].c;
			v = pi[v];
		}
		cout<<": cf(p) = "<<min<<endl;
		
	return min;
}

void updateFlowGf(Weight Gf[n][n], int s, int t, int pi[n], int min, int f[n][n]){
	int v = t;
		while(v!=s){//add cf(p) on the aug. path		
			f[pi[v]][v] += min; f[v][pi[v]] = -f[pi[v]][v];
			Gf[pi[v]][v].c -= min; Gf[v][pi[v]].c += min;
			//Gf[v][u] is -Gf[u][v] initially (assume cost symmetry)
			v = pi[v];
		}
}

bool hasAugmentingPath(Weight Gf[][n], int s, int t, int d[], int pi[]){
	//BellmanFord
	Edge edge[M];
	int m=0;
	int u, v, c, w;

	for(int i=0; i<n; i++){
		if(i!=s)
			d[i]=INF;
		else
			d[s]=0;
		pi[i]=-1;
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(Gf[i][j].c!=0){
				edge[m].u = i;
				edge[m].v = j;
				edge[m].c = Gf[i][j].c;
				edge[m].w = Gf[i][j].w;
				m++;
			}

	for(int i=1; i<=n-1; i++)
		for(int j=0; j<m; j++){
			u = edge[j].u; v = edge[j].v; 
			c=edge[j].c; w=edge[j].w;
			if(d[v] > d[u]+w){
				d[v]=d[u]+w;
				pi[v]=u;
			}
		}

	if(pi[t]!=-1)
		return true;
	else
		return false;

}

void displayResult(int f[n][n], int w[n][n], int s){
	int flow=0, totalCostZ=0;
	cout<<"Arc: Flow - cost"<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(f[i][j]>0){
				cout<<i<<"-"<<j<<": "<<f[i][j]<<" - "<<w[i][j]<<endl;
				totalCostZ+=f[i][j]*w[i][j];
			}if(i==s)
				flow+=f[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Max flow: fmax ="<<flow<<endl;
	cout<<"Min Cost: Z(fmax) ="<<totalCostZ<<endl;
}

