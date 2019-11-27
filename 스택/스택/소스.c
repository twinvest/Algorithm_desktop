#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode
{
	element item;
	struct StackNode*link;

}StackNode;

typedef struct 
{
	StackNode*top;
}LinkedStackType;

void init(LinkedStackType*s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType*s)
{
	return s->top == NULL;
	
}

void push(LinkedStackType*s, element item)
{
	StackNode*temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL)
		printf("할당 못함..ㄷㄷ");

	else
	{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}

}

element pop(LinkedStackType*s)
{
	element item;

	if (is_empty(s))
		printf("빼낼 데이터 없음");
	else
	{
		StackNode*temp = s->top;
		item = temp->item;
		s->top = s->top->link; //s->top=temp->link;  s->top->link
		free(temp);
		return item;
	}
}

element peek(LinkedStackType*s)
{
	if (is_empty(s))
		printf("빼낼 데이터 없음");
	else
		return s->top->item;
}

void main()
{
	LinkedStackType s;
	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));


}