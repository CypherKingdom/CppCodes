#include<iostream>
using namespace std;

#define n 5
#define INF 99999

void floydWarshall(int [][n], int [][n], int [][n]);
void displayD_Pi(int [][n], int [][n]);
bool negativeCycle(int [][n]);//prob7
void transitiveClosure(int [][n], int [][n], bool);//prob8
void displayGraph(int [][n]);
int main(){
				//0, 1, 2, 3, 4
	int a[n][n]={ 0, 3, 8, 0, -4, //0
				  0, 0, 0, 1, 7, //1
				  0, 4, 0, 0, 0, //2
				  2, 0, -5, 0, 0, //3
				  0, 0, 0, 6, 0//4
	};

	int s;
	int d[n][n], pi[n][n];
	int w[n][n];

	displayGraph(a);
	floydWarshall(a,d,pi);
	displayD_Pi(d,pi);
	if(negativeCycle(d))
		cout<<"There is a negative cycle";
	else
		cout<<"No negative cycle";
	cout<<endl;

	transitiveClosure(d,w,true);
	cout<<"transitive closure graph"<<endl;
	displayGraph(w);

	return 0;
}

void floydWarshall(int a[n][n], int d[n][n], int pi[n][n]){

	for(int i=0; i<n ; i++){
		for(int j=0; j<n ; j++){			
			if(a[i][j]!=0){
				pi[i][j]=i;
				d[i][j]=a[i][j];
			}else 
				if (i!=j){
					d[i][j]=INF;
					pi[i][j]=-1;
				}else{
					d[i][j]=0;
					pi[i][j]=-1;
				}
		}
	}

	for(int k=0; k<n; k++){
		for(int i=0; i<n ; i++){
			for(int j=0; j<n ; j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					pi[i][j]=pi[k][j];
				}
			}
		}
	}

}

void displayD_Pi(int d[n][n], int pi[n][n]){

	cout<<"Display distance matrix: "<<endl;
	cout<<" \t";
	for(int j=0; j<n ; j++)
		cout<<j<<"\t";
	cout<<endl;
	for(int i=0; i<n ; i++){
		cout<<i<<"\t";
		for(int j=0; j<n ; j++){
			cout<<d[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"Display predecessor matrix: "<<endl;
	cout<<" \t";
	for(int j=0; j<n ; j++)
		cout<<j<<"\t";
	cout<<endl;
	for(int i=0; i<n ; i++){
		cout<<i<<"\t";
		for(int j=0; j<n ; j++){
			cout<<pi[i][j]<<"\t";
		}
		cout<<endl;
	}
}

//prob7
bool negativeCycle(int d[n][n]){
	for(int i=0; i<n ; i++)
		if(d[i][i]<0)
			return true;
	return false;

}

//prob8
void transitiveClosure(int d[n][n], int w[n][n], bool weighted){

	if(!weighted){//not weighted graph
		for(int i=0; i<n ; i++)
			for(int j=0; j<n ; j++)
				if(d[i][j] == 0 || d[i][j] == INF)
					w[i][j] = 0;
				else
					w[i][j] = 1;
	}else{//weighted graph
		for(int i=0; i<n ; i++)
			for(int j=0; j<n ; j++)
				if (d[i][j] != INF)
					w[i][j] = d[i][j];
				else
					w[i][j] = 0;
	}
}

void displayGraph(int a[n][n]){
	cout<<"Graph: "<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<": ";
		for(int j=0; j<n; j++)
			if(a[i][j]!=0)
				cout<<j<<" ";
		cout<<endl;
	}

}