#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;

} TreeNode;

int get_node_count(TreeNode*node) //��� ���� ī���� �Լ�
{
	int count = 0; //���϶��� ���� 0���� �ʱ�ȭ�Ѱ�. �ؿ� if�� ����ȵǸ� �ٷ� 0��ȯ.
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

int get_height(TreeNode*node) // Ʈ�� ���� ��ȯ �Լ�
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}

void preorder(TreeNode*root)
{ 
	if (root) // �� ǥ���� ����!!! �̴� root�� ���� �ƴϸ� true�� ��ȯ.
	{
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode*root)
{
	if (root) // �� ǥ���� ����!!! �̴� root�� ���� �ƴϸ� true�� ��ȯ.
	{
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode*root)
{
	if (root) // �� ǥ���� ����!!! �̴� root�� ���� �ƴϸ� true�� ��ȯ.
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}


void main()
{
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10;
	n1->left = n2; // &�Ⱥ��� ����!!!
	n1->right = n3;
	
	n2->data = 20;
	n2->left = NULL; // &�Ⱥ��� ����!!!
	n2->right = NULL;

	n3->data = 30;
	n3->left = NULL; // &�Ⱥ��� ����!!!
	n3->right = NULL;

}