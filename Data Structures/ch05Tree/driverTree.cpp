#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include <ctime>
#include "BST.h"


int nbNodes(treeNode *);//ex5
void nbNodes1(treeNode *, int&);
int nbOddNodes(treeNode *);
int nbOddNodes2(treeNode *);
void nbOddNodes1(treeNode *,int&);

int sumNodes(treeNode *);//ex12 //lab_ex2
void sumNodes1(treeNode *, int&);

int nbLeaves(treeNode* );//ex5
int nbLeaves2(treeNode* );
void nbLeaves1(treeNode* , int&);

void copyBST(treeNode*& , treeNode* );//ex17//lab_ex1
bool isSimilar(treeNode* , treeNode* );//ex13
void splitTree(treeNode*, treeNode*& , treeNode*& );//ex17

bool isBST(treeNode*,elementType,elementType);//ex15 
bool isBST2(treeNode*,elementType,elementType);//ex15
int treeHeight(treeNode*);//ex6

//-----//
treeNode* createExprTree(char*);//ex9 
float evalExprTree(treeNode*);//ex9 
void postfixIter(treeNode*);//ex10
void infixIter(treeNode*);//ex10 
void prefixIter(treeNode*);//ex10
void displayByLevel(treeNode*);//ex14
void displayByLevel1(treeNode*);//ex14

treeNode* insertGeneralTree(treeNode*, elementType);

//lab_ex2
void removeOdd(treeNode*&);

void createTreeByLevel(treeNode*& t, int *a, int n);
void insertTreeByLevel(treeNode*& t, int x);

