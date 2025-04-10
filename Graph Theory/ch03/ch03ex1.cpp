#include<iostream>
using namespace std;


#define N 5

int main(){
	/*
	int a[N][N]={0, 1, 1 ,2, 0,
				 1, 0, 0, 0, 1,
				 1, 0, 0, 1, 1,
				2, 0, 1, 0, 0,
				0, 1, 1, 0, 0};
	*/
	int a[N][N]={0};
	int countOdd, degree, type;// type: 0: weighed, 1: multigraph
	int u, v, w;
	cout<<"Input type of graph (0: weighed, 1: multigraph): "; 
	cin>>type;
	if(type==0){//Weighed graph
		cout<<"Input u-v edge and w weight (ctrl-z to stop):"<<endl;
		while(cin>>u>>v>>w){
			a[u][v] = w;
			a[v][u] = w;
		}
		cin.clear();
		
		countOdd=0;
		for(int i=0; i<N; i++){
			degree=0;
			for(int j=0; j<N; j++){
				if(a[i][j]!=0)
					degree++; 
			}
			if(degree%2!=0)
				countOdd++;
		}
	}else{//Multigraph
		cout<<"Input u-v edges (ctrl-z to stop):"<<endl;
		while(cin>>u>>v>>w){
			a[u][v] += 1;
			a[v][u] += 1;
		}
		cin.clear();

		countOdd=0;
		for(int i=0; i<N; i++){
			degree=0;
			for(int j=0; j<N; j++){
				if(a[i][j]!=0)
					degree+=a[i][j]; 
			}
			if(degree%2!=0)
				countOdd++;
		}
	}



	if(countOdd%2==0)
		cout<<"Odd vertices are even"<<endl;
	else
		cout<<"Odd vertices are NOT even"<<endl;

	return 0;
}