#include "BSTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "expr_assert.h"

void test_createBSTree_create_a_empty_bstree_0(){
	BSTree tree;
	tree = createBSTree();
	assert(tree.root==0);
};
void test_insert_insert_the_given_element_into_the_list(){
	int result;
	BSTree tree = createBSTree();
	result = insert(&tree,6);
	assertEqual(result,1);
};

void test_createNode_create_node_with_given(){
	Node* n = createNode(10);
	assertEqual(n->data, 10);
	assert(n->left==NULL);
	assert(n->right==NULL);
};

void test_createNode_create_node_with_given_1(){
	Node* n = createNode(-10);
	assertEqual(n->data, -10);
	assert(n->left==NULL);
	assert(n->right==NULL);
};

void test_insertInto_node_insert_data_into_node(){
	Node *n=createNode(9),*n1 = createNode(10);
	BSTree t =  createBSTree();
	t.root = n1;
	t.root->left = n;
	intsertIntoNode(t.root,11);
	intsertIntoNode(t.root,12);
	assertEqual(n1->right->data,11);
	assertEqual(n1->right->right->data,12);
};

void test_insertInto_node_insert_data_into_node_2(){
	Node *n=createNode(9),*n1 = createNode(10);
	BSTree t =  createBSTree();
	t.root = n1;
	t.root->left = n;
	intsertIntoNode(t.root,6);
	intsertIntoNode(t.root,7);
	assertEqual(n1->left->left->data,6);
	assertEqual(n1->left->left->right->data,7);
};

void test_insertInto_node_insert_data_into_node_3(){
	Node *n=createNode(9),*n1 = createNode(10);
	BSTree t =  createBSTree();
	t.root = n1;
	t.root->left = n;
	intsertIntoNode(t.root,6);
	intsertIntoNode(t.root,8);
	intsertIntoNode(t.root,7);
	assertEqual(t.root->left->left->right->left->data,7);
};

void test_insert_insert_the_data_to_the_tree_1(){
	BSTree *tree = malloc(sizeof(BSTree));
	*tree = createBSTree();
	insert(tree,10);
	assertEqual(tree->root->data,10);
	free(tree);
};
void test_insert_insert_the_data_to_the_tree_2(){
	BSTree *tree = malloc(sizeof(BSTree));
	*tree = createBSTree();
	insert(tree,10);insert(tree,5);insert(tree,15);
	assertEqual(tree->root->data,10);
	assertEqual(tree->root->left->data,5);
	assertEqual(tree->root->right->data,15);
	free(tree);
};

void test_insert_insert_the_data_to_the_tree_3(){
	BSTree *tree = malloc(sizeof(BSTree));
	*tree = createBSTree();
	insert(tree,10);insert(tree,5);insert(tree,15);insert(tree,7);
	assertEqual(tree->root->left->right->data,7);
	free(tree);
};

void test_insert_insert_the_data_to_the_tree_4(){
	BSTree *tree = malloc(sizeof(BSTree));
	*tree = createBSTree();
	insert(tree,10);insert(tree,9);insert(tree,8);insert(tree,7),insert(tree,6);
	assertEqual(tree->root->left->left->left->left->data,6);
	free(tree);
};

void test_find_find_the_data_in_a_tree_1(){
	BSTree *tree = malloc(sizeof(BSTree));
	Node *n;
	*tree = createBSTree();
	insert(tree,11);insert(tree,5);insert(tree,15);insert(tree,7);
	n = find(*tree,7);
	assertEqual(n->data,7);
	assertEqual((int)n->left,0);
	assertEqual((int)n->right,0);
	free(tree);
}
void test_find_find_the_data_in_a_tree_2(){
	BSTree *tree = malloc(sizeof(BSTree));
	Node *n;
	*tree = createBSTree();
	insert(tree,11);insert(tree,5);insert(tree,15);insert(tree,7);
	n = find(*tree,10);
	assert(n==0);
	free(tree);
}

void test_find_find_the_data_in_a_tree_3(){
	BSTree *tree = malloc(sizeof(BSTree));
	Node *n;
	*tree = createBSTree();
	insert(tree,11);insert(tree,5);insert(tree,20);insert(tree,15);insert(tree,7);
	n = find(*tree,20);
	assert(n->data == 20);
	assert(n->left->data == 15);
	assert(n->right == 0);
	free(tree);
}



