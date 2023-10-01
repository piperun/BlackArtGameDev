#include "stdafx.h"


void insert_tree(bintree **tree, int data);
void remove_data(bintree **tree, int value);
void print_tree(bintree *tree);
void morris(bintree *tree);
void recursive(bintree *tree);
bintree *search(bintree *tree, int value);

void generate_methods(tree_methods *p)
{
	tree_methods tm;
	tm.insert = insert_tree;
	tm.remove = remove_data;
	tm.print_tree = print_tree;
	tm.search = search;

	*p = tm;
}


bintree *search(bintree *tree, int value)
{
	if (tree->data == value || tree == NULL)
		return tree;
	if (tree->data < value)
		search(tree->right, value);
	if (tree->data > value)
		search(tree->left, value);
}


void insert_tree(bintree **tree, int data)
{
	if (*tree == NULL)
	{
		*tree = new bintree;
		(*tree)->data = data;
		(*tree)->left = (*tree)->right = NULL;
	}
	else if ((*tree)->data < data)
		insert_tree(&(*tree)->right, data);
	else if ((*tree)->data > data)
		insert_tree(&(*tree)->left, data);
}

void remove_data(bintree **tree, int value)
{
	if ((*tree)->data == value)
	{
		if ((*tree)->right != NULL)
			*tree = (*tree)->right;
		else if ((*tree)->left != NULL)
			*tree = (*tree)->left;
		else
		{
			free((*tree)->right);
			free((*tree)->left);
			*tree = NULL;
			
		}
	}

	else if ((*tree)->left != NULL && (*tree)->data > value)
	{
		remove_data(&(*tree)->left, value);
	}
	else if ((*tree)->right != NULL && (*tree)->data < value)
	{
		remove_data(&(*tree)->right, value);
	}
	
}


void print_tree(bintree *tree)
{	
	recursive(tree);	
}


// print functions
void morris(bintree *tree)
{
	bintree *current, *prev;
	current = tree;

	while (current != NULL)
	{
		if (current->left == NULL)
		{
			std::cout << current->data << "\n";
			current = current->right;
		}
		else
		{
			prev = current->left;
			while (prev->right != NULL && prev->right != current)
				prev = prev->right;

			if (prev->right == NULL)
			{
				prev->right = current;
				current = current->left;
			}
			else
			{
				prev->right = NULL;
				std::cout << current->data << "\n";
				current = current->right;
			}



		}
	}
}

void recursive(bintree *tree)
{
	if (tree == NULL)
		return;
	recursive(tree->left);
	std::cout << (tree)->data << "\n";
	recursive(tree->right);
}