int main(){
	treeNode* T, *t, *T1, *T2;
	int n, x, min, max;
	int* a;
	int N;

	T = initialize();
	T1 = initialize();
	T2 = initialize();

	cout<<"Input n: "; cin>>n;
	a = new int[n];

	srand(time(0));
	cout<<"Random values to insert to tree"<<endl;
	for(int i=0; i<n; i++){
		x = rand()%100;
		T = insert(T,x);
		a[i] = x;
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Tree preorder"<<endl;
	displayPreorder(T);
	cout<<"---"<<endl;


	BSTsorting(a,n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	cout<<"# odd nodes: "<<nbOddNodes(T)<<endl;
	cout<<"# odd nodes2: "<<nbOddNodes2(T)<<endl;
	N=0;
	nbOddNodes1(T,N);
	cout<<"# odd nodes1: "<<N<<endl;

	cout<<"# leaves: "<<nbLeaves(T)<<endl;
	cout<<"# leaves 2: "<<nbLeaves2(T)<<endl;
	N=0;
	nbLeaves1(T,N);
	cout<<"# leaves 1: "<<N<<endl;
	t = nullptr;
	createTreeByLevel(t, a, n);
	displayByLevel1(t);
/*
	removeOdd(T);
	displayPreorder(T);
	cout<<endl;
*/
/*
	cout<<"Tree preorder Iter"<<endl;
	prefixIter(T);
	cout<<endl;
	cout<<"Tree inorder"<<endl;
	displayInorder(T);
	cout<<endl;
	cout<<"Tree inorder Iter"<<endl;
	infixIter(T);
	cout<<endl;
	cout<<"Tree Posorder"<<endl;
	displayPostorder(T);
	cout<<endl;
	cout<<"Tree Postorder Iter"<<endl;
	postfixIter(T);
	cout<<endl;
*/
/*
	x = rand()%100;;
	cout<<"Find "<<x<<endl;
	if(find(T,x))
		cout<<"Found"<<endl;
	else
		cout<<"Not found"<<endl;
	t = findMin(T);
	cout<<"Min = "<<t->element<<endl;
	t = findMax(T);
	cout<<"Max = "<<t->element<<endl;

	BSTsorting(a,n);
	cout<<"Sorted array: "<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
*/
/*
	cout<<"Removing Max from tree..."<<endl;
	t = findMax(T);
	remove(T,t->element);
	displayPreorder(T);
	cout<<endl;
*/
/*
	cout<<"Nb nodes: "<<nbNodes(T)<<endl;
	n = 0;
	nbNodes1(T,n);
	cout<<"Nb nodes: "<<n<<endl;

	cout<<"Sum of nodes: "<<sumNodes(T)<<endl;
	n = 0;
	sumNodes1(T,n);
	cout<<"Sum of nodes: "<<n<<endl;

	cout<<"nb of leaves: "<<nbLeaves(T)<<endl;
*/
/*
	copyBST(T1,T);
	displayPreorder(T1);
	cout<<endl;
	if(isSimilar(T,T1))
		cout<<"Similar"<<endl;
	else
		cout<<"Not similar"<<endl;

	for(int i=0; i<n; i++){
		x = rand()%100;
		T2 = insert(T2,x);
	}

	if(isSimilar(T1,T2))
		cout<<"Similar"<<endl;
	else
		cout<<"Not similar"<<endl;

	removeTree(T1);
	removeTree(T2);
	T1 = initialize();
	T2 = initialize();
	splitTree(T,T1,T2);
	displayPreorder(T1);cout<<endl;
	displayPreorder(T2);cout<<endl;
*/
/*
	cout<<"T2: ";
	for(int i=0; i<n; i++){
		x = rand()%100;
		T2 = insertGeneralTree(T2,x);
	}
	displayPreorder(T2);
	cout<<endl;

	t=findMin(T2); min = t->element;
	t=findMax(T2);max = t->element;
	isBST(T2,min,max)?cout<<"T2 is BST"<<endl:cout<<"T2 is Not BST"<<endl;
	isBST2(T2,min,max)?cout<<"T2 is BST"<<endl:cout<<"T2 is Not BST"<<endl;

	t=findMin(T); min = t->element;
	t=findMax(T);max = t->element;
	isBST(T,min,max)?cout<<"T is BST"<<endl:cout<<"T is Not BST"<<endl;
	isBST2(T,min,max)?cout<<"T is BST"<<endl:cout<<"T is Not BST"<<endl;
	
	cout<<"tree Height: "<<treeHeight(T)<<endl;
	cout<<"Display by level: ";
	displayByLevel(T);
	cout<<"Display by level: "<<endl;
	displayByLevel1(T);	
	removeTree(T2);
	T2 = initialize();
	T2 = createExprTree("23+586+**");
	displayPostorder(T2);cout<<endl;
	cout<<"Expr 23+586+** = "<<evalExprTree(T2)<<endl;
*/
	return 0;
}

void insertTreeByLevel(treeNode*& T, int x) {
	queue<treeNode*> q;
	treeNode* tmp, *t;
	tmp = new treeNode;
	tmp->element = x;
	tmp->left = nullptr;
	tmp->right = nullptr;
	if (T == nullptr) {
		T = tmp;
		return;
	}
	q.push(T);
	while (!q.empty()) {
		t = q.front(); q.pop();
		if (t->left == nullptr) { t->left = tmp; return; }
		else q.push(t->left);
		if (t->right == nullptr) { t->right = tmp; return; }
		else q.push(t->right); 
	}
}

void createTreeByLevel(treeNode*& T, int *a, int n) {
	queue<treeNode*> q;
	treeNode* tmp, *t;
	int i = 0;
	tmp = new treeNode;
	tmp->element = a[i++];
	tmp->left = nullptr;
	tmp->right = nullptr;
	if (T != nullptr) return;
	T = tmp;
	q.push(T);
	while(!q.empty() && i<n) {
		t = q.front(); q.pop();
		if (t->left == nullptr) {
			tmp = new treeNode;
			tmp->element = a[i++]; tmp->left = tmp->right = nullptr;
			t->left = tmp;
		}
		q.push(t->left);
		if (i >= n)break;
		if (t->right == nullptr) {
			tmp = new treeNode;
			tmp->element = a[i++]; tmp->left = tmp->right = nullptr;
			t->right = tmp;
		}
		q.push(t->right);
	}



}

//lab_ex2
void removeOdd(treeNode*& T){
	if(T == NULL)
		return;

	removeOdd(T->left);
	removeOdd(T->right);

	if(T->element%2!=0)
		T = remove(T,T->element);
}

treeNode* insertGeneralTree(treeNode* T, elementType val){
	if(T == NULL){
		treeNode * tmp = new treeNode;
		tmp->element = val;
		tmp->left = tmp->right = NULL;
		return tmp;
	}

	if(val <= rand()%(2*(T->element)))
		T->left = insertGeneralTree(T->left, val);
	else
		T->right = insertGeneralTree(T->right, val);

	return T;
}

//ex5
int nbLeaves(treeNode* T){
	if(T == NULL) return 0;
	if(T->left == NULL && T->right == NULL) return 1;	
	return nbLeaves(T->left)+nbLeaves(T->right);
}

int nbLeaves2(treeNode* T){
	int s;
	if(T == NULL) return 0;
	s = nbLeaves2(T->left)+nbLeaves2(T->right);
	if(T->left == NULL && T->right == NULL) return s+1;	
	return s;
}

void nbLeaves1(treeNode* T, int& n){
	if(T == NULL) return ;
	if(T->left == NULL && T->right == NULL) n++;	
	nbLeaves1(T->left,n);
	nbLeaves1(T->right,n);
}

//ex17
void copyBST(treeNode*& T2, treeNode* T1){
	if(T1 == NULL)
		return ;
	insert1(T2,T1->element);
	copyBST(T2,T1->left);
	copyBST(T2,T1->right);
}

//ex13
bool isSimilar(treeNode* T1, treeNode* T2){
	if(T1 == NULL && T2 == NULL) return true;	
	if((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL)) return false;
	if(T1->element != T2->element) return false;
	return isSimilar(T1->left,T2->left) && isSimilar(T1->right,T2->right);
}

//ex17
void splitTree(treeNode* T, treeNode*& T1, treeNode*& T2){
	if(T == NULL) return;
	if(T->element % 2 == 0) insert1(T1,T->element);
	else insert1(T2,T->element);
	splitTree(T->left,T1,T2);
	splitTree(T->right,T1,T2);
}
/*
//ex15
bool isBST(treeNode* T){//***** NOT CORRECT tricky CODE****
	if(T == NULL)
		return true;
	if(T->left == NULL && T->right == NULL)
		return true;

	if(isBST(T->left) && isBST(T->right) 
		&& (T->left==NULL || (T->left!=NULL && T->element > T->left->element))
		&& (T->right==NULL || T->right!=NULL && T->element < T->right->element))
		return true;
	else
		return false;
}
*/

/*the root node of a subtree is the min of the right and max of the left, 
for that when you go left the root becomes max when you go right the root 
becomes min*/
bool isBST(treeNode* T, elementType min, elementType max){
	if(T==NULL)
		return true;

	if(T->element >= min && T->element<=max 
		&& isBST(T->left,min,T->element)
		&& isBST(T->right,T->element,max)){
		return true;
	}else
		return false;
}

bool isBST2(treeNode*T,elementType min,elementType max){
	if(T==NULL) return true;
	if(T->element < min || T->element>max)	return false;
	return isBST2(T->left,min,T->element) && isBST2(T->right,T->element,max);
}

//ex6 (bottom up)
int treeHeight(treeNode* T){
	int left, right;
	if(T == NULL) return 0;

	left = treeHeight(T->left);
	right = treeHeight(T->right);
	if(left >= right) return left+1;
	else return right+1;
}

//-----//

//ex9
treeNode* createExprTree(char*expr){
	treeNode *T, *t1, *t2, *tmp;
	stack<treeNode*> s;

	T = initialize();
	for(int i = 0; expr[i] != '\0'; i++){
		if(expr[i]=='+' || expr[i]=='-' ||expr[i]=='*' ||expr[i]=='/' ||expr[i]=='%'){
			tmp = new treeNode;
			tmp->element = expr[i];
			tmp->left = tmp->right = NULL;
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			tmp->right = t1;
			tmp->left = t2;		
			s.push(tmp);
		}else{
			tmp = new treeNode;
			tmp->element = expr[i];
			tmp->left = tmp->right = NULL;
			s.push(tmp);
		}
	}
	T = s.top();
	s.pop();
	return T;
}
float evalExprTree(treeNode*T){
	if(T == NULL)
		return 0;
	switch(T->element){
		case '+': return evalExprTree(T->left)+evalExprTree(T->right);
		case '-': return evalExprTree(T->left)-evalExprTree(T->right);
		case '*': return evalExprTree(T->left)*evalExprTree(T->right);
		case '/': return evalExprTree(T->left)/evalExprTree(T->right);
		case '%': return int(evalExprTree(T->left))%int(evalExprTree(T->right));
		default: return T->element-'0';
	}
}

//ex10

void postfixIter(treeNode*T){
/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child 
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/
	treeNode *t;
	stack<treeNode*> s;

	if(T == NULL)
		return;

	if(T->right != NULL)
		s.push(T->right);
	s.push(T);
	T = T->left;
	while(!s.empty() || T!=NULL){

		while(T != NULL){
			if(T->right != NULL)
				s.push(T->right);
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		t = s.top();

		if(T->right != NULL && t == T->right){
			t = s.top();
			s.pop();
			s.push(T);
			T = T->right;
		}else{
			cout<<T->element<<" ";
			T = NULL;
		}
	}
	cout<<endl;
}

void infixIter(treeNode* T){
	stack<treeNode*> s;
	if(T == NULL)
		return;

	s.push(T);
	T = T->left;
	while(!s.empty() || T!=NULL){
		while(T != NULL){
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		cout<<T->element<<" ";
		T = T->right;
	}
	cout<<endl;
}
void prefixIter(treeNode* T){
	stack<treeNode*> s;

	if(T == NULL)
		return;

	s.push(T);
	cout<<T->element<<" ";
	T = T->left;
	while(!s.empty() || T!=NULL){
		while(T != NULL){			
			s.push(T);
			cout<<T->element<<" ";
			T = T->left;
		}
		T = s.top();
		s.pop();
		T = T->right;
	}
	cout<<endl;
}

//ex14
void displayByLevel(treeNode* T){
	queue<treeNode *> q;
	treeNode *t;
	if(T == NULL){
		cout<<"Tree is empty!"<<endl;
		return;
	}
	q.push(T);
	while(!q.empty()){
		t = q.front();
		q.pop();
		cout<<t->element<<" ";
		if(t->left!=NULL)
			q.push(t->left);
		if(t->right!=NULL)
			q.push(t->right);
	}
	cout<<endl;
}

void displayByLevel1(treeNode* T){
	queue<treeNode*> q;

	treeNode *t;
	int level, nbNodesByLevel, k;

	if(T == NULL){
		cout<<"Tree is empty!"<<endl;
		return;
	}

	q.push(T);
	level = 0;
	while(!q.empty()){
		nbNodesByLevel = q.size();
		level++;
		cout<<"level "<<level<<": ";
		k=0;
		while(k<nbNodesByLevel){
			t = q.front(); q.pop();
			cout<<t->element<<" ";
			if(t->left!=NULL)
				q.push(t->left);
			if(t->right!=NULL)
				q.push(t->right);
			k++;
		}
		cout<<endl;
	}
}

//ex5
int nbNodes(treeNode *T){
	if(T == NULL)
		return 0;
	return nbNodes(T->left)+nbNodes(T->right)+1;
}
void nbNodes1(treeNode *T, int& n){
	if(T == NULL)
		return;
	n++;
	nbNodes1(T->left,n);	
	nbNodes1(T->right,n);
}

int nbOddNodes(treeNode *T){
	if(T == NULL) return 0;
	if(T->element%2!=0) return nbOddNodes(T->left)+nbOddNodes(T->right)+1;
	else return nbOddNodes(T->left)+nbOddNodes(T->right);
}
int nbOddNodes2(treeNode *T){
	int s;
	if(T == NULL) return 0;
	s = nbOddNodes2(T->left)+nbOddNodes2(T->right);
	if(T->element%2!=0) return s+1;
	else return s;
}
void nbOddNodes1(treeNode *T, int& n){
	if(T == NULL) return;
	if(T->element%2!=0) n++;
	nbOddNodes1(T->left,n);	
	nbOddNodes1(T->right,n);
}

//ex12
int sumNodes(treeNode *T){
	if(T == NULL)
		return 0;
	return sumNodes(T->left)+sumNodes(T->right)+T->element;
}
void sumNodes1(treeNode *T, int& s){
	if(T == NULL)
		return;
	s+=T->element;
	sumNodes1(T->left,s);	
	sumNodes1(T->right,s);
}