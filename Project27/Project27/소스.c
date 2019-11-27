#include <stdio.h>      //standardio 헤더파일 불러옴
#include <stdlib.h>     //stnadardlibrary 헤더파일 불러옴

typedef int element;// int를 element로 재정의
typedef struct ListNode {
	element data;             //데이타부분
	struct ListNode *link;    //링크부분
}ListNode;//구조체 정의 

ListNode * create_node(element data, ListNode * link);
void insert_node(ListNode ** phead, ListNode * p, ListNode * new_node);
void display(ListNode * head);
void remove_node(ListNode **phead, ListNode *p, ListNode *removed);
ListNode *concat(ListNode *head1, ListNode *head2);
ListNode *reverse(ListNode *head);
ListNode *search(ListNode *head, int x);

int main(void)
{
	ListNode * list1 = NULL;           //헤드포인터라고 생각하면됨. 이름은 헤드 대신 list1 NULL로 초기화
	ListNode * list2 = NULL;           //헤드포인터라고 생각하면됨. 이름은 헤드 대신 list2 NULL로 초기화
	ListNode *p;                       //구조체를 가리키는 포인터 p선언.

	insert_node(&list1, NULL, create_node(10, NULL));   //첫번째 인자 헤드포인터의 주소. 두번째 인자는 널이므로 제일 앞에 삽입한다는 의미. 세번째 인자는 삽입할 노드인데 create함수에서 이를 처리한다음에 반환되는 값을 인자로 넘김. 새로운 노드의 데이터부분에는 10 link부분에는 null이 들어가 있을것임.
	insert_node(&list1, NULL, create_node(20, NULL));   //위와 같은내용. 데이터만 20으로 바뀜.
	insert_node(&list1, NULL, create_node(30, NULL));   //위와 같은내용. 데이터만 30으로 바뀜.
	insert_node(&list2, NULL, create_node(18, NULL));   //리스트만 바뀌고 똑같음. 데이터는 18삽입.
	insert_node(&list2, NULL, create_node(23, NULL));   //리스트만 바뀌고 똑같음. 데이터는 23삽입.
	insert_node(&list2, NULL, create_node(9, NULL));    //리스트만 바뀌고 똑같음. 데이터는 9삽입.
	display(list1);                     //30 20 10  위에와 달리 포인터의 주소값이 아닌 포인터 자체를 넘기고 있는데 이유는 헤드의 수정이 없기때문이다.
	display(list2);                     //9 23 18 

	remove_node(&list1, NULL, list1);         //제잎 앞에 부분을 삭제. 즉, 30이 저장된 노드가 삭제될거임.
	display(list1);                         // 20 10출력.

	list1 = concat(list1, list2);            //합치기함수. 20 10 9 23 18될것임.
	display(list1);                        //실제 확인 가능.

	list1 = reverse(list1);               //거꾸로 바꿔주는 기능의 함수. 18 23 9 10 20이 될것임.
	display(list1);                        //실제 확인가능.

	p = search(list1, 20);                 //검색함수 검색할 수와 head를 넘겨주고 있음. 그리고 검색된 노드를 가리키고 있는 포인터를 반환해준다. 그리고 그걸 구조체(노드)를 가리키는 포인터 p에 저장.
	printf("success explore : %d\n", p->data); //그 p가 가리키는 부분의 데이터 부분을 출력.

	free(list1);    //lsit1 모두 없앤다.
	free(list2);    //list2 모두 없앤다.
	return 0;    //프로그램 종료.
}
ListNode * create_node(element data, ListNode * link) //노드 생성함수
{
	ListNode * new_node;                             //포인터 new_node에
	new_node = (ListNode *)malloc(sizeof(ListNode));//구조체 할당싸이즈만큼 할당.

	if (new_node == NULL)	                       //new_node가 null이면 할당이 안된것.
		printf("memory allocation error");         //에러메시지
	new_node->data = data;                         //new_node가 가리키는 데이터부분 초기화
	new_node->link = link;                         //링크부분 초기화

	return(new_node);                               //초기화된 new_node를 반환.
}

void insert_node(ListNode ** phead, ListNode *p, ListNode * new_node)     //삽입함수. 인자가 더블포인터인 이유는 반환형이 void이기 때문. 즉, insert_node함수 안에서 더블포인터로 헤드가 수정되고 반환이 없기때문. 만약 일중포인터로 하려면 반환을 해줘야함.
{
	if (*phead == NULL) {                        //헤드가 널인경우 즉, 비어있던 상태임.
		new_node->link = NULL;                   //new_node의 링크부분은 널로 바꿔줌.
		*phead = new_node;                          //헤드는 널을 가리킴
	}
	else if (p == NULL) {                       //p가 널인경우. 첫번째에 삽입.
		new_node->link = *phead;                //새로삽입되는 노드의 링크를 지금 해드가 가리키고 있는걸로 바꿔주고
		*phead = new_node;                      //헤드를 삽입되는 노드를 가리키게함.
	}
	else {
		new_node->link = p->link;               //일반적인 경우. 새로삽입되는 노드의 링크는 그 앞의 p가 가리키고 있는 링크의 노드를 가리키게함.
		p->link = new_node;                     //그리고 p의링크부분을 새로 삽입되는 노드를 가리키게함.
	}
}

