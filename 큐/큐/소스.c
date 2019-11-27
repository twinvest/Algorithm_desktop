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
	q->front = q->rear = NULL; //둘다 널이 텅빈상태.
}

int is_empty(QueueType*q)
{
	return q->rear == NULL;  //q의 front가 널이어도 공백. 둘다 널이어도 공백. full함수는 필요없음. 왜냐. 링크드로 구현했으니까.
}

void enqueue(QueueType*q, element item) //통째로 암기할것....
{
	QueueNode*temp=(QueueNode*)malloc(sizeof(QueueNode));
	
	if (temp == NULL)
		printf("메모리 할당에 실패했습니다...ㅠㅠ");

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
		printf("삭제할 데이터가 없습니다.");
	}
	else
	{
		temp = q->front;
		item = temp->item;
		q->front = q->front->link;
		
		if (q->front == NULL) //이 부분 못적음.
			q->rear == NULL;
		free(temp);
		return item;
	}
}

element peek(QueueType*q)
{
	if (q->front == NULL) //q->rear==NULL도 노상관. 두개다 널도 노상관. 여기다가 empty함수를 사용해도 노상관. if(is_empty(q))
		printf("출력할 데이터가 없습니다.");
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