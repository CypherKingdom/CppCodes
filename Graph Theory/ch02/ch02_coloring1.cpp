#include<iostream>
using namespace std;

#define N 7//4
/*
   1
   1
  / \
 /   \
0---- 2---3
0	  2   0
*/
bool ColoringVertex(int [][N],int,int []);
int ChromaticNb(int []);

int main(){
/*
	int a[N][N]={0, 1, 1, 0,
				 1, 0, 1, 0,	
				 1, 1, 0, 1,
				 0, 0, 1, 0
				};
*/

	int a[N][N]={0, 1, 1, 1, 0, 1, 1,
				 1, 0, 1, 1, 1, 0, 0,	
				 1, 1, 0, 1, 0, 1, 1,
				 1, 1, 1, 0, 1, 1, 0,
				 0, 1, 0, 1, 0, 1, 1,
				 1, 0, 1, 1, 1, 0, 1,
				 1, 0, 1, 0, 1, 1, 0,
				};




	int color[N];
	
	for(int i=0;i<N;i++){
		color[i]=-1;
	}

	for(int i=0; i<N; i++){
		if(!ColoringVertex(a,i,color)){
			cout<<"Coloring Error!";
			return 1;
		}
	}

	cout<<"Chrom Nb: "<<ChromaticNb(color)<<endl;

	for(int i=0;i<N;i++){
		cout<<"color of vertex"<<i<<" :"<<color[i]<<endl;
	}

	return 0;
}

bool ColoringVertex(int a[][N],int i, int color[]){
	bool found;
	for(int k=0;k<N;k++){// k: color
		found=false;
		for(int j=0;j<N;j++){ // j: vertex
			//if i ajacent to j and j has color k			
			if(a[i][j]==1 && color[j]==k){
				found=true; // color k already used by neighbor
				break;	
			}
		}
		if(!found){
			color[i]=k;		
			return true;
		}
	}
	return false;

}

int ChromaticNb(int color[]){
	int max=0;
	for(int i=0;i<N;i++){
		if(max<color[i])
			max=color[i];
	}
	return max+1;
}