void display(ListNode * head)           //출력함수 head가 위에와 달리 그냥 일중포인터인 이유는 헤드의 변화가 없기때문.
{
	ListNode *p = head;                 //포인터 p는 헤드를 가리킴.
	while (p != NULL) {                   //p가 널이 아니면
		printf("%d->", p->data);        //현재 p가 가리키는것의 데이타를 출력하고
		p = p->link;                    //p를 앞으로 한칸 전진.
	}
	printf("\n");
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)// 삭제함수. 위에 삽입함수와 마찬가지로 인자로 더블포인터를 받는데 이유는 반환형을 보면 void. 즉, 반환해주는것이 없어 더블포인터로 헤드의 변경을 바꿔줘야함.
{
	if (p == NULL)                //p가 널일때 즉, 맨앞에 요소를 삭제할때.
		*phead = (*phead)->link;    //헤드를 헤드의 링크가 가리키는 것으로 바꿔준다.
	else                            //보통의 경우.
		p->link = removed->link;    //삭제할 요소(removed가 가리키고 있음.)의 앞의 요소를 가리키는 p의 링크를 삭제할 요소(removed)의 link가 가리키는 걸로 바꿔줌.

	free(removed); //논리적으로는 삭제를 의미하고. 물리적으로는 removed가 가리키는 노드를 해제시킴.
}
ListNode *concat(ListNode *head1, ListNode *head2)//리스트를 합치는 함수. 인자로 각각의 리스트를 가리키고 있는 헤드 두개를 받아온다.
{
	ListNode *p; //구조체를 가리키는 포인터 p선언.

	if (head1 == NULL)	return head2;          //만약 head1이 아무것도 안가리키고 있다면(즉, head1의 리스트가 비어있다면) head2만 반환한다.
	else if (head2 == NULL) 	return head1;      //반대로 만약 head2가 아무것도 안가리키고 있다면(즉, head2의 리스트가 비어있다면) head1만 반환한다.
	else {                                         //보통의 경우
		p = head1;                                //p도 head1이 가리키는 걸 가리킴 즉, head1이 가리키고 있는 리스트의 맨앞 요소를 가리키게됨.
		while (p->link != NULL)                  //p가 현재가리키고 있는 요소의 link가 널이 아니라면
			p = p->link;                          //앞으로 한칸전진 이를 반복. 주의할점은 앞에 모든 모든 함수의 조건과 비교해봤을 때 이것만 한칸전에서 멈춘다. 논리적으로 생각해보면 당연히 그래야겠지? 왜냐 한칸 더 가서 벗어나면 안되니까.
		p->link = head2;                          //이제 반복문에 의해 head1이 가리키는 리스트의 마지막 요소에 도착했을 것이고 그때 p의 link는 널일것이다. 이 p가 가리키고 있는 노드의 link부분을 head2를 가리키게함. 그럼 두개가 연결됨.
		return head1;                             //head1이 가리키는 리스트와 head2가 가리키는 리스트가 위에 문장에 의해 연결이 됐고 head1을 반환해주면 연결된 리스트를 반환하는것과 같음.
	}
}
ListNode *reverse(ListNode *head)           //거꾸로 바꿔주는 함수. 그림과 함께 설명.
{
	ListNode *p, *q, *r;                  //구조체를 가리키는 포인터 세개 선언 p q r. (p가 앞장서고 q는 중간. r은 맨뒤를 따라감. 핵심은 q이다.)
	p = head;                            //앞장서는 p는 헤드가 가리키는 걸 가리키게 만듦.
	q = NULL;                            //q는 null. 보기좋게 r도 null추가해줘도 상관 없음.
	while (p != NULL) {                  //p가 널이 아니라면 즉, 처음에 head를 가리키게끔 p를 초기화했으니까 널이 아니고 이 문장실행됨.
		r = q;                         //r은 널이되고.
		q = p;                         //q는 헤드를 가리킬 것이며
		p = p->link;                   //p는 한칸 전진한다.
		q->link = r;                   //이때 q가 가리키는 요소의 링크부분을 r이 가리키는 걸로 바꿔주니 q의 link부분은 null이 된다. 이를 계속해서 반복하면서 한칸씩 전진한다. 그리고 바로 이문장이 거꾸로 바꿔주는 역할을 하는 문장이 되고 위에 문장들이 전진을 할 수 있게끔 만드는 문장들이다.
	}

	return q;                      //그리고 마지막에 p는 벗어날것이고 q가 마지막 요소를 가리키고 있을 것이며 q가 head와 같은 역할을 한다고 보면 되고 이를 반환해주면 되겠다.
}
ListNode *search(ListNode *head, int x)  //검색함수. 헤드와 검색할 값 전달.
{
	ListNode *p;                       //구조체를 가리키는 포인터 하나 선언.
	p = head;                          //p가 head를 가리키는 것을 가리키게함.
	while (p != NULL) {                   //p가 널이아니면
		if (p->data == x)	return p;  //p가 가리키는 데이터부분과 x를 비교해서 같으면 1이어서 if문 실행하여 p가 가리키는 노드의 포인터를 반환.
		p = p->link;            //같지 않으면 한칸 전진.
	}
	return p;                   //검색에 실패 했을때는 null을 반환. 위에 p=p->link에 의해 while문의 끝까지 갔을 때 널이되서 들어가지 못해 널을 반환하게 된다.
}
