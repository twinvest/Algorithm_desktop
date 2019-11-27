//쓰레드 이진트리는 리컬젼을 쓰지 않고 구현하는 트리임. 
//이진트리의 구성상 단말노드의 링크는 전부 널임. 이 단말노드 링크에 다음방문할 노드의 주소를 심음.
//중위순회로 구현함.
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode //구조체 다 똑같은데 is_thread 변수 하나 추가된거임.
{
	int data;
	struct TreeNode *left, *right;
	int is_thread;//단말 노드와 비단말 노드를 구분할 수 있음. 오른쪽 링크가 스레드이면 TRUE
}TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 }; //중위 순회에서 제일 마지막 순서임. 그래서 0
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *exp = &n7;

//후속자 찾는 함수와 쓰레드 인오더 함수 시험각.
TreeNode* find_successor(TreeNode*p)
{
	TreeNode *q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;

	while (q->left != NULL) //특히 이 와일문 시험각
		q = q->left;
	return q;
}

void thread_inorder(TreeNode*t)
{
	TreeNode*q;
	q = t;
	while (q->left != NULL) q = q->left; //특히 이 와일문 시험각
	do
	{
		printf("%c", q->data);
		q = find_successor(q);
	} while (q != NULL);
}

main()
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	thread_inorder(exp);
}