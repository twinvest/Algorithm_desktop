// ���� Ž�� Ʈ���� ����� ���� ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <Windows.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// ������ ����
typedef struct {
	char word[MAX_WORD_SIZE];		// Ű�ʵ�
	char meaning[MAX_MEANING_SIZE];
} element;
// ����� ����
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

// ���� e1 > e2 -> -1 ��ȯ
// ���� e1 == e2 -> 0  ��ȯ 
// ���� e1 < e2 -> 1 ��ȯ
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode *p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s", p->key.word);
		display(p->right);
		printf(")");
	}
}
/*void file_read(TreeNode**root, FILE*fp2)//��Ʈ�� ���� ���� ���� ���ڷ� �ѱ�� �а� �μ�Ʈ �а� �μ�Ʈ~
{
	element temp;

	while (feof(fp2)==0)
	{
		fscanf(fp2, "%s", temp.word);
		fscanf(fp2, "%s", temp.meaning);
		insert_node(root, temp);
	}

	//element e;
	//fscanf(fp2, "%s", "(");
	//file_read(p->left, fp2);
	//fscanf(fp2, "%s", p->key.word);
	//insert_node(&p, e);
	//file_read(p->right, fp2);
	//fscanf(fp2, "%s", ")");
}*/


//Ʈ���� �ִ� �����͸� �ؽ�Ʈ���Ϸ� �����ϴ� �Լ�
int file_write(TreeNode *p, FILE*fp1)
{
	int num = 0;
	//fp1 = fp1;
	/*int num;
	printf("������ ����� ���ÿ�.\n");
	printf("1. ������ȸ ����.\n");
	printf("2. ������ȸ ����.\n");
	printf("3. ������ȸ ����.\n��ȣ�Է� :");
	scanf("%d", &num);*/
	

	
		if (p != NULL) 
		{
			//fprintf(fp1, "%s", "(");
			file_write(p->left, fp1);
			fprintf(fp1, "%s\n", p->key.word);
			fprintf(fp1, "%s\n", p->key.meaning);
			file_write(p->right, fp1);
			//fprintf(fp1, "%s", ")");
		}
		return 1;
	
	/*else if (num == 2) //����
	{
		if (p != NULL) {
			printf("(");
			display(p->left);
			printf("%s", p->key.word);
			display(p->right);
			printf(")");
		}
	}

	else if (num == 3)//����
	{
		if (p != NULL) {
			printf("(");
			display(p->left);
			printf("%s", p->key.word);
			display(p->right);
			printf(")");
		}

	}*/
}



// ���� Ž�� Ʈ�� Ž�� �Լ�
TreeNode *search(TreeNode *root, element key)
{
	TreeNode *p = root;
	while (p != NULL) {
		switch (compare(key, p->key))
		{
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
	}
	return p; 	// Ž���� �������� ��� NULL ��ȯ
}
// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
void insert_node(TreeNode **root, element key)
{
	TreeNode *p, *t; // p�� �θ� ���, p�� �ڽ� ��� 
	TreeNode *n;	 // n�� ���ο� ���

	t = *root;
	p = NULL;
	// Ž���� ���� ���� 
	while (t != NULL) {
		if (compare(key, t->key) == 0) return;
		p = t;
		if (compare(key, t->key)<0) t = t->left;
		else t = t->right;
	}
	// item�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;
	// �θ� ���� ��ũ ����
	if (p != NULL)
	{
		if (compare(key, p->key) < 0)
			p->left = n;
		else
			p->right = n;
	}
	else *root = n;
}
// ���� �Լ�
void delete_node(TreeNode **root, element key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(key, t->key)<0) ? t->left : t->right;
	}
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}
	// �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// �θ��尡 ������ ��Ʈ
			*root = NULL;
	}
	// �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// �θ��带 �ڽĳ��� ���� 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {		// �ΰ��� �ڽ��� ������ ���
				//������ ����Ʈ������ ã���ž�~~
		succ_p = t;
		succ = t->right;

		//������ ����Ʈ���� ���� ������ ��ü�� �� �ִ³���.
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;
		}
		//�ļ����� �θ�� �ڽ��� ����
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else//���� ù����. ��, while�� �ѹ��� �ȵ�����.
			succ_p->right = succ->right;

		//������ ������ succ�� ���� ��ü�� ����� t�� �������
		t->key = succ->key;
		//t�� ��ġ�����ؼ� succ����
		t = succ;
	}
	free(t);
}
//
void file_read(TreeNode**root, FILE*fp2)//��Ʈ�� ���� ���� ���� ���ڷ� �ѱ�� �а� �μ�Ʈ �а� �μ�Ʈ~
{
	element temp;

	while (feof(fp2) == 0)
	{
		fscanf(fp2, "%s", temp.word);
		fscanf(fp2, "%s", temp.meaning);
		insert_node(root, temp);
	}

	//element e;
	//fscanf(fp2, "%s", "(");
	//file_read(p->left, fp2);
	//fscanf(fp2, "%s", p->key.word);
	//insert_node(&p, e);
	//file_read(p->right, fp2);
	//fscanf(fp2, "%s", ")");
}



void help()
{
	printf("**************\n");
	printf("i: �Է�\n");
	printf("d: ����\n");
	printf("s: Ž��\n");
	printf("p: ���\n");
	printf("o : ���� �ҷ�����\n");
	printf("v : ���� �����ϱ�\n");
	printf("q: ����\n");
	printf("**************\n");
}
// ���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷� 
void main()
{
	//FILE*fp1 = fopen("twinvest.txt", "wt");

	char command;
	element e;
	TreeNode *root = NULL;
	TreeNode *tmp;

	do {
		help();
		command = getchar();
		fflush(stdin);

		switch (command)
		{
		case 'i':
			printf("�ܾ�:");
			//gets(e.word);
			scanf("%s", e.word);
			printf("�ǹ�:");
			scanf("%s", e.meaning);
			insert_node(&root, e);
			break;

		case 'd':
			printf("�ܾ�:");
			scanf("%s", e.word);
			delete_node(&root, e);
			break;

		case 'p':
			display(root);
			printf("\n");
			break;

		case 's':
			printf("�ܾ�:");
			scanf("%s", e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("�ǹ� : %s\n", e.meaning);
			break;
		
		case 'o':
			printf("������ �ҷ����� ���Դϴ�...\n");
			Sleep(1000);
			printf("3..\n");
			Sleep(1000);
			printf("2..\n");
			Sleep(1000);
			printf("1..\n");

			FILE*fp2 = fopen("twinvest.txt", "rt");
			file_read(&root, fp2);
			fclose(fp2);
			break;

		case 'v':
			printf("������ �����ϴ� ���Դϴ�...\n");
			Sleep(1000);
			printf("3..\n");
			Sleep(1000);
			printf("2..\n");
			Sleep(1000);
			printf("1..\n");

			
			FILE*fp1 = fopen("twinvest.txt", "wt");	
			int num = file_write(root, fp1);
			//fclose(fp1);
			if (num == 1)
				fclose(fp1);
			break;
		}

	} while (command != 'q');
}
