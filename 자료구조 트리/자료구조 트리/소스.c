#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;

} TreeNode;

int get_node_count(TreeNode*node) //노드 개수 카운팅 함수
{
	int count = 0; //널일때를 위해 0으로 초기화한거. 밑에 if문 실행안되면 바로 0반환.
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

int get_height(TreeNode*node) // 트리 높이 반환 함수
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
	if (root) // 이 표현에 주의!!! 이는 root가 널이 아니면 true를 반환.
	{
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode*root)
{
	if (root) // 이 표현에 주의!!! 이는 root가 널이 아니면 true를 반환.
	{
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode*root)
{
	if (root) // 이 표현에 주의!!! 이는 root가 널이 아니면 true를 반환.
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
	n1->left = n2; // &안붙임 주의!!!
	n1->right = n3;
	
	n2->data = 20;
	n2->left = NULL; // &안붙임 주의!!!
	n2->right = NULL;

	n3->data = 30;
	n3->left = NULL; // &안붙임 주의!!!
	n3->right = NULL;

}