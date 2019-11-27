//
//	라인 에디터 프로그램
//
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHAR_PER_LINE	1000
#define MAX_CHAR_PER_LINE 1000
#define MAX_NAME	256
void warning(char *);
void error(char *);

#define FALSE 0
#define TRUE 1

typedef struct {
	char a[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;
typedef struct {
	ListNode *head;     // 헤드 포인터
	int length;		// 노드의 개수
} ListType;

//
void insert_node(ListNode **phead, ListNode *p,
	ListNode *new_node)
{
	if (*phead == NULL) {	// 공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { // p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else {			 // p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}
//
void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}
// 리스트를 초기화한다.
void init(ListType *list)
{
	if (list == NULL) return;
	list->length = 0;
	list->head = NULL;
}
// 리스트안에서 pos 위치의 노드를 반환한다.
ListNode *get_node_at(ListType *list, int pos)
{
	int i;
	ListNode *tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i<pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}
// 리스트의 항목의 개수를 반환한다.
int get_length(ListType *list)
{
	return list->length;
}

// 주어진 위치에 데이터를 삽입한다.
void add(ListType *list, int position, element data)
{
	ListNode *p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode*node = (ListNode *)malloc(sizeof(ListNode));
		if (node == NULL) error("메모리 할당에러");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}
// 리스트의 끝에 데이터를 삽입한다.
void add_last(ListType *list, element data)
{
	add(list, get_length(list), data);
}
// 리스트의 끝에 데이터를 삽입한다.
void add_first(ListType *list, element data)
{
	add(list, 0, data);
}
//
int is_empty(ListType *list)
{
	if (list->head == NULL) return 1;
	else return 0;
}
// 주어진 위치의 데이터를 삭제한다.
void delete(ListType *list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode *p = get_node_at(list, pos - 1);
		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}
//
element get_entry(ListType *list, int pos)
{
	ListNode *p;
	if (pos >= list->length) error("위치 오류");
	p = get_node_at(list, pos);
	return p->data;
}
//
void clear(ListType *list)
{
	int i;
	for (i = 0; i<list->length; i++)
		delete(list, i);
}
// 버퍼의 내용을 출력한다. 
void display(ListType *buffer)
{
	int i;
	ListNode *tmp_node;
	tmp_node = buffer->head;

	printf("**************\n");
	for (i = 0; i<buffer->length; i++) {
	// ** 코드작성완료 ** //
		printf("%s", tmp_node->data.a);
		tmp_node = tmp_node->link;

	}
	printf("**************\n");
}
// 
void warning(char *message)
{
	fprintf(stderr, "%s\n", message);
}
//
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//
void help()
{
	printf("**************\n");
	printf("첫 시작행은 0행부터입니다 조교님들ㅎㅎ그다음 1행 2행 3행~~ n행\n연구실에서 피곤하실텐데 힘내세요!!\n");
	printf("i: 입력\n");
	printf("c: 바꾸기\n");
	printf("d: 삭제\n");
	printf("f: 검색\n");
	printf("r: 파일읽기\n");
	printf("w: 파일쓰기\n");
	printf("v: 거꾸로\n");
	printf("q: 종료\n");
	printf("**************\n");
}

// 디스크 파일로부터 데이터를 읽는다.
void read_file(ListType *buffer)
{
	char fname[MAX_NAME];
	FILE *fd;
	element p;

	if (!is_empty(buffer)) {
		clear(buffer);
	}
	init(buffer);

	// ** 코드작성완료 ** //
	printf("파일이름");
	scanf("%s", fname);
	if ((fd = fopen(fname, "r")) == NULL)
	{
		warning("파일을 열 수 없습니다.");
		return;
	}

	while (fgets(p.a, MAX_CHAR_PER_LINE, fd))
	{
		add_last(buffer, p);
	}

	fclose(fd);
	display(buffer);
}
// 버퍼에 있는 데이터를 디스크 파일에 쓴다.
void write_file(ListType *buffer)
{
	FILE *fd;
	char fname[MAX_NAME];
	element p;
	int i;

	// ** 코드작성완료 ** //
	printf("파일 이름: ");
	scanf("%s", fname);
	
	if ((fd = fopen(fname, "w")) == NULL)
	{
		warning("파일을 열 수 없습니다.\n");
		return;
	}
	
	for (i = 0; i < get_length(buffer); i++)
	{
		p = get_entry(buffer, i);
		fputs(p.a, fd);
	}
	fclose(fd);	
	display(buffer);
}
// 하나의 라인을 지운다
void delete_line(ListType *buffer)
{

	int position;

	if (is_empty(buffer))
		printf("지울 라인이 없습니다.\n");
	else
	{

		// ** 코드작성완료 ** //
		printf("지우고 싶은 라인번호를 입력하세요 : \n");
		scanf("%d", &position);
		delete(buffer, position);

	}

	display(buffer);
}
// 하나의 라인을 삽입한다.
void insert_line(ListType *buffer)
{
	int ch;
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;

	// ** 코드작성완료 ** //

	printf("입력행번호를 입력하세요 : \n");
	scanf("%d", &position);

	printf("내용을 입력하세요 : ");

	while (getchar() != '\n');
	

	//fflush(stdin); //인자로 전달된 스트림의 버퍼를 비우는 기능을 제공. 위에 scanf함수 엔터가 남아있음.
	fgets(line, MAX_CHAR_PER_LINE, stdin);
	strcpy(p.a, line);
	add(buffer, position, p);

	display(buffer);
}
//거꾸로 만들기
void reverse_line(ListType*buffer)
{

	char fname[MAX_NAME];
	FILE *fd;
	element s;

	if (!is_empty(buffer)) {
		clear(buffer);
	}
	init(buffer);

	printf("파일이름");
	scanf("%s", fname);
	if ((fd = fopen(fname, "r")) == NULL)
	{
		warning("파일을 열 수 없습니다.");
		return;
	}

	while (fgets(s.a, MAX_CHAR_PER_LINE, fd))
	{
		add_last(buffer, s);
	}
		
	ListNode *p, *q, *r;
	p = buffer->head;
	q = NULL;
	
	while (p != NULL)
	{
		/*r = p->link;
		p->link = q;
		q = p;
		p = r;*/

		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	
	/*int i;
	ListNode *tmp_node;
	tmp_node = q;

	printf("**************\n");
	for (i = 0; i<buffer->length; i++) {
		// ** 코드작성완료 ** //
		printf("%s\n", tmp_node->data.a);
		tmp_node = tmp_node->link;

	}
	printf("**************\n");*/

	buffer->head = q;
	display(buffer);
	fclose(fd);
}

void change_line(ListType*buffer)
{
	int ch;
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;
	
	if (is_empty(buffer))
		printf("변경할 라인이 없습니다.\n");
	else
	{

		// ** 코드작성완료 ** //
		printf("변경하고 싶은 라인번호를 입력하세요 : \n");
		scanf("%d", &position);
		delete(buffer, position);
		printf("변경할 내용을 입력하세요 : ");

		while (getchar() != '\n');


		//fflush(stdin); //인자로 전달된 스트림의 버퍼를 비우는 기능을 제공. 위에 scanf함수 엔터가 남아있음.
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		strcpy(p.a, line);
		add(buffer, position, p);

	}

	display(buffer);
}

void find_line(ListType*buffer)
{
	ListNode *tmp_node;
	int position = 0;
	tmp_node = buffer->head;
	char line[MAX_CHAR_PER_LINE];
	int flag = 0;

	printf("찾을 문자열 검색 : ");
	scanf("%s", &line);
	while (tmp_node != NULL) {
		position++;
		if (strstr(tmp_node->data.a, line)) {
			printf("찾을 문자열 의 행 번호는 : %d ", position-1);
			flag = position;
		}
		tmp_node = tmp_node->link;
	}
	if (!flag)
		printf("-1\n");

	
	
	/*ListNode*p;
	p = buffer->head;
	char line[MAX_CHAR_PER_LINE];
	
		
	printf("검색할 문자열을 입력해주세요 : \n");
	scanf("%s", line);
	while (getchar() != '\n');

	fgets(line, MAX_CHAR_PER_LINE, stdin);
	int a = 1; //strcmp 값 받으려고
	int i;

	ListNode *tmp_node;
	tmp_node = buffer->head;

	printf("**************\n");
	for (i = 0; i<buffer->length; i++) {
		int a = 1; //strcmp 값 받으려고
		a= strcmp(tmp_node->data.a, line);
		
		if (a == 0) 
		{
			printf("검색에 성공했습니다. 라인번호는 %d번 입니다.", i);
			break;
		}

		tmp_node = tmp_node->link;
	}

	if (a != 0)
	{
		printf("검색에 실패했습니다. -1");
	}*/
}


//
void do_command(ListType *buffer, char command)
{ // ** 코드작성완료 ** //
	switch (command)
	{

	case 'f':
		find_line(buffer);
		break;

	case 'c':
		change_line(buffer);
		break;
	case 'd':
		delete_line(buffer);
		break;

	case 'i':
		insert_line(buffer);
		break;
	
	case 'r':
		read_file(buffer);
		break;
	
	case 'w':
		write_file(buffer);
		break;
	case 'v':
		reverse_line(buffer);
	
	case 'q':
		break;
		

	}

}
// 라인 에디터 메인 프로그램
void main()
{
	char command;
	ListType buffer;

	init(&buffer);
	do {
		help();
		command = getchar();
		do_command(&buffer, command);
		fflush(stdin);
	} while (command != 'q');
}
