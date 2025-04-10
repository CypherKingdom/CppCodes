#include<iostream>
#include<queue>
using namespace std;

#define n 6
#define m 10
#define INF 9999

void fordFulkerson(int [][n], int , int , int [][n]);

void constructGf(int [][n], int [][n]);
bool hasAugmentingPath(int [][n], int , int , int [], int []);
int minResCapacity(int [][n], int, int, int []);
void updateFlowGf(int [][n], int, int, int [], int, int [][n] );

void displayFlow(int [][n], int);

int main(){
			   //0,1,2,3,4,5
	int a[n][n]={0,16,0,0,0,13,
				 0,0,12,0,0,10,
				 0,0,0,20,0,9,
				 0,0,0,0,0,0,
				 0,0,7,4,0,0,
				 0,4,0,0,14,0};
	int f[n][n]={0};
	int s, t;

	s=0; t=3;
	fordFulkerson(a,s,t,f);
	displayFlow(f,s);

	return 0;
}

void fordFulkerson(int a[n][n], int s, int t, int f[n][n] ){
	int Gf[n][n];
	int d[n], pi[n];
	int  min;//cf(p)

	constructGf(a,Gf);
	while(hasAugmentingPath(Gf,s,t,d,pi)){
		min = minResCapacity(Gf,s,t,pi);
		updateFlowGf(Gf,s,t,pi,min,f);
	}


}

void constructGf(int a[][n], int Gf[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			Gf[i][j]= a[i][j];
		}
	}
}

int minResCapacity(int Gf[n][n], int s, int t, int pi[n]){
	int v, min=INF;	//cf(p)
	v = t;
	//for sure we have a path bcz hasAugmentingPath()=true
	//and t != s
		while(v!=s){//find cf(p) on aug. path
			if(Gf[pi[v]][v] < min)
				min = Gf[pi[v]][v];
			v = pi[v];
		}
	return min;
}

void updateFlowGf(int Gf[n][n], int s, int t, int pi[n], int min, int f[n][n]){
	int v = t;
		while(v!=s){//add cf(p) on the aug. path		
			f[pi[v]][v] += min; f[v][pi[v]] = -f[pi[v]][v];
			Gf[pi[v]][v] -= min; Gf[v][pi[v]] += min;
			v = pi[v];
		}
}



bool hasAugmentingPath(int Gf[][n], int s, int t, int d[], int pi[]){
	int u;
	queue<int> q;//create FIFO queue
	for(int i=0; i<n; i++){
		d[i]=INF;
		pi[i]=-1;
	}
	d[s]=0;
	q.push(s);//input s to the end of queue
	while(!q.empty()){
		u = q.front();//output the value in front of queu
		q.pop();//remove the front of queue from queue
		for(int v=0; v<n; v++)
			if(Gf[u][v]>0)
				if(d[v]==INF){
					d[v]=d[u]+1;
					pi[v] = u;
					q.push(v);
				}
	}
	if(pi[t]!=-1)
		return true;
	else
		return false;
}

void displayFlow(int f[n][n], int s){
	int flow=0;
	cout<<"Arc: Flow"<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(f[i][j]>0)
				cout<<i<<"-"<<j<<": "<<f[i][j]<<endl;
			if(i==s)
				flow+=f[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Max flow: fmax ="<<flow<<endl;

}