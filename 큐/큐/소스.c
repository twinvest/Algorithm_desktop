// LinkedQueue.c

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode
{
	element item;
	struct QueueNode*link;
}QueueNode;


typedef struct
{
	QueueNode*front;
	QueueNode*rear;
}QueueType;



void init(QueueType*q)
{
	q->front = q->rear = NULL; //�Ѵ� ���� �ֺ����.
}

int is_empty(QueueType*q)
{
	return q->rear == NULL;  //q�� front�� ���̾ ����. �Ѵ� ���̾ ����. full�Լ��� �ʿ����. �ֳ�. ��ũ��� ���������ϱ�.
}

void enqueue(QueueType*q, element item) //��°�� �ϱ��Ұ�....
{
	QueueNode*temp=(QueueNode*)malloc(sizeof(QueueNode));
	
	if (temp == NULL)
		printf("�޸� �Ҵ翡 �����߽��ϴ�...�Ф�");

	else 
	{
		temp->item = item;
		temp->link = NULL;

		if (is_empty(q))
		{
			q->rear = temp;
			q->front = temp;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType*q)
{
	QueueNode*temp;
	element item;

	if (is_empty(q))
	{
		printf("������ �����Ͱ� �����ϴ�.");
	}
	else
	{
		temp = q->front;
		item = temp->item;
		q->front = q->front->link;
		
		if (q->front == NULL) //�� �κ� ������.
			q->rear == NULL;
		free(temp);
		return item;
	}
}

element peek(QueueType*q)
{
	if (q->front == NULL) //q->rear==NULL�� ����. �ΰ��� �ε� ����. ����ٰ� empty�Լ��� ����ص� ����. if(is_empty(q))
		printf("����� �����Ͱ� �����ϴ�.");
	else
	{
		return q->front->item;
	}
}

void main()
{
	QueueType q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);

	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("peek()=%d\n", peek(&q));

}