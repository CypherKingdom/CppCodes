typedef int elementType;
struct treeNode{
	elementType element;
	treeNode *left;
	treeNode *right;
};

treeNode* initialize();
//bool isEmpty(treeNode*);
//Searching
treeNode* find(treeNode*,elementType);//lab_ex3.b
treeNode* findMin(treeNode*);
treeNode* findMax(treeNode*);

//Inserting
treeNode* insert(treeNode*,elementType);//Recursive //used in lab_ex1.1
void insert1(treeNode*&,elementType);//Iterative 

//Removing
treeNode* remove(treeNode*&,elementType);
void removeTree(treeNode*&);

//Displaying
void displayInorder(treeNode*);
void displayPreorder(treeNode*);
void displayPostorder(treeNode*);

//Sorting array
void inorderArray(treeNode* , int*, int&);
void BSTsorting(int*, int);
