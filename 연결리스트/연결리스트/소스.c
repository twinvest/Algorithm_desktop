#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode*link;
}ListNode;

void insert_node(ListNode**phead, ListNode*p, ListNode*new_node)
{
	if (*phead == NULL)
	{
		new_node->link = NULL; //이거 못적음.
		*phead = new_node;
	}
	else
	{
		if (p == NULL)
		{
			new_node ->link = *phead;
			*phead = new_node;
		}

		else
		{
			new_node->link = p->link;
			p->link = new_node;
		}
	}
}

/*element remove_node(ListNode**phead, ListNode*p, ListNode*removed)
{
	element item;

	if (p == NULL) //맨앞의 데이터 삭제.
	{
		removed = *phead;
		item = removed->data;
		*phead = removed->link;
		free(removed);
	}

	else
	{
		item = removed->data;
		p->link = removed->link;
		p = p->link;
		free(removed);

	}

	return item;
}*/

void remove_node(ListNode**phead, ListNode*p, ListNode*removed)
{
	if (p == NULL)
	{
		*phead = (*phead)->link;
	}
	else
	{
		p->link = removed->link;
	}
	free(removed);

}

void display(ListNode*head)
{
	ListNode*p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
}

ListNode* search(ListNode*head, int x)
{
	ListNode*p = head;

	while (p != NULL)
	{
		if (p->data == x)
			return p;
		p = p->link;
	}
	return p; //탐색 실패할 경우 NULL반환.
}

ListNode* concat(ListNode*head1, ListNode*head2)
{
	ListNode*p;
	
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	else
	{
		p = head1;
		while (p->link != NULL)
			p = p->link;
		
		p->link = head2;

		return head1;
	}
}

ListNode* reverse(ListNode*head)
{
	ListNode*p;
	ListNode*q;
	ListNode*r;

	p = head;
	q = NULL;
	r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

ListNode* create_node(element data, ListNode*link)
{
	ListNode*new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if(new_node ==NULL)
		printf("메모리 할당 안됨ㅠㅠ");

	new_node->data = data;
	new_node->link = link;
	return new_node;

}

main()
{
	ListNode*list1 = NULL;
	ListNode*list2 = NULL;
	ListNode*p;

	//list1 = 30->20->10
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));

	remove_node(&list1, NULL, list1);
	display(list1);
}