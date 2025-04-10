#include<iostream>
using namespace std;

#include "BST.h"


treeNode* initialize(){
	return NULL;
}

treeNode* find(treeNode* T,elementType x){
	if(T == NULL)
		return NULL;

	if(x < T->element)
		return find(T->left,x);
	else
		if(x > T->element)
			return find(T->right,x);
		else
			return T;
}
treeNode* findMin(treeNode* T){//recursive
	if(T == NULL)
		return NULL;
	
	if(T->left == NULL)
		return T;

	return findMin(T->left);
}
treeNode* findMax(treeNode* T){//iterative

	if(T == NULL)
		return NULL;

	while(T->right != NULL){
		T = T->right;
	}
	return T;
}

treeNode* insert(treeNode* T,elementType val){
	if(T == NULL){
		treeNode * tmp = new treeNode;
		tmp->element = val;
		tmp->left = tmp->right = NULL;
		return tmp;
	}

	if(val <= T->element)
		T->left = insert(T->left, val);
	else
		T->right = insert(T->right, val);

	return T;	
}
void insert1(treeNode*& T,elementType val){
	treeNode* tmp, *prev;

	tmp = new treeNode;
	tmp->element = val;
	tmp->left = tmp->right = NULL;

	if(T == NULL){
		T = tmp;
		return ;
	}

	for(treeNode* t = T; t!=NULL;){
		prev = t;
		if(val <= t->element)
			t = t->left;
		else
			t = t->right;
	}

	if(val < prev->element)
		prev->left = tmp;
	else
		prev->right = tmp;
	return ;
}
treeNode* remove(treeNode*& T,elementType x){
	treeNode* tmp;
	if(T == NULL){
		cerr<<"Element not found!"<<endl;
		return NULL;
	}
	if(x < T->element)
		T->left = remove(T->left, x);
	else
		if(x > T->element)
			T->right = remove(T->right, x);
		else
			if(T->left != NULL && T->right != NULL){				
				tmp = findMin(T->right);
				T->element = tmp->element;
				T->right = remove(T->right, T->element);
			}else{
				tmp = T;
				if(T->left != NULL){
					T = T->left;
				}else
					T = T->right;
				delete tmp;
			}
	return T;
}

void removeTree(treeNode*&T){
	if(T == NULL)
		return;
	removeTree(T->left);
	removeTree(T->right);
	delete T;
	T = NULL;
}
void displayInorder(treeNode* T){
	if(T == NULL)
		return;
	displayInorder(T->left);	
	cout<<T->element<<" ";
	displayInorder(T->right);
}
void displayPreorder(treeNode* T){
	if(T == NULL)
		return;
	cout<<T->element<<" ";
	displayPreorder(T->left);
	displayPreorder(T->right);
}
void displayPostorder(treeNode* T){
	if(T == NULL)
		return;	
	displayPostorder(T->left);
	displayPostorder(T->right);
	cout<<T->element<<" ";
}

void inorderArray(treeNode* T, int* a, int& k){
	if(T == NULL) return;

	inorderArray(T->left,a,k);
	a[k++] = T->element;
	inorderArray(T->right,a,k);
}

void BSTsorting(int*a, int N){
	treeNode* T;
	int k = 0;
	T = initialize();
	for(int i=0; i<N; i++){
		T = insert(T,a[i]);
	}
	inorderArray(T,a, k);
}