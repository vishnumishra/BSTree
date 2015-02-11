#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"

BSTree createBSTree(void){
	BSTree *tree = malloc(sizeof(Node));
	tree->root = NULL;
	return *tree;
};
Node* createNode(int data){
	Node* new_node = malloc(sizeof(Node));
	new_node->left = NULL;
	new_node->data = data;
	new_node->right = NULL;
	return new_node;
};

Node* intsertIntoNode(Node* root,int data){
	if(root == NULL)return createNode(data);
	if(data < root->data){
		root->left = intsertIntoNode(root->left, data);
	}
	else if(data >= root->data){
		root->right = intsertIntoNode(root->right, data);
	}
	return root;
};

int insert(BSTree *tree, int data){
	Node* node;
	if(tree->root==NULL){
		tree->root = createNode(data);
	}else
	node = intsertIntoNode(tree->root,data);
	return 1;
}
Node* findInNode(Node* root,int data){
	if(!root) return NULL;
	if(root->data == data )return root;
	if(data < root->data){
		return findInNode(root->left,data); 
	}
	if (data >= root->data){
		return findInNode(root->right,data); 
	}
	return NULL;
};

Node * find(BSTree t, int data){
	return findInNode(t.root,data);
};



