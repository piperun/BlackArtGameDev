#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

typedef struct node {
	int data;
	struct node *left, *right;
}bintree;

typedef struct methods {
	void(*insert)(bintree **tree, int data);
	void(*remove)(bintree **tree, int value);
	bintree *(*search)(bintree *tree, int value);
	void(*print_tree)(bintree *tree);
}tree_methods;

void generate_methods(tree_methods *bintree);
#endif