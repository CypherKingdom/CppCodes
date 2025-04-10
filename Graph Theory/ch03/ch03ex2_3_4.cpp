#include<iostream>
using namespace std;

#define N 5

void initMatrix(int [][N]);
void inputMatrix(int [][N]);
void fillMatrix(int [][N]);
void displayMatrix(int [][N]);
bool isCycle(int [][N]);
bool isComplete(int [][N]);
bool isTree(int [][N]);

int main(){
	int A[N][N];

	initMatrix(A);
	inputMatrix(A);
	//fillMatrix(A);
	displayMatrix(A);

	if(isCycle(A))
		cout<<"G is a cycle"<<endl;
	else
		cout<<"NOT a cycle"<<endl;

	if(isComplete(A))
		cout<<"G is complete"<<endl;
	else
		cout<<"G is NOT complete"<<endl;

	if(isTree(A))
		cout<<"G is a tree"<<endl;
	else
		cout<<"G is NOT a tree"<<endl;


	return 0;
}

void fillMatrix(int A[][N]){//Path Pn
	for(int i=1;i<N-1;i++){
		A[i][i+1]=1;
		A[i][i-1]=1;
	}
	A[0][1]=1;
	A[N-1][N-2]=1;
}


bool isCycle(int A[][N]){
	int degree;
	for(int i=0; i<N; i++){
		degree=0;
		for(int j=0; j<N; j++){
			if(A[i][j]!=0)
				degree++;
		}
		if(degree!=2){
			return false;
		}
	}
	return true;
}

bool isComplete(int A[][N]){
	int degree;
	for(int i=0; i<N; i++){
		degree=0;
		for(int j=0; j<N; j++){
			if(A[i][j]!=0)
				degree++;
		}
		if(degree!=N-1){
			return false;
		}
	}
	return true;

}
bool isTree(int A[][N]){
	int s=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i][j]!=0)
				s++;
		}
	}
	if(s/2==N-1)
		return true;
	else
		return false;
}

void initMatrix(int A[][N]){
	for(int i=0; i<N; i++)
		for(int j=0;j<N;j++)
			A[i][j]=0;
}

void inputMatrix(int A[][N]){
	int u, v;
	cout<<"Input edges: u-v: "<<endl;
	while(cin>>u>>v){
		A[u][v]=1;
		A[v][u]=1;
	}
	cin.clear();
}

void displayMatrix(int A[][N]){
	cout<<"Graph is: "<<endl;
	for(int i=0; i<N; i++){
		cout<<i<<" -> ";
		for(int j=0; j<N; j++){
			if(A[i][j]!=0)
				cout<<j<<" ";
		}
		cout<<endl;
	}


}
