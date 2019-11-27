#include <stdio.h>      //standardio ������� �ҷ���
#include <stdlib.h>     //stnadardlibrary ������� �ҷ���

typedef int element;// int�� element�� ������
typedef struct ListNode {
	element data;             //����Ÿ�κ�
	struct ListNode *link;    //��ũ�κ�
}ListNode;//����ü ���� 

ListNode * create_node(element data, ListNode * link);
void insert_node(ListNode ** phead, ListNode * p, ListNode * new_node);
void display(ListNode * head);
void remove_node(ListNode **phead, ListNode *p, ListNode *removed);
ListNode *concat(ListNode *head1, ListNode *head2);
ListNode *reverse(ListNode *head);
ListNode *search(ListNode *head, int x);

int main(void)
{
	ListNode * list1 = NULL;           //��������Ͷ�� �����ϸ��. �̸��� ��� ��� list1 NULL�� �ʱ�ȭ
	ListNode * list2 = NULL;           //��������Ͷ�� �����ϸ��. �̸��� ��� ��� list2 NULL�� �ʱ�ȭ
	ListNode *p;                       //����ü�� ����Ű�� ������ p����.

	insert_node(&list1, NULL, create_node(10, NULL));   //ù��° ���� ����������� �ּ�. �ι�° ���ڴ� ���̹Ƿ� ���� �տ� �����Ѵٴ� �ǹ�. ����° ���ڴ� ������ ����ε� create�Լ����� �̸� ó���Ѵ����� ��ȯ�Ǵ� ���� ���ڷ� �ѱ�. ���ο� ����� �����ͺκп��� 10 link�κп��� null�� �� ��������.
	insert_node(&list1, NULL, create_node(20, NULL));   //���� ��������. �����͸� 20���� �ٲ�.
	insert_node(&list1, NULL, create_node(30, NULL));   //���� ��������. �����͸� 30���� �ٲ�.
	insert_node(&list2, NULL, create_node(18, NULL));   //����Ʈ�� �ٲ�� �Ȱ���. �����ʹ� 18����.
	insert_node(&list2, NULL, create_node(23, NULL));   //����Ʈ�� �ٲ�� �Ȱ���. �����ʹ� 23����.
	insert_node(&list2, NULL, create_node(9, NULL));    //����Ʈ�� �ٲ�� �Ȱ���. �����ʹ� 9����.
	display(list1);                     //30 20 10  ������ �޸� �������� �ּҰ��� �ƴ� ������ ��ü�� �ѱ�� �ִµ� ������ ����� ������ ���⶧���̴�.
	display(list2);                     //9 23 18 

	remove_node(&list1, NULL, list1);         //���� �տ� �κ��� ����. ��, 30�� ����� ��尡 �����ɰ���.
	display(list1);                         // 20 10���.

	list1 = concat(list1, list2);            //��ġ���Լ�. 20 10 9 23 18�ɰ���.
	display(list1);                        //���� Ȯ�� ����.

	list1 = reverse(list1);               //�Ųٷ� �ٲ��ִ� ����� �Լ�. 18 23 9 10 20�� �ɰ���.
	display(list1);                        //���� Ȯ�ΰ���.

	p = search(list1, 20);                 //�˻��Լ� �˻��� ���� head�� �Ѱ��ְ� ����. �׸��� �˻��� ��带 ����Ű�� �ִ� �����͸� ��ȯ���ش�. �׸��� �װ� ����ü(���)�� ����Ű�� ������ p�� ����.
	printf("success explore : %d\n", p->data); //�� p�� ����Ű�� �κ��� ������ �κ��� ���.

	free(list1);    //lsit1 ��� ���ش�.
	free(list2);    //list2 ��� ���ش�.
	return 0;    //���α׷� ����.
}
ListNode * create_node(element data, ListNode * link) //��� �����Լ�
{
	ListNode * new_node;                             //������ new_node��
	new_node = (ListNode *)malloc(sizeof(ListNode));//����ü �Ҵ�����ŭ �Ҵ�.

	if (new_node == NULL)	                       //new_node�� null�̸� �Ҵ��� �ȵȰ�.
		printf("memory allocation error");         //�����޽���
	new_node->data = data;                         //new_node�� ����Ű�� �����ͺκ� �ʱ�ȭ
	new_node->link = link;                         //��ũ�κ� �ʱ�ȭ

	return(new_node);                               //�ʱ�ȭ�� new_node�� ��ȯ.
}

