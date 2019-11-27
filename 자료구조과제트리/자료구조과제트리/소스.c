// 이진 탐색 트리를 사용한 영어 사전

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <Windows.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];		// 키필드
	char meaning[MAX_MEANING_SIZE];
} element;
// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

// 만약 e1 > e2 -> -1 반환
// 만약 e1 == e2 -> 0  반환 
// 만약 e1 < e2 -> 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// 이진 탐색 트리 출력 함수
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
/*void file_read(TreeNode**root, FILE*fp2)//루트와 파일 읽을 파일 인자로 넘기고 읽고 인설트 읽고 인설트~
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


//트리에 있는 데이터를 텍스트파일로 저장하는 함수
int file_write(TreeNode *p, FILE*fp1)
{
	int num = 0;
	//fp1 = fp1;
	/*int num;
	printf("저장할 방식을 고르시오.\n");
	printf("1. 전위순회 저장.\n");
	printf("2. 중위순회 저장.\n");
	printf("3. 후위순회 저장.\n번호입력 :");
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
	
	/*else if (num == 2) //중위
	{
		if (p != NULL) {
			printf("(");
			display(p->left);
			printf("%s", p->key.word);
			display(p->right);
			printf(")");
		}
	}

	else if (num == 3)//후위
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



// 이진 탐색 트리 탐색 함수
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
	return p; 	// 탐색에 실패했을 경우 NULL 반환
}
// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
void insert_node(TreeNode **root, element key)
{
	TreeNode *p, *t; // p는 부모 노드, p는 자식 노드 
	TreeNode *n;	 // n은 새로운 노드

	t = *root;
	p = NULL;
	// 탐색을 먼저 수행 
	while (t != NULL) {
		if (compare(key, t->key) == 0) return;
		p = t;
		if (compare(key, t->key)<0) t = t->left;
		else t = t->right;
	}
	// item이 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
	if (p != NULL)
	{
		if (compare(key, p->key) < 0)
			p->left = n;
		else
			p->right = n;
	}
	else *root = n;
}
// 삭제 함수
void delete_node(TreeNode **root, element key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(key, t->key)<0) ? t->left : t->right;
	}
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}
	// 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// 부모노드가 없으면 루트
			*root = NULL;
	}
	// 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// 부모노드를 자식노드와 연결 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {		// 두개의 자식을 가지는 경우
				//오른쪽 서브트리에서 찾을거야~~
		succ_p = t;
		succ = t->right;

		//오른쪽 서브트리의 제일 왼쪽이 대체할 수 있는놈임.
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;
		}
		//후속자의 부모와 자식을 연결
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else//제일 첫순간. 즉, while을 한번도 안돈상태.
			succ_p->right = succ->right;

		//연결이 끊어진 succ에 값을 대체할 노드인 t에 집어넣음
		t->key = succ->key;
		//t의 위치변경해서 succ삭제
		t = succ;
	}
	free(t);
}
//
void file_read(TreeNode**root, FILE*fp2)//루트와 파일 읽을 파일 인자로 넘기고 읽고 인설트 읽고 인설트~
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
	printf("i: 입력\n");
	printf("d: 삭제\n");
	printf("s: 탐색\n");
	printf("p: 출력\n");
	printf("o : 파일 불러오기\n");
	printf("v : 파일 저장하기\n");
	printf("q: 종료\n");
	printf("**************\n");
}
// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
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
			printf("단어:");
			//gets(e.word);
			scanf("%s", e.word);
			printf("의미:");
			scanf("%s", e.meaning);
			insert_node(&root, e);
			break;

		case 'd':
			printf("단어:");
			scanf("%s", e.word);
			delete_node(&root, e);
			break;

		case 'p':
			display(root);
			printf("\n");
			break;

		case 's':
			printf("단어:");
			scanf("%s", e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미 : %s\n", e.meaning);
			break;
		
		case 'o':
			printf("파일을 불러오는 중입니다...\n");
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
			printf("파일을 저장하는 중입니다...\n");
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
