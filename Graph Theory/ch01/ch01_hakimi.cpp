#include<iostream>

using namespace std;

bool IsValidVector(int [], int);
bool IsZeroVector(int [], int);
void sortVector(int [], int);
int	updateVector(int [], int);
int main(){
	int N, n, s=0;
	bool valid=true, zero=false;
	cout<<"Enter the nb of vertices: ";
	cin>>N;
	int* v=new int[N];
	cout<<"Enter the degree for the N vertices:"<<endl;

	for(int i=0; i<N; i++){
		cin>>v[i];
		s+=v[i];
	}

	if(s%2!=0){
		cout<<"Not graphical: s not even"<<endl;
		system("pause");
		return 1;
	}
int	i=0;
	while(true){
		if(!IsValidVector(v,N)){
			cout<<"Not graphical vector"<<endl;
			system("pause");
			return 1;
		}
		if(IsZeroVector(v,N)){
			cout<<"Graphical vector"<<endl;
			system("pause");		
			return 0;
		}		
		sortVector(v,N);
		N=updateVector(v,N);
		cout<<"i= "<<i++<<endl;
	}
	system("pause");
	return 0;
}

int updateVector(int v[], int N){
	int x=v[0];
	for(int i=1; i<=x; i++){
		v[i-1]=--v[i];
	}
	for(int i=x+1; i<N; i++){
		v[i-1]=v[i];
	}
	return N-1;
}

bool IsZeroVector(int v[], int n){
	for(int i=0; i<n; i++)
		if(v[i]!=0)
			return false;
	
	return true;
}

bool	IsValidVector(int v[], int n){
	for(int i=0; i<n; i++){
		if(v[i]<0){
			cout<<"Not graphical: v[i]<0"<<endl;
			return false;
		}
		if(v[i]>n-1){
			cout<<"Not graphical: v[i]>N-1"<<endl;
			return false;
		}			
	}
	return true;
}

void	sortVector(int v[], int n){
	int temp;	
	for(int i=1; i<=n-1; i++)
			for(int j=0; j<n-i; j++)
				if(v[j]<v[j+1]){
					temp=v[j]	;
					v[j]=v[j+1];
					v[j+1]=temp;
				}
}
