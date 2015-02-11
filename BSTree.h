typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

typedef struct tree{
	struct node * root;
}BSTree;

BSTree createBSTree(void);
Node* createNode(int data);

int insert(BSTree *, int);
Node* intsertIntoNode(Node* root,int data);
Node * find(BSTree, int);