void insert_node(ListNode ** phead, ListNode *p, ListNode * new_node)     //�����Լ�. ���ڰ� ������������ ������ ��ȯ���� void�̱� ����. ��, insert_node�Լ� �ȿ��� ���������ͷ� ��尡 �����ǰ� ��ȯ�� ���⶧��. ���� ���������ͷ� �Ϸ��� ��ȯ�� �������.
{
	if (*phead == NULL) {                        //��尡 ���ΰ�� ��, ����ִ� ������.
		new_node->link = NULL;                   //new_node�� ��ũ�κ��� �η� �ٲ���.
		*phead = new_node;                          //���� ���� ����Ŵ
	}
	else if (p == NULL) {                       //p�� ���ΰ��. ù��°�� ����.
		new_node->link = *phead;                //���λ��ԵǴ� ����� ��ũ�� ���� �ص尡 ����Ű�� �ִ°ɷ� �ٲ��ְ�
		*phead = new_node;                      //��带 ���ԵǴ� ��带 ����Ű����.
	}
	else {
		new_node->link = p->link;               //�Ϲ����� ���. ���λ��ԵǴ� ����� ��ũ�� �� ���� p�� ����Ű�� �ִ� ��ũ�� ��带 ����Ű����.
		p->link = new_node;                     //�׸��� p�Ǹ�ũ�κ��� ���� ���ԵǴ� ��带 ����Ű����.
	}
}

