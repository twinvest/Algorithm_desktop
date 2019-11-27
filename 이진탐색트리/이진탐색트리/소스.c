#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode *left, *right;

} TreeNode;

TreeNode* search(TreeNode*node, int key)
{
	if (node == NULL) return NULL;
	else if (node->key < key)
		return search(node->right, key);
	else
		return search(node->left, key);
}

void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t;
	TreeNode *n;
	t = *root;
	p = NULL;
	
	while (t != NULL)
	{
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else              t = t->right;
	}

	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;
	if (p != NULL)
	{
		if (key < p->key)
			p->left = n;
		else p->right = n;
	}
	else *root = n;
}