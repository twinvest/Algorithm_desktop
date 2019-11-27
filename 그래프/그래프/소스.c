#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

//�������(�迭)�� �̿��� �׷��� ����
typedef struct GraphType
{
	int n; //��������
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; //�������
}GraphType;

void graph_init(GraphType*g)
{
	int r, c;
	g->n = 0; //�������� 0���� �����
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0; //���Ἲ�� 0���� �����.
}

void insert_vertex(GraphType*g, int v)
{
	if (((g->n)+1)>MAX_VERTICES) //���� ������ ������ +1�� �Ѱ��� �迭�� ������� ũ�� ����. ��,�迭�� �ε����� 49������ ����.
	{
		fprintf(stderr, "���������ʰ�����");
		return;
	}
	g->n++;
}

void insert_edge(GraphType*g, int start, int end)
{
	if ((start >= g->n) || (end >= g->n))
	{
		fprintf(stderr, "������ȣ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