void display(ListNode * head)           //����Լ� head�� ������ �޸� �׳� ������������ ������ ����� ��ȭ�� ���⶧��.
{
	ListNode *p = head;                 //������ p�� ��带 ����Ŵ.
	while (p != NULL) {                   //p�� ���� �ƴϸ�
		printf("%d->", p->data);        //���� p�� ����Ű�°��� ����Ÿ�� ����ϰ�
		p = p->link;                    //p�� ������ ��ĭ ����.
	}
	printf("\n");
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)// �����Լ�. ���� �����Լ��� ���������� ���ڷ� ���������͸� �޴µ� ������ ��ȯ���� ���� void. ��, ��ȯ���ִ°��� ���� ���������ͷ� ����� ������ �ٲ������.
{
	if (p == NULL)                //p�� ���϶� ��, �Ǿտ� ��Ҹ� �����Ҷ�.
		*phead = (*phead)->link;    //��带 ����� ��ũ�� ����Ű�� ������ �ٲ��ش�.
	else                            //������ ���.
		p->link = removed->link;    //������ ���(removed�� ����Ű�� ����.)�� ���� ��Ҹ� ����Ű�� p�� ��ũ�� ������ ���(removed)�� link�� ����Ű�� �ɷ� �ٲ���.

	free(removed); //�������δ� ������ �ǹ��ϰ�. ���������δ� removed�� ����Ű�� ��带 ������Ŵ.
}
ListNode *concat(ListNode *head1, ListNode *head2)//����Ʈ�� ��ġ�� �Լ�. ���ڷ� ������ ����Ʈ�� ����Ű�� �ִ� ��� �ΰ��� �޾ƿ´�.
{
	ListNode *p; //����ü�� ����Ű�� ������ p����.

	if (head1 == NULL)	return head2;          //���� head1�� �ƹ��͵� �Ȱ���Ű�� �ִٸ�(��, head1�� ����Ʈ�� ����ִٸ�) head2�� ��ȯ�Ѵ�.
	else if (head2 == NULL) 	return head1;      //�ݴ�� ���� head2�� �ƹ��͵� �Ȱ���Ű�� �ִٸ�(��, head2�� ����Ʈ�� ����ִٸ�) head1�� ��ȯ�Ѵ�.
	else {                                         //������ ���
		p = head1;                                //p�� head1�� ����Ű�� �� ����Ŵ ��, head1�� ����Ű�� �ִ� ����Ʈ�� �Ǿ� ��Ҹ� ����Ű�Ե�.
		while (p->link != NULL)                  //p�� ���簡��Ű�� �ִ� ����� link�� ���� �ƴ϶��
			p = p->link;                          //������ ��ĭ���� �̸� �ݺ�. ���������� �տ� ��� ��� �Լ��� ���ǰ� ���غ��� �� �̰͸� ��ĭ������ �����. �������� �����غ��� �翬�� �׷��߰���? �ֳ� ��ĭ �� ���� ����� �ȵǴϱ�.
		p->link = head2;                          //���� �ݺ����� ���� head1�� ����Ű�� ����Ʈ�� ������ ��ҿ� �������� ���̰� �׶� p�� link�� ���ϰ��̴�. �� p�� ����Ű�� �ִ� ����� link�κ��� head2�� ����Ű����. �׷� �ΰ��� �����.
		return head1;                             //head1�� ����Ű�� ����Ʈ�� head2�� ����Ű�� ����Ʈ�� ���� ���忡 ���� ������ �ư� head1�� ��ȯ���ָ� ����� ����Ʈ�� ��ȯ�ϴ°Ͱ� ����.
	}
}
ListNode *reverse(ListNode *head)           //�Ųٷ� �ٲ��ִ� �Լ�. �׸��� �Բ� ����.
{
	ListNode *p, *q, *r;                  //����ü�� ����Ű�� ������ ���� ���� p q r. (p�� ���弭�� q�� �߰�. r�� �ǵڸ� ����. �ٽ��� q�̴�.)
	p = head;                            //���弭�� p�� ��尡 ����Ű�� �� ����Ű�� ����.
	q = NULL;                            //q�� null. �������� r�� null�߰����൵ ��� ����.
	while (p != NULL) {                  //p�� ���� �ƴ϶�� ��, ó���� head�� ����Ű�Բ� p�� �ʱ�ȭ�����ϱ� ���� �ƴϰ� �� ��������.
		r = q;                         //r�� ���̵ǰ�.
		q = p;                         //q�� ��带 ����ų ���̸�
		p = p->link;                   //p�� ��ĭ �����Ѵ�.
		q->link = r;                   //�̶� q�� ����Ű�� ����� ��ũ�κ��� r�� ����Ű�� �ɷ� �ٲ��ִ� q�� link�κ��� null�� �ȴ�. �̸� ����ؼ� �ݺ��ϸ鼭 ��ĭ�� �����Ѵ�. �׸��� �ٷ� �̹����� �Ųٷ� �ٲ��ִ� ������ �ϴ� ������ �ǰ� ���� ������� ������ �� �� �ְԲ� ����� ������̴�.
	}

	return q;                      //�׸��� �������� p�� ������̰� q�� ������ ��Ҹ� ����Ű�� ���� ���̸� q�� head�� ���� ������ �Ѵٰ� ���� �ǰ� �̸� ��ȯ���ָ� �ǰڴ�.
}
ListNode *search(ListNode *head, int x)  //�˻��Լ�. ���� �˻��� �� ����.
{
	ListNode *p;                       //����ü�� ����Ű�� ������ �ϳ� ����.
	p = head;                          //p�� head�� ����Ű�� ���� ����Ű����.
	while (p != NULL) {                   //p�� ���̾ƴϸ�
		if (p->data == x)	return p;  //p�� ����Ű�� �����ͺκа� x�� ���ؼ� ������ 1�̾ if�� �����Ͽ� p�� ����Ű�� ����� �����͸� ��ȯ.
		p = p->link;            //���� ������ ��ĭ ����.
	}
	return p;                   //�˻��� ���� �������� null�� ��ȯ. ���� p=p->link�� ���� while���� ������ ���� �� ���̵Ǽ� ���� ���� ���� ��ȯ�ϰ� �ȴ�.
}
